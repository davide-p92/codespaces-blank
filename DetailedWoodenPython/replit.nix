{ pkgs }: {
	deps = [
   pkgs.pstree
   pkgs.kmod
   pkgs.strace
   pkgs.vim
   pkgs.tcpdump
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}