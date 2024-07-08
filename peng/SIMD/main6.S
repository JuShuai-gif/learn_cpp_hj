	.file	"test6.cpp"
# GNU C++14 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE test6.cpp
# -mtune=generic -march=x86-64
# -auxbase-strip /home/robot/code/c++/learn_cpp_hj/peng/SIMD/main6.S -O3
# -fomit-frame-pointer -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -falign-functions -falign-jumps -falign-labels -falign-loops
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcaller-saves -fcode-hoisting
# -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fdefer-pop
# -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexceptions -fexpensive-optimizations -fforward-propagate
# -ffp-int-builtin-inexact -ffunction-cse -fgcse -fgcse-after-reload
# -fgcse-lm -fgnu-runtime -fgnu-unique -fguess-branch-probability
# -fhoist-adjacent-loads -fident -fif-conversion -fif-conversion2
# -findirect-inlining -finline -finline-atomics -finline-functions
# -finline-functions-called-once -finline-small-functions -fipa-bit-cp
# -fipa-cp -fipa-cp-clone -fipa-icf -fipa-icf-functions -fipa-icf-variables
# -fipa-profile -fipa-pure-const -fipa-ra -fipa-reference
# -fipa-reference-addressable -fipa-sra -fipa-stack-alignment -fipa-vrp
# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -floop-interchange
# -floop-unroll-and-jam -flra-remat -flto-odr-type-merging -fmath-errno
# -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
# -fomit-frame-pointer -foptimize-sibling-calls -foptimize-strlen
# -fpartial-inlining -fpeel-loops -fpeephole -fpeephole2 -fplt
# -fpredictive-commoning -fprefetch-loop-arrays -free -freg-struct-return
# -freorder-blocks -freorder-blocks-and-partition -freorder-functions
# -frerun-cse-after-loop -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fschedule-insns2 -fsemantic-interposition -fshow-column -fshrink-wrap
# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
# -fsplit-loops -fsplit-paths -fsplit-wide-types -fssa-backprop
# -fssa-phiopt -fstack-clash-protection -fstack-protector-strong
# -fstdarg-opt -fstore-merging -fstrict-aliasing
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
# -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-distribute-patterns -ftree-loop-distribution
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-loop-vectorize -ftree-parallelize-loops=
# -ftree-partial-pre -ftree-phiprop -ftree-pre -ftree-pta -ftree-reassoc
# -ftree-scev-cprop -ftree-sink -ftree-slp-vectorize -ftree-slsr -ftree-sra
# -ftree-switch-conversion -ftree-tail-merge -ftree-ter -ftree-vrp
# -funit-at-a-time -funswitch-loops -funwind-tables -fverbose-asm
# -fversion-loops-for-strides -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.p2align 4
	.globl	_Z4funcv
	.type	_Z4funcv, @function
_Z4funcv:
.LFB1146:
	.cfi_startproc
	endbr64	
	subq	$56, %rsp	#,
	.cfi_def_cfa_offset 64
# test6.cpp:6:         arr[i] = i;
	movdqa	.LC1(%rip), %xmm0	#, tmp96
	movdqa	.LC3(%rip), %xmm1	#, tmp112
# test6.cpp:2: int func(){
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp113
	movq	%rax, 40(%rsp)	# tmp113, D.30725
	xorl	%eax, %eax	# tmp113
	leaq	32(%rsp), %rdx	#, tmp111
# test6.cpp:6:         arr[i] = i;
	movaps	%xmm0, (%rsp)	# tmp96, MEM[(value_type &)&arr]
	movdqa	.LC2(%rip), %xmm0	#, tmp97
	movaps	%xmm0, 16(%rsp)	# tmp97, MEM[(value_type &)&arr + 16]
	movdqa	.LC0(%rip), %xmm0	#, vect_vec_iv_.13
.L2:
	movdqa	%xmm0, %xmm2	# vect_vec_iv_.13, vect_vec_iv_.13
	paddd	%xmm1, %xmm0	# tmp112, vect_vec_iv_.13
# test6.cpp:6:         arr[i] = i;
	movaps	%xmm2, (%rdx,%rax)	# vect_vec_iv_.13, MEM[symbol: arr, index: ivtmp.28_24, offset: 32]
	addq	$16, %rax	#, ivtmp.28
	cmpq	$368, %rax	#, ivtmp.28
	jne	.L2	#,
# test6.cpp:11:         ret += arr[i];
	movdqa	(%rsp), %xmm0	# MEM[(value_type &)&arr], vect_ret_13.5
	paddd	16(%rsp), %xmm0	# MEM[(value_type &)&arr + 16], vect_ret_13.5
	xorl	%eax, %eax	# ivtmp.19
.L3:
# test6.cpp:11:         ret += arr[i];
	paddd	(%rdx,%rax), %xmm0	# MEM[symbol: arr, index: ivtmp.19_12, offset: 32], vect_ret_13.5
	addq	$16, %rax	#, ivtmp.19
	cmpq	$368, %rax	#, ivtmp.19
	jne	.L3	#,
# test6.cpp:14: }
	movq	40(%rsp), %rcx	# D.30725, tmp114
	xorq	%fs:40, %rcx	# MEM[(<address-space-1> long unsigned int *)40B], tmp114
	movdqa	%xmm0, %xmm1	# vect_ret_13.5, tmp106
	psrldq	$8, %xmm1	#, tmp106
	paddd	%xmm1, %xmm0	# tmp106, vect_ret_13.11
	movdqa	%xmm0, %xmm1	# vect_ret_13.11, tmp107
	psrldq	$4, %xmm1	#, tmp107
# test6.cpp:13:     return ret;    
	paddd	%xmm1, %xmm0	# tmp107, vect_ret_13.11
	movd	%xmm0, %eax	# vect_ret_13.11, stmp_ret_13.10
# test6.cpp:14: }
	jne	.L9	#,
	addq	$56, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret	
.L9:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
	.cfi_endproc
.LFE1146:
	.size	_Z4funcv, .-_Z4funcv
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	8
	.long	9
	.long	10
	.long	11
	.align 16
.LC1:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC2:
	.long	4
	.long	5
	.long	6
	.long	7
	.align 16
.LC3:
	.long	4
	.long	4
	.long	4
	.long	4
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
