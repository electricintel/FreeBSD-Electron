--- gpu/command_buffer/tests/gl_copy_texture_CHROMIUM_unittest.cc.orig	2019-09-10 11:14:06 UTC
+++ gpu/command_buffer/tests/gl_copy_texture_CHROMIUM_unittest.cc
@@ -593,7 +593,7 @@ class GLCopyTextureCHROMIUMES3Test : public GLCopyText
 
   bool ShouldSkipNorm16() const {
     DCHECK(!ShouldSkipTest());
-#if (defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)) && \
+#if (defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)) && \
     (defined(ARCH_CPU_X86) || defined(ARCH_CPU_X86_64))
     // Make sure it's tested; it is safe to assume that the flag is always true
     // on desktop.
