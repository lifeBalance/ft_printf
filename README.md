# ft_printf
Are you tired of using alternatively ft_putstr and ft_putnbr for your displays? You don’t have the right to use printf? Re-code your own! This is a good time to discover a C feature: variadic functions, and to train your display options management skills. You will then be able to use your ft_printf in all future projects.

![succeded with 112](graded.png "Succeded with 112")

This was the first project in the **algorithms branch** (old curriculum).

## Conversion Specifications
A conversion specification is made up of the following parts:
```
%[flags][min-field-width].[precision][length]Specifier
```

### Flags
These are the flags to implement:

* `#`: Alternate form
* `0`: Zero padded (ignored if '-' flag, or specified 'Precision' with d i o u x X)
* `-`: Left align result
* `+`: Prepend sign (+ or -) to SIGNED conversions
* ` `: (A space character. Overrides '+' flag) Leave a space before:

	* Positive numbers produced by SIGNED conversions.
	* Before strings.

### Length
The length modifier:

* `h`:	Signed/unsigned **char**: hd, hi, hu
	1. Signed: hd, hi
	2. Unsigned: hu

* `hh`:	Signed/unsigned **short int**: hhc, hhu
	1. Signed: hhc
	2. Unsigned: hhu

* `l`:	Signed/unsigned **long int**:
	1. Signed: ld, li, l
	2. Unsigned: lu

* `ll`: Signed/unsigned **long long int**: lld, lli, llu
	Signed **double**: llf, lli, llu

* `L`:	Signed **long double**: Lf

### Specifiers
The **specifier** is the last part of a **conversion specification**. These are the ones we had to implement:

* `c`: character
* `s`: string
* `d`: integer
* `i`: integer
* `u`: unsigned integer
* `p`: memory address (0x7ffc48)
* `x`: hexadecimal (7ffc48)
* `X`: hexadecimal (7FFC48)
* `f`: float (always signed in C)

## Error messsages?
Since we were supposed to create a **non buffered** version of `printf`, I didn't do any error handling. But these are the type of error and error messages I was considering at the beginning:

* When there are more data arguments than conversion specifiers:
```c
printf("hello %d\n", 3, 3);
```
`error: data argument not used by format string`

* When there are more conversion specifiers than data arguments:
```c
printf("hello %d %d\n", 3);
```
`error: more '%' conversions than data arguments`

* When the specifier doesn't match the data argument:
```c
printf("hello %d\n", 3.3);
```
`error: format specifies type 'int' but the argument has type 'double'`

* When we use conversion specification w/o conversion specifiers:
// printf(" test percent: %"); // error: incomplete format specifier
// printf(" test percent: % \n"); // error: invalid conversion specifier '\x0a'

Valgrind: checking for leaks
============================
1. Compile your program with the -g option.

2. Run:
```
valgrind --leak-check=yes --log-file=/tmp/test_printf.log ./test_printf -s
```

3. Check logs:
```
cat /tmp/test_printf.log
```

Extensibility
=============
Once a new function is added to the dispatcher, don't forget to update the length of the FUN macro, used to allocate memory for the array of function pointers by 'init_dispatcher' (in ft_printf.c).