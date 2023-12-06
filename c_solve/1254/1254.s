	.file	"1254.c"
	.comm	_str, 101, 5
	.text
	.globl	_pel
	.def	_pel;	.scl	2;	.type	32;	.endef
_pel:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L2
L5:
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %edx
	movl	12(%ebp), %eax
	subl	-4(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	je	L3
	movl	$0, %eax
	jmp	L4
L3:
	addl	$1, -4(%ebp)
L2:
	movl	12(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	-4(%ebp), %eax
	jg	L5
	movl	12(%ebp), %eax
L4:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%s\0"
LC1:
	.ascii "%d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$_str, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	movl	$_str, (%esp)
	call	_strlen
	movl	%eax, 24(%esp)
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$_str, (%esp)
	call	_pel
	testl	%eax, %eax
	je	L7
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, %eax
	jmp	L8
L7:
	movl	$1, 28(%esp)
	jmp	L9
L11:
	movl	24(%esp), %eax
	subl	28(%esp), %eax
	movl	28(%esp), %edx
	addl	$_str, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_pel
	movl	%eax, 20(%esp)
	cmpl	$0, 20(%esp)
	je	L10
	movl	24(%esp), %eax
	addl	%eax, %eax
	subl	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	$0, %eax
	jmp	L8
L10:
	addl	$1, 28(%esp)
L9:
	movl	28(%esp), %eax
	cmpl	24(%esp), %eax
	jl	L11
	movl	$0, %eax
L8:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
