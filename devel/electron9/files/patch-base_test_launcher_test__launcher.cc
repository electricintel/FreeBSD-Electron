--- base/test/launcher/test_launcher.cc.orig	2020-05-26 08:03:15 UTC
+++ base/test/launcher/test_launcher.cc
@@ -55,6 +55,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
@@ -551,7 +552,7 @@ ChildProcessResults DoLaunchChildTestProcess(
 #if !defined(OS_FUCHSIA)
   options.new_process_group = true;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   options.kill_on_parent_death = true;
 #endif
 
