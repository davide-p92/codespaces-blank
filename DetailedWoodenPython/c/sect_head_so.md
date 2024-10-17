There are 15 section headers, starting at offset 0x260:

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .text             PROGBITS         0000000000000000  00000040
       0000000000000000  0000000000000000  AX       0     0     1
  [ 2] .data             PROGBITS         0000000000000000  00000040
       0000000000000000  0000000000000000  WA       0     0     1
  [ 3] .bss              NOBITS           0000000000000000  00000040
       0000000000000000  0000000000000000  WA       0     0     1
  [ 4] .rodata.str1.1    PROGBITS         0000000000000000  00000040
       000000000000000d  0000000000000001 AMS       0     0     1
  [ 5] .text.startup     PROGBITS         0000000000000000  00000050
       0000000000000017  0000000000000000  AX       0     0     16
  [ 6] .rela.text.s[...] RELA             0000000000000000  00000188
       0000000000000030  0000000000000018   I      12     5     8
  [ 7] .comment          PROGBITS         0000000000000000  00000067
       0000000000000013  0000000000000001  MS       0     0     1
  [ 8] .note.GNU-stack   PROGBITS         0000000000000000  0000007a
       0000000000000000  0000000000000000           0     0     1
  [ 9] .note.gnu.pr[...] NOTE             0000000000000000  00000080
       0000000000000030  0000000000000000   A       0     0     8
  [10] .eh_frame         PROGBITS         0000000000000000  000000b0
       0000000000000030  0000000000000000   A       0     0     8
  [11] .rela.eh_frame    RELA             0000000000000000  000001b8
       0000000000000018  0000000000000018   I      12    10     8
  [12] .symtab           SYMTAB           0000000000000000  000000e0
       0000000000000090  0000000000000018          13     4     8
  [13] .strtab           STRTAB           0000000000000000  00000170
       0000000000000017  0000000000000000           0     0     1
  [14] .shstrtab         STRTAB           0000000000000000  000001d0
       0000000000000089  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), l (large), p (processor specific)
