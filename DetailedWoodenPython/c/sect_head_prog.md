
Elf file type is EXEC (Executable file)
Entry point 0x401060
There are 13 program headers, starting at offset 64

Program Headers:
  Type           Offset             VirtAddr           PhysAddr
                 FileSiz            MemSiz              Flags  Align
  PHDR           0x0000000000000040 0x0000000000400040 0x0000000000400040
                 0x00000000000002d8 0x00000000000002d8  R      0x8
  INTERP         0x0000000000000318 0x0000000000400318 0x0000000000400318
                 0x0000000000000054 0x0000000000000054  R      0x1
      [Requesting program interpreter: /nix/store/4nlgxhb09sdr51nc9hdm8az5b08vzkgx-glibc-2.35-163/lib/ld-linux-x86-64.so.2]
  LOAD           0x0000000000000000 0x0000000000400000 0x0000000000400000
                 0x0000000000000640 0x0000000000000640  R      0x1000
  LOAD           0x0000000000001000 0x0000000000401000 0x0000000000401000
                 0x0000000000000155 0x0000000000000155  R E    0x1000
  LOAD           0x0000000000002000 0x0000000000402000 0x0000000000402000
                 0x00000000000000c4 0x00000000000000c4  R      0x1000
  LOAD           0x0000000000002db0 0x0000000000403db0 0x0000000000403db0
                 0x0000000000000260 0x0000000000000268  RW     0x1000
  DYNAMIC        0x0000000000002dc0 0x0000000000403dc0 0x0000000000403dc0
                 0x0000000000000210 0x0000000000000210  RW     0x8
  NOTE           0x0000000000000370 0x0000000000400370 0x0000000000400370
                 0x0000000000000040 0x0000000000000040  R      0x8
  NOTE           0x00000000000003b0 0x00000000004003b0 0x00000000004003b0
                 0x0000000000000020 0x0000000000000020  R      0x4
  GNU_PROPERTY   0x0000000000000370 0x0000000000400370 0x0000000000400370
                 0x0000000000000040 0x0000000000000040  R      0x8
  GNU_EH_FRAME   0x0000000000002010 0x0000000000402010 0x0000000000402010
                 0x000000000000002c 0x000000000000002c  R      0x4
  GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
                 0x0000000000000000 0x0000000000000000  RW     0x10
  GNU_RELRO      0x0000000000002db0 0x0000000000403db0 0x0000000000403db0
                 0x0000000000000250 0x0000000000000250  R      0x1

 Section to Segment mapping:
  Segment Sections...
   00     
   01     .interp 
   02     .interp .note.gnu.property .note.ABI-tag .hash .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn .rela.plt 
   03     .init .plt .text .fini 
   04     .rodata .eh_frame_hdr .eh_frame 
   05     .init_array .fini_array .dynamic .got .data .bss 
   06     .dynamic 
   07     .note.gnu.property 
   08     .note.ABI-tag 
   09     .note.gnu.property 
   10     .eh_frame_hdr 
   11     
   12     .init_array .fini_array .dynamic .got 
