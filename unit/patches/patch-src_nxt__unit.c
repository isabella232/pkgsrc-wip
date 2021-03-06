$NetBSD$

Use more apropriate format specifier for shm preix

--- src/nxt_unit.c.orig	2020-11-19 18:12:30.000000000 +0000
+++ src/nxt_unit.c
@@ -3762,8 +3762,8 @@ nxt_unit_shm_open(nxt_unit_ctx_t *ctx, s
 #if (NXT_HAVE_MEMFD_CREATE || NXT_HAVE_SHM_OPEN)
     char             name[64];
 
-    snprintf(name, sizeof(name), NXT_SHM_PREFIX "unit.%d.%p",
-             lib->pid, (void *) pthread_self());
+    snprintf(name, sizeof(name), NXT_SHM_PREFIX "unit.%d.%x",
+             lib->pid, pthread_self());
 #endif
 
 #if (NXT_HAVE_MEMFD_CREATE)
