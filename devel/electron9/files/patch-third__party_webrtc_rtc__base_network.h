--- third_party/webrtc/rtc_base/network.h.orig	2020-05-26 08:04:34 UTC
+++ third_party/webrtc/rtc_base/network.h
@@ -26,6 +26,10 @@
 #include "rtc_base/system/rtc_export.h"
 #include "rtc_base/third_party/sigslot/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
