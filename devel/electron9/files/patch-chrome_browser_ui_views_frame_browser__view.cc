--- chrome/browser/ui/views/frame/browser_view.cc.orig	2020-05-26 08:03:19 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -1716,7 +1716,7 @@ void BrowserView::UserChangedTheme(BrowserThemeChangeT
   const bool should_use_native_frame = frame_->ShouldUseNativeFrame();
 
   bool must_regenerate_frame;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // GTK and user theme changes can both change frame buttons, so the frame
   // always needs to be regenerated on Linux.
   must_regenerate_frame = true;
