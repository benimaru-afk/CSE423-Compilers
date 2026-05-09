	.file	"test.kt"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$96, %rsp
	movq	$5, %rax
	movq	%rax, -8(%rbp)
	movq	$10, %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	$0, %eax
	call	printf@PLT
	movq	%rax, -48(%rbp)
	movq	$0, %rax
	jmp	.Lend_main
.Lend_main:
	leave
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits
