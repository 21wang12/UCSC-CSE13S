	.file	"banhammer.c"
	.globl	badspeak_message
	.section	.rodata
	.align 8
.LC0:
	.ascii	"Dear beloved citizen of the GPRSC,\n\nYou have been caug"
	.string	"ht using degenerate words that may cause\ndistress among the moral and upstanding citizens of the GPSRC.\nAs such, you will be sent to joycamp. It is there where you will\nsit and reflect on the consequences of your choice in language.\n\nYour transgressions:\n\n"
	.data
	.align 8
	.type	badspeak_message, @object
	.size	badspeak_message, 8
badspeak_message:
	.quad	.LC0
	.globl	goodspeak_message
	.section	.rodata
	.align 8
.LC1:
	.ascii	"Dear beloved citizen of the GPRSC,\n\nWe recognize your effo"
	.ascii	"rts in conforming to the language stand"
	.string	"ards\nof the GPSRC. Alas, you have been caught uttering questionable words\nand thinking unpleasant thoughts. You must correct your wrongspeak\nand badthink at once. Failure to do so will result in your deliverance\nto joycamp.\n\nWords that you must think on:\n\n"
	.data
	.align 8
	.type	goodspeak_message, @object
	.size	goodspeak_message, 8
goodspeak_message:
	.quad	.LC1
	.globl	mixspeak_message
	.section	.rodata
	.align 8
.LC2:
	.ascii	"Dear beloved citizen of the GPRSC,\n\nWe have some good news"
	.ascii	", and we have some bad news.\nThe good news is that there is"
	.ascii	" bad news. The bad news is that you will\nbe sent to j"
	.string	"oycamp and subjected to a week-long destitute existence.\nThis is the penalty for using degenerate words, as well as using\noldspeak in place of newspeak. We hope you can correct your behavior.\n\nYour transgressions, followed by the words you must think on:\n\n"
	.data
	.align 8
	.type	mixspeak_message, @object
	.size	mixspeak_message, 8
mixspeak_message:
	.quad	.LC2
	.section	.rodata
.LC3:
	.string	"ht:f:ms"
.LC4:
	.string	"r"
.LC5:
	.string	"badspeak.txt"
.LC6:
	.string	"%s\n"
.LC7:
	.string	"newspeak.txt"
.LC8:
	.string	"%s %s\n"
	.align 8
.LC9:
	.string	"([a-zA-Z0-9]((-|'|_)[a-zA-Z0-9])?)+"
.LC10:
	.string	"regcomp"
.LC11:
	.string	"%s"
.LC12:
	.string	"Seeks: %lu\n"
.LC13:
	.string	"Average seek length: %.6lf\n"
.LC15:
	.string	"Hash table load: %.6lf%% \n"
.LC16:
	.string	"Bloom filter load: %.6lf%% \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$3280, %rsp
	movl	%edi, -3252(%rbp)
	movq	%rsi, -3264(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -3220(%rbp)
	movl	$10000, -3232(%rbp)
	movl	$1048576, -3228(%rbp)
	movb	$0, -3234(%rbp)
	movb	$0, -3233(%rbp)
	jmp	.L2
.L10:
	movl	-3220(%rbp), %eax
	subl	$102, %eax
	cmpl	$14, %eax
	ja	.L3
	movl	%eax, %eax
	movq	.L5(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L5:
	.quad	.L4
	.quad	.L3
	.quad	.L6
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L7
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L3
	.quad	.L8
	.quad	.L9
	.text
.L6:
	movq	-3264(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	help
	movl	$0, %edi
	call	exit
.L9:
	movq	optarg(%rip), %rax
	movl	$10, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	strtoul
	movl	%eax, -3232(%rbp)
	jmp	.L2
.L4:
	movq	optarg(%rip), %rax
	movl	$10, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	strtoul
	movl	%eax, -3228(%rbp)
	jmp	.L2
.L7:
	movb	$1, -3234(%rbp)
	jmp	.L2
.L8:
	movb	$1, -3233(%rbp)
	jmp	.L2
.L3:
	movq	-3264(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	help
	movl	$0, %edi
	call	exit
.L2:
	movq	-3264(%rbp), %rcx
	movl	-3252(%rbp), %eax
	movl	$.LC3, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	getopt
	movl	%eax, -3220(%rbp)
	cmpl	$-1, -3220(%rbp)
	jne	.L10
	movl	-3228(%rbp), %eax
	movl	%eax, %edi
	call	bf_create
	movq	%rax, -3216(%rbp)
	movzbl	-3234(%rbp), %edx
	movl	-3232(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	ht_create
	movq	%rax, -3208(%rbp)
	movl	$.LC4, %esi
	movl	$.LC5, %edi
	call	fopen
	movq	%rax, -3184(%rbp)
	jmp	.L11
.L12:
	movq	-3216(%rbp), %rax
	leaq	-3088(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	bf_insert
	movq	-3208(%rbp), %rax
	leaq	-3088(%rbp), %rcx
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	ht_insert
.L11:
	leaq	-3088(%rbp), %rdx
	movq	-3184(%rbp), %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	cmpl	$-1, %eax
	jne	.L12
	movl	$.LC4, %esi
	movl	$.LC7, %edi
	call	fopen
	movq	%rax, -3176(%rbp)
	jmp	.L13
.L14:
	movq	-3216(%rbp), %rax
	leaq	-2064(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	bf_insert
	movq	-3208(%rbp), %rax
	leaq	-1040(%rbp), %rdx
	leaq	-2064(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	ht_insert
.L13:
	leaq	-1040(%rbp), %rcx
	leaq	-2064(%rbp), %rdx
	movq	-3176(%rbp), %rax
	movl	$.LC8, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	cmpl	$-1, %eax
	jne	.L14
	leaq	-3152(%rbp), %rax
	movl	$1, %edx
	movl	$.LC9, %esi
	movq	%rax, %rdi
	call	regcomp
	testl	%eax, %eax
	je	.L15
	movl	$.LC10, %edi
	call	perror
	movl	$1, %edi
	call	exit
.L15:
	movzbl	-3234(%rbp), %eax
	movl	%eax, %edi
	call	ll_create
	movq	%rax, -3200(%rbp)
	movzbl	-3234(%rbp), %eax
	movl	%eax, %edi
	call	ll_create
	movq	%rax, -3192(%rbp)
	movq	$0, -3168(%rbp)
	jmp	.L16
.L22:
	movl	$0, -3224(%rbp)
.L20:
	movl	-3224(%rbp), %eax
	movslq	%eax, %rdx
	movq	-3168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L43
	movl	-3224(%rbp), %eax
	movslq	%eax, %rdx
	movq	-3168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$64, %al
	jle	.L19
	movl	-3224(%rbp), %eax
	movslq	%eax, %rdx
	movq	-3168(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$90, %al
	jg	.L19
	movl	-3224(%rbp), %eax
	movslq	%eax, %rdx
	movq	-3168(%rbp), %rax
	addq	%rdx, %rax
	movl	-3224(%rbp), %edx
	movslq	%edx, %rcx
	movq	-3168(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rdx), %edx
	addl	$32, %edx
	movb	%dl, (%rax)
.L19:
	addl	$1, -3224(%rbp)
	jmp	.L20
.L43:
	nop
	movq	-3216(%rbp), %rax
	movq	-3168(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	bf_probe
	testb	%al, %al
	je	.L16
	movq	-3208(%rbp), %rax
	movq	-3168(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	ht_lookup
	movq	%rax, -3160(%rbp)
	cmpq	$0, -3160(%rbp)
	je	.L16
	movq	-3160(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L21
	movq	-3200(%rbp), %rax
	movq	-3168(%rbp), %rcx
	movl	$0, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	ll_insert
	jmp	.L16
.L21:
	movq	-3160(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-3192(%rbp), %rax
	movq	-3168(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	ll_insert
.L16:
	movq	stdin(%rip), %rax
	leaq	-3152(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	next_word
	movq	%rax, -3168(%rbp)
	cmpq	$0, -3168(%rbp)
	jne	.L22
	movzbl	-3233(%rbp), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L23
	movq	-3192(%rbp), %rax
	movq	%rax, %rdi
	call	ll_length
	testl	%eax, %eax
	je	.L24
	movq	-3200(%rbp), %rax
	movq	%rax, %rdi
	call	ll_length
	testl	%eax, %eax
	je	.L24
	movq	mixspeak_message(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
	movq	-3200(%rbp), %rax
	movq	%rax, %rdi
	call	ll_print
	movq	-3192(%rbp), %rax
	movq	%rax, %rdi
	call	ll_print
	jmp	.L27
.L24:
	movq	-3200(%rbp), %rax
	movq	%rax, %rdi
	call	ll_length
	testl	%eax, %eax
	je	.L26
	movq	-3192(%rbp), %rax
	movq	%rax, %rdi
	call	ll_length
	testl	%eax, %eax
	jne	.L26
	movq	badspeak_message(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
	movq	-3200(%rbp), %rax
	movq	%rax, %rdi
	call	ll_print
	jmp	.L27
.L26:
	movq	-3192(%rbp), %rax
	movq	%rax, %rdi
	call	ll_length
	testl	%eax, %eax
	jne	.L27
	movq	-3200(%rbp), %rax
	movq	%rax, %rdi
	call	ll_length
	testl	%eax, %eax
	je	.L27
	movq	goodspeak_message(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	printf
	movq	-3192(%rbp), %rax
	movq	%rax, %rdi
	call	ll_print
	jmp	.L27
.L23:
	movq	seeks(%rip), %rax
	movq	%rax, %rsi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
	movq	links(%rip), %rax
	testq	%rax, %rax
	js	.L28
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L29
.L28:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L29:
	movq	seeks(%rip), %rax
	testq	%rax, %rax
	js	.L30
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	jmp	.L31
.L30:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rdx, %xmm1
	addsd	%xmm1, %xmm1
.L31:
	divsd	%xmm1, %xmm0
	movl	$.LC13, %edi
	movl	$1, %eax
	call	printf
	movq	-3208(%rbp), %rax
	movq	%rax, %rdi
	call	ht_count
	movl	%eax, %eax
	testq	%rax, %rax
	js	.L32
	pxor	%xmm6, %xmm6
	cvtsi2sdq	%rax, %xmm6
	movsd	%xmm6, -3272(%rbp)
	jmp	.L33
.L32:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	movapd	%xmm0, %xmm2
	addsd	%xmm0, %xmm2
	movsd	%xmm2, -3272(%rbp)
.L33:
	movq	-3208(%rbp), %rax
	movq	%rax, %rdi
	call	ht_size
	movl	%eax, %eax
	testq	%rax, %rax
	js	.L34
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L35
.L34:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L35:
	movsd	-3272(%rbp), %xmm3
	divsd	%xmm0, %xmm3
	movapd	%xmm3, %xmm0
	movsd	.LC14(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movl	$.LC15, %edi
	movl	$1, %eax
	call	printf
	movq	-3216(%rbp), %rax
	movq	%rax, %rdi
	call	bf_count
	movl	%eax, %eax
	testq	%rax, %rax
	js	.L36
	pxor	%xmm7, %xmm7
	cvtsi2sdq	%rax, %xmm7
	movsd	%xmm7, -3272(%rbp)
	jmp	.L37
.L36:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	movapd	%xmm0, %xmm4
	addsd	%xmm0, %xmm4
	movsd	%xmm4, -3272(%rbp)
.L37:
	movq	-3216(%rbp), %rax
	movq	%rax, %rdi
	call	bf_size
	movl	%eax, %eax
	testq	%rax, %rax
	js	.L38
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L39
.L38:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L39:
	movsd	-3272(%rbp), %xmm5
	divsd	%xmm0, %xmm5
	movapd	%xmm5, %xmm0
	movsd	.LC14(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movl	$.LC16, %edi
	movl	$1, %eax
	call	printf
.L27:
	leaq	-3216(%rbp), %rax
	movq	%rax, %rdi
	call	bf_delete
	leaq	-3208(%rbp), %rax
	movq	%rax, %rdi
	call	ht_delete
	leaq	-3200(%rbp), %rax
	movq	%rax, %rdi
	call	ll_delete
	leaq	-3192(%rbp), %rax
	movq	%rax, %rdi
	call	ll_delete
	call	clear_words
	leaq	-3152(%rbp), %rax
	movq	%rax, %rdi
	call	regfree
	movq	-3184(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movq	-3176(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L41
	call	__stack_chk_fail
.L41:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
.LC17:
	.string	"SYNOPSIS"
	.align 8
.LC18:
	.string	"  A word filtering program for the GPRSC."
	.align 8
.LC19:
	.string	"  Filters out and reports bad words parsed from stdin."
.LC20:
	.string	"USAGE"
	.align 8
.LC21:
	.string	"  %s [-hsm] [-t size] [-f size]\n"
.LC22:
	.string	"OPTIONS"
	.align 8
.LC23:
	.string	"  -h           Program usage and help."
	.align 8
.LC24:
	.string	"  -s           Print program statistics."
	.align 8
.LC25:
	.string	"  -m           Enable move-to-front rule."
	.align 8
.LC26:
	.string	"  -t size      Specify hash table size (default: 10000)."
	.align 8
.LC27:
	.string	"  -f size      Specify Bloom filter size (default: 2^20)."
	.text
	.globl	help
	.type	help, @function
help:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	$.LC17, %edi
	call	puts
	movl	$.LC18, %edi
	call	puts
	movl	$.LC19, %edi
	call	puts
	movl	$10, %edi
	call	putchar
	movl	$.LC20, %edi
	call	puts
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC21, %edi
	movl	$0, %eax
	call	printf
	movl	$10, %edi
	call	putchar
	movl	$.LC22, %edi
	call	puts
	movl	$.LC23, %edi
	call	puts
	movl	$.LC24, %edi
	call	puts
	movl	$.LC25, %edi
	call	puts
	movl	$.LC26, %edi
	call	puts
	movl	$.LC27, %edi
	call	puts
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	help, .-help
	.section	.rodata
	.align 8
.LC14:
	.long	0
	.long	1079574528
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
