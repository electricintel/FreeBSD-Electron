--- ui/views/style/platform_style.cc.orig	2019-09-10 11:14:40 UTC
+++ ui/views/style/platform_style.cc
@@ -17,7 +17,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define DESKTOP_LINUX
 #endif
 
