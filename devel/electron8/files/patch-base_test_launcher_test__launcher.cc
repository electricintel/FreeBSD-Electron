--- base/test/launcher/test_launcher.cc.orig	2020-03-03 07:02:14 UTC
+++ base/test/launcher/test_launcher.cc
@@ -54,6 +54,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 
 #if defined(OS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
