$NetBSD$

--- src/VBox/Devices/Storage/DrvHostDVD.cpp.orig	2016-08-05 16:42:58.000000000 +0000
+++ src/VBox/Devices/Storage/DrvHostDVD.cpp
@@ -86,12 +86,15 @@
 # undef _interlockedbittestandreset64
 # undef USE_MEDIA_POLLING
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/cdefs.h>
 # include <sys/param.h>
+# undef PVM
 # include <stdio.h>
-# include <cam/cam.h>
-# include <cam/cam_ccb.h>
+# if defined(RT_OS_FREEBSD)
+#  include <cam/cam.h>
+#  include <cam/cam_ccb.h>
+# endif
 # define USE_MEDIA_POLLING
 
 #else
@@ -145,7 +148,7 @@ static DECLCALLBACK(int) drvHostDvdUnmou
             /*
              * Eject the disc.
              */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             uint8_t abCmd[16] =
             {
                 SCSI_START_STOP_UNIT, 0, 0, 0, 2 /*eject+stop*/, 0,
@@ -235,7 +238,7 @@ static DECLCALLBACK(int) drvHostDvdUnmou
  */
 static DECLCALLBACK(int) drvHostDvdDoLock(PDRVHOSTBASE pThis, bool fLock)
 {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     uint8_t abCmd[16] =
     {
         SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL, 0, 0, 0, fLock, 0,
@@ -323,7 +326,7 @@ static DECLCALLBACK(int) drvHostDvdPoll(
     /*
      * Poll for media change.
      */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 #ifdef RT_OS_DARWIN
     AssertReturn(pThis->ppScsiTaskDI, VERR_INTERNAL_ERROR);
 #endif
@@ -393,7 +396,7 @@ static DECLCALLBACK(int) drvHostDvdPoll(
         /*
          * Poll for media change.
          */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         /* taken care of above. */
 #elif defined(RT_OS_LINUX)
         bool fMediaChanged = ioctl(RTFileToNative(pThis->hFileDevice), CDROM_MEDIA_CHANGED, CDSL_CURRENT) == 1;
@@ -423,7 +426,7 @@ static DECLCALLBACK(int) drvHostDvdSendC
     int rc;
     LogFlow(("%s: cmd[0]=%#04x txdir=%d pcbBuf=%d timeout=%d\n", __FUNCTION__, pbCmd[0], enmTxDir, *pcbBuf, cTimeoutMillies));
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /*
      * Pass the request on to the internal scsi command interface.
      * The command seems to be 12 bytes long, the docs a bit copy&pasty on the command length point...
@@ -880,4 +883,3 @@ const PDMDRVREG g_DrvHostDVD =
     /* u32EndVersion */
     PDM_DRVREG_VERSION
 };
-
