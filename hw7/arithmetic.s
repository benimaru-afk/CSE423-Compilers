	.file	"arithmetic.kt"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
	movq	$20, %rax
	movq	%rax, -8(%rbp)
	movq	$6, %rax
	movq	%rax, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rdi
	movq	-32(%rbp), %rsi
	movl	$0, %eax
	call	printf@PLT
	movq	%rax, -40(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -48(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, -56(%rbp)
	movq	-48(%rbp), %rdi
	movq	-56(%rbp), %rsi
	movl	$0, %eax
	call	printf@PLT
	movq	%rax, -64(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -72(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -80(%rbp)
	movq	-72(%rbp), %rdi
	movq	-80(%rbp), %rsi
	movl	$0, %eax
	call	printf@PLT
	movq	%rax, -88(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -96(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	cqto
	idivq	%rcx
	movq	%rax, -104(%rbp)
	movq	-96(%rbp), %rdi
	movq	-104(%rbp), %rsi
	movl	$0, %eax
	call	printf@PLT
	movq	%rax, -112(%rbp)
	movq	$0, %rax
	jmp	.Lend_main
.Lend_main:
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
