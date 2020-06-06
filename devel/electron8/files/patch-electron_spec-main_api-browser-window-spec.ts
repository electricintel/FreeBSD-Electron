--- electron/spec-main/api-browser-window-spec.ts.orig	2020-06-01 16:32:39 UTC
+++ electron/spec-main/api-browser-window-spec.ts
@@ -926,7 +926,7 @@ describe('BrowserWindow module', () => {
           w.setPosition(pos[0], pos[1])
         })
       })
-      ifdescribe(process.platform !== 'linux')(`Maximized state`, () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(`Maximized state`, () => {
         it(`checks normal bounds when maximized`, (done) => {
           const bounds = w.getBounds()
           w.once('maximize', () => {
@@ -949,7 +949,7 @@ describe('BrowserWindow module', () => {
           w.maximize()
         })
       })
-      ifdescribe(process.platform !== 'linux')(`Minimized state`, () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(`Minimized state`, () => {
         it(`checks normal bounds when minimized`, (done) => {
           const bounds = w.getBounds()
           w.once('minimize', () => {
@@ -1431,7 +1431,7 @@ describe('BrowserWindow module', () => {
   describe('BrowserWindow.setOpacity(opacity)', () => {
     afterEach(closeAllWindows)
 
-    ifdescribe(process.platform !== 'linux')(('Windows and Mac'), () => {
+    ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(('Windows and Mac'), () => {
       it('make window with initial opacity', () => {
         const w = new BrowserWindow({ show: false, opacity: 0.5 })
         expect(w.getOpacity()).to.equal(0.5)
@@ -1457,7 +1457,7 @@ describe('BrowserWindow module', () => {
       })
     })
 
-    ifdescribe(process.platform === 'linux')(('Linux'), () => {
+    ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')(('Linux'), () => {
       it('sets 1 regardless of parameter', () => {
         const w = new BrowserWindow({ show: false })
         w.setOpacity(0)
@@ -2250,7 +2250,7 @@ describe('BrowserWindow module', () => {
         expect(test.version).to.equal(process.version)
         expect(test.versions).to.deep.equal(process.versions)
 
-        if (process.platform === 'linux' && test.osSandbox) {
+        if ((process.platform === 'linux' || process.platform === 'freebsd') && test.osSandbox) {
           expect(test.creationTime).to.be.null('creation time')
           expect(test.systemMemoryInfo).to.be.null('system memory info')
         } else {
@@ -2758,7 +2758,7 @@ describe('BrowserWindow module', () => {
     })
   })
 
-  ifdescribe(process.platform !== 'linux')('max/minimize events', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('max/minimize events', () => {
     afterEach(closeAllWindows)
     it('emits an event when window is maximized', (done) => {
       const w = new BrowserWindow({show: false})
@@ -3300,7 +3300,7 @@ describe('BrowserWindow module', () => {
     })
   })
 
-  ifdescribe(process.platform !== 'linux')('window states (excluding Linux)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('window states (excluding Linux)', () => {
     // Not implemented on Linux.
     afterEach(closeAllWindows)
 
@@ -3998,8 +3998,8 @@ describe('BrowserWindow module', () => {
     })
   })
 
-  const skip = features.isOffscreenRenderingEnabled() && 
-    (process.platform !== 'linux' || process.arch !== 'ia32')
+  const skip = features.isOffscreenRenderingEnabled() &&
+    ((process.platform !== 'linux' && process.platform !== 'freebsd') || process.arch !== 'ia32')
   ifdescribe(skip)('offscreen rendering', () => {
     let w: BrowserWindow
     beforeEach(function () {
