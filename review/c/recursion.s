	.file	"recursion.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"sum of numbers in interval [%d, %d) = %d\n"
.LC3:
	.string	"square root of %f = %f\n"
.LC4:
	.string	"minimal change for %d:  %s\n"
	.align 8
.LC5:
	.string	"there isn't a minimal change for %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -48(%rbp)
	movl	$15, -44(%rbp)
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	interval
	movl	%eax, %ecx
	movl	-44(%rbp), %edx
	movl	-48(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	-32(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	movq	.LC2(%rip), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	root_bisection
	movq	%xmm0, %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %xmm1
	movq	%rax, %xmm0
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$2, %eax
	call	printf@PLT
	movl	$15, -40(%rbp)
	movl	$4, -24(%rbp)
	movl	$5, -20(%rbp)
	movl	$8, -16(%rbp)
	movw	$0, -10(%rbp)
	leaq	-10(%rbp), %rdx
	leaq	-24(%rbp), %rcx
	movl	-40(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	change
	movl	%eax, -36(%rbp)
	cmpl	$0, -36(%rbp)
	jne	.L2
	leaq	-10(%rbp), %rdx
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.globl	interval
	.type	interval, @function
interval:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jne	.L7
	movl	$0, %eax
	jmp	.L8
.L7:
	movl	-4(%rbp), %eax
	leal	1(%rax), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	%edx, %edi
	call	interval
	movl	-4(%rbp), %edx
	addl	%edx, %eax
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	interval, .-interval
	.globl	root_bisection
	.type	root_bisection, @function
root_bisection:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	%xmm2, -40(%rbp)
	movsd	-32(%rbp), %xmm0
	subsd	-24(%rbp), %xmm0
	movsd	.LC6(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	mulsd	%xmm0, %xmm0
	movsd	-40(%rbp), %xmm1
	movsd	.LC7(%rip), %xmm2
	subsd	%xmm2, %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L10
	movsd	-8(%rbp), %xmm0
	movapd	%xmm0, %xmm1
	mulsd	%xmm0, %xmm1
	movsd	-40(%rbp), %xmm2
	movsd	.LC7(%rip), %xmm0
	addsd	%xmm2, %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L10
	movq	-8(%rbp), %rax
	jmp	.L13
.L10:
	movsd	-8(%rbp), %xmm0
	mulsd	%xmm0, %xmm0
	movsd	-40(%rbp), %xmm2
	movsd	.LC7(%rip), %xmm1
	addsd	%xmm2, %xmm1
	comisd	%xmm1, %xmm0
	jb	.L19
	movsd	-40(%rbp), %xmm1
	movsd	-8(%rbp), %xmm0
	movq	-24(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	root_bisection
	movq	%xmm0, %rax
	jmp	.L13
.L19:
	movsd	-40(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	root_bisection
	movq	%xmm0, %rax
.L13:
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	root_bisection, .-root_bisection
	.section	.rodata
.LC8:
	.string	"ultimo: %d   (%d)\n"
.LC9:
	.string	"resto: %d\n"
.LC10:
	.string	"%d "
.LC11:
	.string	"%d\n"
.LC12:
	.string	"dim: %ld\n"
.LC13:
	.string	"fatto"
	.text
	.globl	change
	.type	change, @function
change:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r12
	pushq	%rbx
	subq	$112, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movl	%edi, -100(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%rdx, -120(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movl	$2105376, -45(%rbp)
	movb	$0, -41(%rbp)
	movl	$3, -76(%rbp)
	movl	$0, -72(%rbp)
	movl	-76(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	-76(%rbp), %edx
	movl	%eax, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-76(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ecx
	movl	-100(%rbp), %eax
	cltd
	idivl	%ecx
	movl	%edx, -68(%rbp)
	movl	-68(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$0, -68(%rbp)
	jne	.L21
	movl	$0, -84(%rbp)
	jmp	.L22
.L23:
	movl	-76(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	leaq	-45(%rbp), %rax
	leaq	.LC10(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	leaq	-45(%rbp), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat@PLT
	addl	$1, -84(%rbp)
.L22:
	movl	-76(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ebx
	movl	-100(%rbp), %eax
	cltd
	idivl	%ebx
	cmpl	%eax, -84(%rbp)
	jl	.L23
	movl	$0, %eax
	jmp	.L37
.L21:
	movl	-76(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -88(%rbp)
	jmp	.L25
.L36:
	movq	%rsp, %rax
	movq	%rax, %r12
	movl	-88(%rbp), %edx
	movl	-76(%rbp), %eax
	subl	%edx, %eax
	leal	-2(%rax), %ebx
	movl	%ebx, %eax
	subq	$1, %rax
	movq	%rax, -64(%rbp)
	movl	%ebx, %eax
	movq	%rax, %r14
	movl	$0, %r15d
	movl	%ebx, %eax
	movq	%rax, -144(%rbp)
	movq	$0, -136(%rbp)
	movl	%ebx, %eax
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	movq	%rax, %rcx
	andq	$-4096, %rcx
	movq	%rsp, %rdx
	subq	%rcx, %rdx
.L26:
	cmpq	%rdx, %rsp
	je	.L27
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L26
.L27:
	movq	%rax, %rdx
	andl	$4095, %edx
	subq	%rdx, %rsp
	movq	%rax, %rdx
	andl	$4095, %edx
	testq	%rdx, %rdx
	je	.L28
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L28:
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -56(%rbp)
	movl	-76(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -84(%rbp)
	jmp	.L29
.L30:
	movl	-84(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	-84(%rbp), %ecx
	movl	-76(%rbp), %edx
	subl	%ecx, %edx
	leal	-2(%rdx), %ecx
	movl	(%rax), %edx
	movq	-56(%rbp), %rax
	movl	%ecx, %ecx
	movl	%edx, (%rax,%rcx,4)
	movl	-84(%rbp), %edx
	movl	-76(%rbp), %eax
	subl	%edx, %eax
	leal	-2(%rax), %edx
	movq	-56(%rbp), %rax
	movl	%edx, %edx
	movl	(%rax,%rdx,4), %eax
	movl	%eax, %esi
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	subl	$1, -84(%rbp)
.L29:
	movl	-84(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jge	.L30
	movl	%ebx, %eax
	salq	$2, %rax
	shrq	$2, %rax
	addq	$1, %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -84(%rbp)
	jmp	.L31
.L35:
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	-76(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	imull	-84(%rbp), %eax
	movl	%eax, %edx
	movl	-68(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movq	-120(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rax, %rsi
	movl	%ecx, %edi
	call	change
	movl	%eax, -72(%rbp)
	cmpl	$0, -72(%rbp)
	jne	.L32
	movl	$0, -80(%rbp)
	jmp	.L33
.L34:
	movl	-88(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	leaq	-45(%rbp), %rax
	leaq	.LC10(%rip), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf@PLT
	leaq	-45(%rbp), %rdx
	movq	-120(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcat@PLT
	addl	$1, -80(%rbp)
.L33:
	movl	-88(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %ebx
	movl	-100(%rbp), %eax
	cltd
	idivl	%ebx
	cmpl	%eax, -80(%rbp)
	jl	.L34
	movl	$0, %eax
	movq	%r12, %rsp
	jmp	.L37
.L32:
	addl	$1, -84(%rbp)
.L31:
	movl	-76(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	movq	-112(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %esi
	movl	-100(%rbp), %eax
	cltd
	idivl	%esi
	cmpl	%eax, -84(%rbp)
	jle	.L35
	movq	%r12, %rsp
	subl	$1, -88(%rbp)
.L25:
	cmpl	$0, -88(%rbp)
	jns	.L36
	movl	$1, %eax
.L37:
	movq	-40(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L38
	call	__stack_chk_fail@PLT
.L38:
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	change, .-change
	.section	.rodata
	.align 8
.LC1:
	.long	824633721
	.long	1077165064
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC6:
	.long	0
	.long	1073741824
	.align 8
.LC7:
	.long	-1998362383
	.long	1055193269
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
