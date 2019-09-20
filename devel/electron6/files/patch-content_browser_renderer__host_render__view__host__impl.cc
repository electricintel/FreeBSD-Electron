--- content/browser/renderer_host/render_view_host_impl.cc.orig	2019-09-10 11:14:02 UTC
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -163,7 +163,7 @@ void GetPlatformSpecificPrefs(blink::mojom::RendererPr
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   prefs->system_font_family_name = gfx::Font().GetFontName();
 #endif
 }
