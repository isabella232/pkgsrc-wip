$NetBSD$

--- cmake/config-ix.cmake.orig	2017-10-17 18:35:43.000000000 +0000
+++ cmake/config-ix.cmake
@@ -511,28 +511,28 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND LSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD")
   set(COMPILER_RT_HAS_LSAN TRUE)
 else()
   set(COMPILER_RT_HAS_LSAN FALSE)
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND MSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Linux")
+    OS_NAME MATCHES "Linux|NetBSD")
   set(COMPILER_RT_HAS_MSAN TRUE)
 else()
   set(COMPILER_RT_HAS_MSAN FALSE)
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND TSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Android|NetBSD")
   set(COMPILER_RT_HAS_TSAN TRUE)
 else()
   set(COMPILER_RT_HAS_TSAN FALSE)
