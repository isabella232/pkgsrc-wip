$NetBSD$

--- gdbserver/netbsd-low.h.orig	2020-09-02 16:10:13.482596165 +0000
+++ gdbserver/netbsd-low.h
@@ -0,0 +1,157 @@
+/* Copyright (C) 2020 Free Software Foundation, Inc.
+
+   This file is part of GDB.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 3 of the License, or
+   (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
+
+#ifndef GDBSERVER_NETBSD_LOW_H
+#define GDBSERVER_NETBSD_LOW_H
+
+struct regcache;
+struct target_desc;
+
+/*  Some information relative to a given register set.   */
+
+struct netbsd_regset_info
+{
+  /* The ptrace request needed to get/set registers of this set.  */
+  int get_request, set_request;
+  /* The size of the register set.  */
+  int size;
+  /* Fill the buffer BUF from the contents of the given REGCACHE.  */
+  void (*fill_function) (struct regcache *regcache, char *buf);
+  /* Store the register value in BUF in the given REGCACHE.  */
+  void (*store_function) (struct regcache *regcache, const char *buf);
+};
+
+/* A list of regsets for the target being debugged, terminated by an entry
+   where the size is negative.
+
+   This list should be created by the target-specific code.  */
+
+extern struct netbsd_regset_info netbsd_target_regsets[];
+
+/* The target-specific operations for NetBSD support.  */
+
+struct netbsd_target_ops
+{
+  /* Architecture-specific setup.  */
+  void (*arch_setup) ();
+
+  /* Hook to support target specific qSupported.  */
+  void (*process_qsupported) (char **, int count);
+};
+
+/* Target ops definitions for a NetBSD target.  */
+
+class netbsd_process_target : public process_stratum_target
+{
+public:
+
+  int create_inferior (const char *program,
+		       const std::vector<char *> &program_args) override;
+
+  void post_create_inferior () override;
+
+  int attach (unsigned long pid) override;
+
+  int kill (process_info *proc) override;
+
+  int detach (process_info *proc) override;
+
+  void mourn (process_info *proc) override;
+
+  void join (int pid) override;
+
+  bool thread_alive (ptid_t pid) override;
+
+  void resume (thread_resume *resume_info, size_t n) override;
+
+  ptid_t wait (ptid_t ptid, target_waitstatus *status,
+	       int options) override;
+
+  void fetch_registers (regcache *regcache, int regno) override;
+
+  void store_registers (regcache *regcache, int regno) override;
+
+  int read_memory (CORE_ADDR memaddr, unsigned char *myaddr,
+		   int len) override;
+
+  int write_memory (CORE_ADDR memaddr, const unsigned char *myaddr,
+		    int len) override;
+
+  void request_interrupt () override;
+
+  bool supports_read_auxv () override;
+
+  int read_auxv (CORE_ADDR offset, unsigned char *myaddr,
+		 unsigned int len) override;
+
+  bool supports_hardware_single_step () override;
+
+  const gdb_byte *sw_breakpoint_from_kind (int kind, int *size) override;
+
+  bool supports_z_point_type (char z_type) override;
+
+  int insert_point (enum raw_bkpt_type type, CORE_ADDR addr,
+		    int size, struct raw_breakpoint *bp) override;
+
+  int remove_point (enum raw_bkpt_type type, CORE_ADDR addr,
+		    int size, struct raw_breakpoint *bp) override;
+
+  bool stopped_by_sw_breakpoint () override;
+
+  bool supports_qxfer_siginfo () override;
+
+  int qxfer_siginfo (const char *annex, unsigned char *readbuf,
+		     unsigned const char *writebuf, CORE_ADDR offset,
+		     int len) override;
+
+  bool supports_stopped_by_sw_breakpoint () override;
+
+  bool supports_non_stop () override;
+
+  bool supports_multi_process () override;
+
+  bool supports_fork_events () override;
+
+  bool supports_vfork_events () override;
+
+  bool supports_exec_events () override;
+
+  bool supports_disable_randomization () override;
+
+  bool supports_qxfer_libraries_svr4 () override;
+
+  int qxfer_libraries_svr4 (const char*, unsigned char*, const unsigned char*,
+			    CORE_ADDR, int) override;
+
+  bool supports_pid_to_exec_file () override;
+
+  char *pid_to_exec_file (int pid) override;
+
+  const char *thread_name (ptid_t thread) override;
+
+  bool supports_catch_syscall () override;
+};
+
+/* The inferior's target description.  This is a global because the
+   NetBSD ports support neither bi-arch nor multi-process.  */
+
+extern struct netbsd_target_ops the_low_target;
+
+/* XXX: multilib */
+extern const struct target_desc *netbsd_tdesc;
+
+#endif /* GDBSERVER_NETBSD_LOW_H */
