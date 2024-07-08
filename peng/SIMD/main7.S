	.file	"test7.cpp"
# GNU C++14 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE test7.cpp
# -mtune=generic -march=x86-64
# -auxbase-strip /home/robot/code/c++/learn_cpp_hj/peng/SIMD/main7.S -O3
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
	.globl	_Z10vector_addDv2_xS_
	.type	_Z10vector_addDv2_xS_, @function
_Z10vector_addDv2_xS_:
.LFB542:
	.cfi_startproc
	endbr64	
# /usr/lib/gcc/x86_64-linux-gnu/9/include/emmintrin.h:1042:   return (__m128i) ((__v4su)__A + (__v4su)__B);
	paddd	%xmm1, %xmm0	# tmp91, tmp89
# test7.cpp:6: }
	ret	
	.cfi_endproc
.LFE542:
	.size	_Z10vector_addDv2_xS_, .-_Z10vector_addDv2_xS_
	.p2align 4
	.globl	_Z11add_vectorsPiS_S_i
	.type	_Z11add_vectorsPiS_S_i, @function
_Z11add_vectorsPiS_S_i:
.LFB5534:
	.cfi_startproc
	endbr64	
# test7.cpp:12:     for (int i = 0; i < size; i += 4) {
	testl	%ecx, %ecx	# size
	jle	.L3	#,
	xorl	%eax, %eax	# ivtmp.14
	.p2align 4,,10
	.p2align 3
.L5:
# /usr/lib/gcc/x86_64-linux-gnu/9/include/emmintrin.h:1042:   return (__m128i) ((__v4su)__A + (__v4su)__B);
	movdqa	(%rsi,%rax,4), %xmm0	# MEM[base: b_12(D), index: ivtmp.14_25, step: 4, offset: 0B], tmp94
	paddd	(%rdi,%rax,4), %xmm0	# MEM[base: a_10(D), index: ivtmp.14_25, step: 4, offset: 0B], tmp94
# /usr/lib/gcc/x86_64-linux-gnu/9/include/emmintrin.h:721:   *__P = __B;
	movaps	%xmm0, (%rdx,%rax,4)	# tmp94, MEM[base: c_15(D), index: ivtmp.14_25, step: 4, offset: 0B]
	addq	$4, %rax	#, ivtmp.14
# test7.cpp:12:     for (int i = 0; i < size; i += 4) {
	cmpl	%eax, %ecx	# ivtmp.14, size
	jg	.L5	#,
.L3:
# test7.cpp:18: }
	ret	
	.cfi_endproc
.LFE5534:
	.size	_Z11add_vectorsPiS_S_i, .-_Z11add_vectorsPiS_S_i
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
