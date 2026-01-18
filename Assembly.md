
# Assembly notes


## C and assembly
* gcc -S main.c -o main.s -> generates assembly code from C code

```c
int main() {
    int a = 5;
    int b = 10;
    int c = a + b;
    return 0;
}
```

```assembly
main:
	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp # Push the base pointer to the stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$5, -12(%rbp) # Move the value 5 to the stack (32 bit) at address -12(%rbp)
	movl	$10, -8(%rbp) # Move the value 10 to the stack (32 bit) at address -8(%rbp)
	movl	-12(%rbp), %edx # Move the value at address -12(%rbp) to the edx register
	movl	-8(%rbp), %eax # Move the value at address -8(%rbp) to the eax register
	addl	%edx, %eax # Add the value in edx to the value in eax
	movl	%eax, -4(%rbp) # Move the value in eax to the stack (32 bit) at address -4(%rbp)
	movl	$0, %eax # Move the value 0 to the eax register
	popq	%rbp # Pop the base pointer from the stack
	.cfi_def_cfa 7, 8
	ret # Return from the function
	.cfi_endproc # End of the function
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20260103"
	.section	.note.GNU-stack,"",@progbits
```
