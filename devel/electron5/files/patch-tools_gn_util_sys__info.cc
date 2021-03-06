--- tools/gn/util/sys_info.cc.orig	2019-04-30 22:29:37 UTC
+++ tools/gn/util/sys_info.cc
@@ -28,6 +28,8 @@ std::string OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
