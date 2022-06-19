__asm__(R"(
	.text
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB21:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB27:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
_ZStL13allocator_arg:
	.space 1
_ZStL6ignore:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.align 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
_ZStL10defer_lock:
	.space 1
_ZStL11try_to_lock:
	.space 1
_ZStL10adopt_lock:
	.space 1
	.align 4
_ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
_ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
_ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
_ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
_ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
_ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
_ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
_ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
_ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
_ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
_ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
_ZNSt15regex_constantsL13match_defaultE:
	.space 4
	.align 4
_ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
_ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
_ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
_ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
_ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
_ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
_ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
_ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
_ZNSt15regex_constantsL14format_defaultE:
	.space 4
	.align 4
_ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
_ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
_ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
_ZNSt15regex_constantsL13error_collateE:
	.space 4
	.align 4
_ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
_ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
_ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
_ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
_ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
_ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
_ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
_ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
_ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
_ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
_ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
_ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 4
_ZNSt8__detailL19_S_invalid_state_idE:
	.long	-1
	.align 4
_ZL4maxn:
	.long	200010
	.globl	a
	.bss
	.align 32
a:
	.space 800040
	.globl	m
	.align 4
m:
	.space 4
	.globl	n
	.align 4
n:
	.space 4
	.globl	t_case
	.align 4
t_case:
	.space 4
	.globl	pre
	.align 32
pre:
	.space 1600080
	.section	.text$_ZSt3minIiERKT_S2_S2_,"x"
	.linkonce discard
	.globl	_ZSt3minIiERKT_S2_S2_
	.def	_ZSt3minIiERKT_S2_S2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt3minIiERKT_S2_S2_
_ZSt3minIiERKT_S2_S2_:
.LFB8749:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L6
	movq	24(%rbp), %rax
	jmp	.L7
.L6:
	movq	16(%rbp), %rax
.L7:
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
.LC1:
	.ascii "%d%d\0"
.LC2:
	.ascii "%lld\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8748:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	leaq	t_case(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
.L15:
	movl	t_case(%rip), %eax
	leal	-1(%rax), %edx
	movl	%edx, t_case(%rip)
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L9
	leaq	m(%rip), %r8
	leaq	n(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	_Z5scanfPKcz
	movl	$1, -4(%rbp)
.L11:
	movl	n(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jg	.L10
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
	movl	-4(%rbp), %eax
	subl	$1, %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	pre(%rip), %rax
	movq	(%rdx,%rax), %rcx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	a(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	addq	%rax, %rcx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	pre(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	addl	$1, -4(%rbp)
	jmp	.L11
.L10:
	leaq	m(%rip), %rdx
	leaq	n(%rip), %rcx
	call	_ZSt3minIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movq	$0, -32(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
.L13:
	movl	n(%rip), %eax
	cmpl	%eax, -8(%rbp)
	jg	.L12
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	pre(%rip), %rax
	movq	(%rdx,%rax), %rcx
	movl	-8(%rbp), %eax
	subl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	leaq	pre(%rip), %rax
	movq	(%rdx,%rax), %rax
	subq	%rax, %rcx
	movq	%rcx, %rax
	movq	%rax, -24(%rbp)
	leaq	-24(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_Z5ckmaxIxEbRT_RKS0_
	addl	$1, -8(%rbp)
	jmp	.L13
.L12:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movl	-12(%rbp), %eax
	subl	$1, %eax
	cltq
	imulq	%rdx, %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -32(%rbp)
	movl	m(%rip), %edx
	movl	n(%rip), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, m(%rip)
	movl	m(%rip), %eax
	testl	%eax, %eax
	jle	.L14
	movl	m(%rip), %eax
	movslq	%eax, %rdx
	movl	n(%rip), %eax
	cltq
	imulq	%rdx, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -32(%rbp)
.L14:
	movq	-32(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rcx
	call	_Z6printfPKcz
	jmp	.L15
.L9:
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z5ckmaxIxEbRT_RKS0_,"x"
	.linkonce discard
	.globl	_Z5ckmaxIxEbRT_RKS0_
	.def	_Z5ckmaxIxEbRT_RKS0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5ckmaxIxEbRT_RKS0_
_Z5ckmaxIxEbRT_RKS0_:
.LFB9308:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rdx
	movq	24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jge	.L18
	movq	24(%rbp), %rax
	movq	(%rax), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movl	$1, %eax
	jmp	.L19
.L18:
	movl	$0, %eax
.L19:
	popq	%rbp
	ret
	.seh_endproc
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB10119:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB10118:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L24
	cmpl	$65535, 24(%rbp)
	jne	.L24
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L24:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_a;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_a
_GLOBAL__sub_I_a:
.LFB10142:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_a
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
)");