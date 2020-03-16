--- content/browser/child_process_launcher_helper_linux.cc.orig	2020-03-12 05:46:52 UTC
+++ content/browser/child_process_launcher_helper_linux.cc
@@ -17,7 +17,9 @@
 #include "content/public/common/sandboxed_process_launcher_delegate.h"
 #include "services/service_manager/sandbox/linux/sandbox_linux.h"
 #include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
+#if !defined(OS_BSD)
 #include "services/service_manager/zygote/common/zygote_handle.h"
+#endif
 #include "services/service_manager/zygote/host/zygote_communication_linux.h"
 #include "services/service_manager/zygote/host/zygote_host_impl_linux.h"
 
@@ -54,6 +56,7 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
     options->fds_to_remap.push_back(
         std::make_pair(sandbox_fd, service_manager::GetSandboxFD()));
 
+#if !defined(OS_BSD)
     // (For Electron), if we're launching without zygote, that means we're
     // launching an unsandboxed process (since all sandboxed processes are
     // forked from the zygote). Relax the allow_new_privs option to permit
@@ -65,6 +68,7 @@ bool ChildProcessLauncherHelper::BeforeLaunchOnLaunche
     if (!zygote_handle) {
       options->allow_new_privs = true;
     }
+#endif
   }
 
   options->environment = delegate_->GetEnvironment();
@@ -80,6 +84,7 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
     int* launch_result) {
   *is_synchronous_launch = true;
 
+#if !defined(OS_BSD)
   service_manager::ZygoteHandle zygote_handle =
       base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kNoZygote)
           ? nullptr
@@ -93,7 +98,6 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
         GetProcessType());
     *launch_result = LAUNCH_RESULT_SUCCESS;
 
-#if !defined(OS_OPENBSD)
     if (handle) {
       // This is just a starting score for a renderer or extension (the
       // only types of processes that will be started this way).  It will
@@ -104,13 +108,13 @@ ChildProcessLauncherHelper::LaunchProcessOnLauncherThr
       service_manager::ZygoteHostImpl::GetInstance()->AdjustRendererOOMScore(
           handle, kLowestRendererOomScore);
     }
-#endif
 
     Process process;
     process.process = base::Process(handle);
     process.zygote = zygote_handle;
     return process;
   }
+#endif
 
   Process process;
   process.process = base::LaunchProcess(*command_line(), options);
@@ -128,10 +132,14 @@ ChildProcessTerminationInfo ChildProcessLauncherHelper
     const ChildProcessLauncherHelper::Process& process,
     bool known_dead) {
   ChildProcessTerminationInfo info;
+#if !defined(OS_BSD)
   if (process.zygote) {
     info.status = process.zygote->GetTerminationStatus(
         process.process.Handle(), known_dead, &info.exit_code);
   } else if (known_dead) {
+#else
+  if (known_dead) {
+#endif
     info.status = base::GetKnownDeadTerminationStatus(process.process.Handle(),
                                                       &info.exit_code);
   } else {
@@ -155,13 +163,17 @@ void ChildProcessLauncherHelper::ForceNormalProcessTer
   DCHECK(CurrentlyOnProcessLauncherTaskRunner());
   process.process.Terminate(service_manager::RESULT_CODE_NORMAL_EXIT, false);
   // On POSIX, we must additionally reap the child.
+#if !defined(OS_BSD)
   if (process.zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
     process.zygote->EnsureProcessTerminated(process.process.Handle());
   } else {
+#endif
     base::EnsureProcessTerminated(std::move(process.process));
+#if !defined(OS_BSD)
   }
+#endif
 }
 
 void ChildProcessLauncherHelper::SetProcessPriorityOnLauncherThread(