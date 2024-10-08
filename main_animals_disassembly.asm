
main_animals:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 22 2f 00 00    	pushq  0x2f22(%rip)        # 3f48 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 23 2f 00 00 	bnd jmpq *0x2f23(%rip)        # 3f50 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	pushq  $0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmpq 1020 <.plt>
    107f:	90                   	nop
    1080:	f3 0f 1e fa          	endbr64 
    1084:	68 05 00 00 00       	pushq  $0x5
    1089:	f2 e9 91 ff ff ff    	bnd jmpq 1020 <.plt>
    108f:	90                   	nop
    1090:	f3 0f 1e fa          	endbr64 
    1094:	68 06 00 00 00       	pushq  $0x6
    1099:	f2 e9 81 ff ff ff    	bnd jmpq 1020 <.plt>
    109f:	90                   	nop
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	68 07 00 00 00       	pushq  $0x7
    10a9:	f2 e9 71 ff ff ff    	bnd jmpq 1020 <.plt>
    10af:	90                   	nop
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	68 08 00 00 00       	pushq  $0x8
    10b9:	f2 e9 61 ff ff ff    	bnd jmpq 1020 <.plt>
    10bf:	90                   	nop
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	68 09 00 00 00       	pushq  $0x9
    10c9:	f2 e9 51 ff ff ff    	bnd jmpq 1020 <.plt>
    10cf:	90                   	nop
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	68 0a 00 00 00       	pushq  $0xa
    10d9:	f2 e9 41 ff ff ff    	bnd jmpq 1020 <.plt>
    10df:	90                   	nop
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	68 0b 00 00 00       	pushq  $0xb
    10e9:	f2 e9 31 ff ff ff    	bnd jmpq 1020 <.plt>
    10ef:	90                   	nop
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	68 0c 00 00 00       	pushq  $0xc
    10f9:	f2 e9 21 ff ff ff    	bnd jmpq 1020 <.plt>
    10ff:	90                   	nop
    1100:	f3 0f 1e fa          	endbr64 
    1104:	68 0d 00 00 00       	pushq  $0xd
    1109:	f2 e9 11 ff ff ff    	bnd jmpq 1020 <.plt>
    110f:	90                   	nop

Disassembly of section .plt.got:

0000000000001110 <__cxa_finalize@plt>:
    1110:	f3 0f 1e fa          	endbr64 
    1114:	f2 ff 25 ad 2e 00 00 	bnd jmpq *0x2ead(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001120 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@plt>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	f2 ff 25 2d 2e 00 00 	bnd jmpq *0x2e2d(%rip)        # 3f58 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@GLIBCXX_3.4.21>
    112b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001130 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@plt>:
    1130:	f3 0f 1e fa          	endbr64 
    1134:	f2 ff 25 25 2e 00 00 	bnd jmpq *0x2e25(%rip)        # 3f60 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@GLIBCXX_3.4.21>
    113b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001140 <__cxa_atexit@plt>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	f2 ff 25 1d 2e 00 00 	bnd jmpq *0x2e1d(%rip)        # 3f68 <__cxa_atexit@GLIBC_2.2.5>
    114b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001150 <_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@plt>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	f2 ff 25 15 2e 00 00 	bnd jmpq *0x2e15(%rip)        # 3f70 <_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@GLIBCXX_3.4.21>
    115b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001160 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	f2 ff 25 0d 2e 00 00 	bnd jmpq *0x2e0d(%rip)        # 3f78 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001170 <_ZNSolsEPFRSoS_E@plt>:
    1170:	f3 0f 1e fa          	endbr64 
    1174:	f2 ff 25 05 2e 00 00 	bnd jmpq *0x2e05(%rip)        # 3f80 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
    117b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001180 <_ZNSaIcED1Ev@plt>:
    1180:	f3 0f 1e fa          	endbr64 
    1184:	f2 ff 25 fd 2d 00 00 	bnd jmpq *0x2dfd(%rip)        # 3f88 <_ZNSaIcED1Ev@GLIBCXX_3.4>
    118b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001190 <__stack_chk_fail@plt>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	f2 ff 25 f5 2d 00 00 	bnd jmpq *0x2df5(%rip)        # 3f90 <__stack_chk_fail@GLIBC_2.4>
    119b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011a0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEPKc@plt>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	f2 ff 25 ed 2d 00 00 	bnd jmpq *0x2ded(%rip)        # 3f98 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEPKc@GLIBCXX_3.4.21>
    11ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011b0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@plt>:
    11b0:	f3 0f 1e fa          	endbr64 
    11b4:	f2 ff 25 e5 2d 00 00 	bnd jmpq *0x2de5(%rip)        # 3fa0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@GLIBCXX_3.4.21>
    11bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011c0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@plt>:
    11c0:	f3 0f 1e fa          	endbr64 
    11c4:	f2 ff 25 dd 2d 00 00 	bnd jmpq *0x2ddd(%rip)        # 3fa8 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@GLIBCXX_3.4.21>
    11cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011d0 <_ZNSt8ios_base4InitC1Ev@plt>:
    11d0:	f3 0f 1e fa          	endbr64 
    11d4:	f2 ff 25 d5 2d 00 00 	bnd jmpq *0x2dd5(%rip)        # 3fb0 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
    11db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011e0 <_Unwind_Resume@plt>:
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	f2 ff 25 cd 2d 00 00 	bnd jmpq *0x2dcd(%rip)        # 3fb8 <_Unwind_Resume@GCC_3.0>
    11eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000011f0 <_ZNSaIcEC1Ev@plt>:
    11f0:	f3 0f 1e fa          	endbr64 
    11f4:	f2 ff 25 c5 2d 00 00 	bnd jmpq *0x2dc5(%rip)        # 3fc0 <_ZNSaIcEC1Ev@GLIBCXX_3.4>
    11fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001200 <_start>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	31 ed                	xor    %ebp,%ebp
    1206:	49 89 d1             	mov    %rdx,%r9
    1209:	5e                   	pop    %rsi
    120a:	48 89 e2             	mov    %rsp,%rdx
    120d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1211:	50                   	push   %rax
    1212:	54                   	push   %rsp
    1213:	4c 8d 05 16 04 00 00 	lea    0x416(%rip),%r8        # 1630 <__libc_csu_fini>
    121a:	48 8d 0d 9f 03 00 00 	lea    0x39f(%rip),%rcx        # 15c0 <__libc_csu_init>
    1221:	48 8d 3d a6 01 00 00 	lea    0x1a6(%rip),%rdi        # 13ce <main>
    1228:	ff 15 b2 2d 00 00    	callq  *0x2db2(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    122e:	f4                   	hlt    
    122f:	90                   	nop

0000000000001230 <deregister_tm_clones>:
    1230:	48 8d 3d e1 2d 00 00 	lea    0x2de1(%rip),%rdi        # 4018 <__TMC_END__>
    1237:	48 8d 05 da 2d 00 00 	lea    0x2dda(%rip),%rax        # 4018 <__TMC_END__>
    123e:	48 39 f8             	cmp    %rdi,%rax
    1241:	74 15                	je     1258 <deregister_tm_clones+0x28>
    1243:	48 8b 05 8e 2d 00 00 	mov    0x2d8e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    124a:	48 85 c0             	test   %rax,%rax
    124d:	74 09                	je     1258 <deregister_tm_clones+0x28>
    124f:	ff e0                	jmpq   *%rax
    1251:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1258:	c3                   	retq   
    1259:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001260 <register_tm_clones>:
    1260:	48 8d 3d b1 2d 00 00 	lea    0x2db1(%rip),%rdi        # 4018 <__TMC_END__>
    1267:	48 8d 35 aa 2d 00 00 	lea    0x2daa(%rip),%rsi        # 4018 <__TMC_END__>
    126e:	48 29 fe             	sub    %rdi,%rsi
    1271:	48 89 f0             	mov    %rsi,%rax
    1274:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1278:	48 c1 f8 03          	sar    $0x3,%rax
    127c:	48 01 c6             	add    %rax,%rsi
    127f:	48 d1 fe             	sar    %rsi
    1282:	74 14                	je     1298 <register_tm_clones+0x38>
    1284:	48 8b 05 65 2d 00 00 	mov    0x2d65(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    128b:	48 85 c0             	test   %rax,%rax
    128e:	74 08                	je     1298 <register_tm_clones+0x38>
    1290:	ff e0                	jmpq   *%rax
    1292:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1298:	c3                   	retq   
    1299:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012a0 <__do_global_dtors_aux>:
    12a0:	f3 0f 1e fa          	endbr64 
    12a4:	80 3d a5 2e 00 00 00 	cmpb   $0x0,0x2ea5(%rip)        # 4150 <completed.8061>
    12ab:	75 2b                	jne    12d8 <__do_global_dtors_aux+0x38>
    12ad:	55                   	push   %rbp
    12ae:	48 83 3d 12 2d 00 00 	cmpq   $0x0,0x2d12(%rip)        # 3fc8 <__cxa_finalize@GLIBC_2.2.5>
    12b5:	00 
    12b6:	48 89 e5             	mov    %rsp,%rbp
    12b9:	74 0c                	je     12c7 <__do_global_dtors_aux+0x27>
    12bb:	48 8b 3d 46 2d 00 00 	mov    0x2d46(%rip),%rdi        # 4008 <__dso_handle>
    12c2:	e8 49 fe ff ff       	callq  1110 <__cxa_finalize@plt>
    12c7:	e8 64 ff ff ff       	callq  1230 <deregister_tm_clones>
    12cc:	c6 05 7d 2e 00 00 01 	movb   $0x1,0x2e7d(%rip)        # 4150 <completed.8061>
    12d3:	5d                   	pop    %rbp
    12d4:	c3                   	retq   
    12d5:	0f 1f 00             	nopl   (%rax)
    12d8:	c3                   	retq   
    12d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000012e0 <frame_dummy>:
    12e0:	f3 0f 1e fa          	endbr64 
    12e4:	e9 77 ff ff ff       	jmpq   1260 <register_tm_clones>
    12e9:	90                   	nop

00000000000012ea <_ZN4CaneC1ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>:
    12ea:	f3 0f 1e fa          	endbr64 
    12ee:	55                   	push   %rbp
    12ef:	48 89 e5             	mov    %rsp,%rbp
    12f2:	53                   	push   %rbx
    12f3:	48 83 ec 18          	sub    $0x18,%rsp
    12f7:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    12fb:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    12ff:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1303:	48 89 c7             	mov    %rax,%rdi
    1306:	e8 31 02 00 00       	callq  153c <_ZN7AnimaleC1Ev>
    130b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    130f:	48 8d 35 ef 0c 00 00 	lea    0xcef(%rip),%rsi        # 2005 <_ZStL19piecewise_construct+0x1>
    1316:	48 89 c7             	mov    %rax,%rdi
    1319:	e8 82 fe ff ff       	callq  11a0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEPKc@plt>
    131e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1322:	48 8d 50 20          	lea    0x20(%rax),%rdx
    1326:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    132a:	48 89 c6             	mov    %rax,%rsi
    132d:	48 89 d7             	mov    %rdx,%rdi
    1330:	e8 eb fd ff ff       	callq  1120 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_@plt>
    1335:	eb 1e                	jmp    1355 <_ZN4CaneC1ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE+0x6b>
    1337:	f3 0f 1e fa          	endbr64 
    133b:	48 89 c3             	mov    %rax,%rbx
    133e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1342:	48 89 c7             	mov    %rax,%rdi
    1345:	e8 22 02 00 00       	callq  156c <_ZN7AnimaleD1Ev>
    134a:	48 89 d8             	mov    %rbx,%rax
    134d:	48 89 c7             	mov    %rax,%rdi
    1350:	e8 8b fe ff ff       	callq  11e0 <_Unwind_Resume@plt>
    1355:	48 83 c4 18          	add    $0x18,%rsp
    1359:	5b                   	pop    %rbx
    135a:	5d                   	pop    %rbp
    135b:	c3                   	retq   

000000000000135c <_ZN4Cane6abbaiaEv>:
    135c:	f3 0f 1e fa          	endbr64 
    1360:	55                   	push   %rbp
    1361:	48 89 e5             	mov    %rsp,%rbp
    1364:	48 83 ec 10          	sub    $0x10,%rsp
    1368:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    136c:	48 8d 35 97 0c 00 00 	lea    0xc97(%rip),%rsi        # 200a <_ZStL19piecewise_construct+0x6>
    1373:	48 8d 3d c6 2c 00 00 	lea    0x2cc6(%rip),%rdi        # 4040 <_ZSt4cout@@GLIBCXX_3.4>
    137a:	e8 e1 fd ff ff       	callq  1160 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    137f:	48 89 c2             	mov    %rax,%rdx
    1382:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1386:	48 83 c0 20          	add    $0x20,%rax
    138a:	48 89 c6             	mov    %rax,%rsi
    138d:	48 89 d7             	mov    %rdx,%rdi
    1390:	e8 bb fd ff ff       	callq  1150 <_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@plt>
    1395:	48 8d 35 81 0c 00 00 	lea    0xc81(%rip),%rsi        # 201d <_ZStL19piecewise_construct+0x19>
    139c:	48 89 c7             	mov    %rax,%rdi
    139f:	e8 bc fd ff ff       	callq  1160 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
    13a4:	48 89 c2             	mov    %rax,%rdx
    13a7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13ab:	48 89 c6             	mov    %rax,%rsi
    13ae:	48 89 d7             	mov    %rdx,%rdi
    13b1:	e8 9a fd ff ff       	callq  1150 <_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@plt>
    13b6:	48 89 c2             	mov    %rax,%rdx
    13b9:	48 8b 05 10 2c 00 00 	mov    0x2c10(%rip),%rax        # 3fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
    13c0:	48 89 c6             	mov    %rax,%rsi
    13c3:	48 89 d7             	mov    %rdx,%rdi
    13c6:	e8 a5 fd ff ff       	callq  1170 <_ZNSolsEPFRSoS_E@plt>
    13cb:	90                   	nop
    13cc:	c9                   	leaveq 
    13cd:	c3                   	retq   

00000000000013ce <main>:
    13ce:	f3 0f 1e fa          	endbr64 
    13d2:	55                   	push   %rbp
    13d3:	48 89 e5             	mov    %rsp,%rbp
    13d6:	53                   	push   %rbx
    13d7:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
    13de:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    13e5:	00 00 
    13e7:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    13eb:	31 c0                	xor    %eax,%eax
    13ed:	48 8d 85 7f ff ff ff 	lea    -0x81(%rbp),%rax
    13f4:	48 89 c7             	mov    %rax,%rdi
    13f7:	e8 f4 fd ff ff       	callq  11f0 <_ZNSaIcEC1Ev@plt>
    13fc:	48 8d 95 7f ff ff ff 	lea    -0x81(%rbp),%rdx
    1403:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    1407:	48 8d 35 1b 0c 00 00 	lea    0xc1b(%rip),%rsi        # 2029 <_ZStL19piecewise_construct+0x25>
    140e:	48 89 c7             	mov    %rax,%rdi
    1411:	e8 9a fd ff ff       	callq  11b0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_@plt>
    1416:	48 8d 55 80          	lea    -0x80(%rbp),%rdx
    141a:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    141e:	48 89 d6             	mov    %rdx,%rsi
    1421:	48 89 c7             	mov    %rax,%rdi
    1424:	e8 c1 fe ff ff       	callq  12ea <_ZN4CaneC1ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>
    1429:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    142d:	48 89 c7             	mov    %rax,%rdi
    1430:	e8 fb fc ff ff       	callq  1130 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@plt>
    1435:	48 8d 85 7f ff ff ff 	lea    -0x81(%rbp),%rax
    143c:	48 89 c7             	mov    %rax,%rdi
    143f:	e8 3c fd ff ff       	callq  1180 <_ZNSaIcED1Ev@plt>
    1444:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1448:	48 89 c7             	mov    %rax,%rdi
    144b:	e8 0c ff ff ff       	callq  135c <_ZN4Cane6abbaiaEv>
    1450:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1454:	48 89 c7             	mov    %rax,%rdi
    1457:	e8 40 01 00 00       	callq  159c <_ZN4CaneD1Ev>
    145c:	b8 00 00 00 00       	mov    $0x0,%eax
    1461:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    1465:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
    146c:	00 00 
    146e:	74 5b                	je     14cb <main+0xfd>
    1470:	eb 54                	jmp    14c6 <main+0xf8>
    1472:	f3 0f 1e fa          	endbr64 
    1476:	48 89 c3             	mov    %rax,%rbx
    1479:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    147d:	48 89 c7             	mov    %rax,%rdi
    1480:	e8 ab fc ff ff       	callq  1130 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@plt>
    1485:	eb 07                	jmp    148e <main+0xc0>
    1487:	f3 0f 1e fa          	endbr64 
    148b:	48 89 c3             	mov    %rax,%rbx
    148e:	48 8d 85 7f ff ff ff 	lea    -0x81(%rbp),%rax
    1495:	48 89 c7             	mov    %rax,%rdi
    1498:	e8 e3 fc ff ff       	callq  1180 <_ZNSaIcED1Ev@plt>
    149d:	48 89 d8             	mov    %rbx,%rax
    14a0:	48 89 c7             	mov    %rax,%rdi
    14a3:	e8 38 fd ff ff       	callq  11e0 <_Unwind_Resume@plt>
    14a8:	f3 0f 1e fa          	endbr64 
    14ac:	48 89 c3             	mov    %rax,%rbx
    14af:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    14b3:	48 89 c7             	mov    %rax,%rdi
    14b6:	e8 e1 00 00 00       	callq  159c <_ZN4CaneD1Ev>
    14bb:	48 89 d8             	mov    %rbx,%rax
    14be:	48 89 c7             	mov    %rax,%rdi
    14c1:	e8 1a fd ff ff       	callq  11e0 <_Unwind_Resume@plt>
    14c6:	e8 c5 fc ff ff       	callq  1190 <__stack_chk_fail@plt>
    14cb:	48 81 c4 88 00 00 00 	add    $0x88,%rsp
    14d2:	5b                   	pop    %rbx
    14d3:	5d                   	pop    %rbp
    14d4:	c3                   	retq   

00000000000014d5 <_Z41__static_initialization_and_destruction_0ii>:
    14d5:	f3 0f 1e fa          	endbr64 
    14d9:	55                   	push   %rbp
    14da:	48 89 e5             	mov    %rsp,%rbp
    14dd:	48 83 ec 10          	sub    $0x10,%rsp
    14e1:	89 7d fc             	mov    %edi,-0x4(%rbp)
    14e4:	89 75 f8             	mov    %esi,-0x8(%rbp)
    14e7:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    14eb:	75 32                	jne    151f <_Z41__static_initialization_and_destruction_0ii+0x4a>
    14ed:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    14f4:	75 29                	jne    151f <_Z41__static_initialization_and_destruction_0ii+0x4a>
    14f6:	48 8d 3d 54 2c 00 00 	lea    0x2c54(%rip),%rdi        # 4151 <_ZStL8__ioinit>
    14fd:	e8 ce fc ff ff       	callq  11d0 <_ZNSt8ios_base4InitC1Ev@plt>
    1502:	48 8d 15 ff 2a 00 00 	lea    0x2aff(%rip),%rdx        # 4008 <__dso_handle>
    1509:	48 8d 35 41 2c 00 00 	lea    0x2c41(%rip),%rsi        # 4151 <_ZStL8__ioinit>
    1510:	48 8b 05 e1 2a 00 00 	mov    0x2ae1(%rip),%rax        # 3ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
    1517:	48 89 c7             	mov    %rax,%rdi
    151a:	e8 21 fc ff ff       	callq  1140 <__cxa_atexit@plt>
    151f:	90                   	nop
    1520:	c9                   	leaveq 
    1521:	c3                   	retq   

0000000000001522 <_GLOBAL__sub_I__ZN4CaneC2ENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE>:
    1522:	f3 0f 1e fa          	endbr64 
    1526:	55                   	push   %rbp
    1527:	48 89 e5             	mov    %rsp,%rbp
    152a:	be ff ff 00 00       	mov    $0xffff,%esi
    152f:	bf 01 00 00 00       	mov    $0x1,%edi
    1534:	e8 9c ff ff ff       	callq  14d5 <_Z41__static_initialization_and_destruction_0ii>
    1539:	5d                   	pop    %rbp
    153a:	c3                   	retq   
    153b:	90                   	nop

000000000000153c <_ZN7AnimaleC1Ev>:
    153c:	f3 0f 1e fa          	endbr64 
    1540:	55                   	push   %rbp
    1541:	48 89 e5             	mov    %rsp,%rbp
    1544:	48 83 ec 10          	sub    $0x10,%rsp
    1548:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    154c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1550:	48 89 c7             	mov    %rax,%rdi
    1553:	e8 68 fc ff ff       	callq  11c0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@plt>
    1558:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    155c:	48 83 c0 20          	add    $0x20,%rax
    1560:	48 89 c7             	mov    %rax,%rdi
    1563:	e8 58 fc ff ff       	callq  11c0 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@plt>
    1568:	90                   	nop
    1569:	c9                   	leaveq 
    156a:	c3                   	retq   
    156b:	90                   	nop

000000000000156c <_ZN7AnimaleD1Ev>:
    156c:	f3 0f 1e fa          	endbr64 
    1570:	55                   	push   %rbp
    1571:	48 89 e5             	mov    %rsp,%rbp
    1574:	48 83 ec 10          	sub    $0x10,%rsp
    1578:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    157c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1580:	48 83 c0 20          	add    $0x20,%rax
    1584:	48 89 c7             	mov    %rax,%rdi
    1587:	e8 a4 fb ff ff       	callq  1130 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@plt>
    158c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1590:	48 89 c7             	mov    %rax,%rdi
    1593:	e8 98 fb ff ff       	callq  1130 <_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@plt>
    1598:	90                   	nop
    1599:	c9                   	leaveq 
    159a:	c3                   	retq   
    159b:	90                   	nop

000000000000159c <_ZN4CaneD1Ev>:
    159c:	f3 0f 1e fa          	endbr64 
    15a0:	55                   	push   %rbp
    15a1:	48 89 e5             	mov    %rsp,%rbp
    15a4:	48 83 ec 10          	sub    $0x10,%rsp
    15a8:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    15ac:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15b0:	48 89 c7             	mov    %rax,%rdi
    15b3:	e8 b4 ff ff ff       	callq  156c <_ZN7AnimaleD1Ev>
    15b8:	90                   	nop
    15b9:	c9                   	leaveq 
    15ba:	c3                   	retq   
    15bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000015c0 <__libc_csu_init>:
    15c0:	f3 0f 1e fa          	endbr64 
    15c4:	41 57                	push   %r15
    15c6:	4c 8d 3d 4b 27 00 00 	lea    0x274b(%rip),%r15        # 3d18 <__frame_dummy_init_array_entry>
    15cd:	41 56                	push   %r14
    15cf:	49 89 d6             	mov    %rdx,%r14
    15d2:	41 55                	push   %r13
    15d4:	49 89 f5             	mov    %rsi,%r13
    15d7:	41 54                	push   %r12
    15d9:	41 89 fc             	mov    %edi,%r12d
    15dc:	55                   	push   %rbp
    15dd:	48 8d 2d 44 27 00 00 	lea    0x2744(%rip),%rbp        # 3d28 <__do_global_dtors_aux_fini_array_entry>
    15e4:	53                   	push   %rbx
    15e5:	4c 29 fd             	sub    %r15,%rbp
    15e8:	48 83 ec 08          	sub    $0x8,%rsp
    15ec:	e8 0f fa ff ff       	callq  1000 <_init>
    15f1:	48 c1 fd 03          	sar    $0x3,%rbp
    15f5:	74 1f                	je     1616 <__libc_csu_init+0x56>
    15f7:	31 db                	xor    %ebx,%ebx
    15f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1600:	4c 89 f2             	mov    %r14,%rdx
    1603:	4c 89 ee             	mov    %r13,%rsi
    1606:	44 89 e7             	mov    %r12d,%edi
    1609:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    160d:	48 83 c3 01          	add    $0x1,%rbx
    1611:	48 39 dd             	cmp    %rbx,%rbp
    1614:	75 ea                	jne    1600 <__libc_csu_init+0x40>
    1616:	48 83 c4 08          	add    $0x8,%rsp
    161a:	5b                   	pop    %rbx
    161b:	5d                   	pop    %rbp
    161c:	41 5c                	pop    %r12
    161e:	41 5d                	pop    %r13
    1620:	41 5e                	pop    %r14
    1622:	41 5f                	pop    %r15
    1624:	c3                   	retq   
    1625:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    162c:	00 00 00 00 

0000000000001630 <__libc_csu_fini>:
    1630:	f3 0f 1e fa          	endbr64 
    1634:	c3                   	retq   

Disassembly of section .fini:

0000000000001638 <_fini>:
    1638:	f3 0f 1e fa          	endbr64 
    163c:	48 83 ec 08          	sub    $0x8,%rsp
    1640:	48 83 c4 08          	add    $0x8,%rsp
    1644:	c3                   	retq   
