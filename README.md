# printf


# Introduction

The versatility of the printf function in C represents a great exercise in programming for
us. This project is of moderate difficulty. It will enable you to discover variadic functions
in C.
The key to a successful ft_printf is a well-structured and good extensible code.


# Mandatory part

External functions allowed: malloc, free, write, va_start, va_arg, va_copy, va_end
Description: Write a library that contains ft_printf, a function
that will mimic the real printf
```
- The prototype of ft_printf should beint ft_printf(const char *, ..)
- You have to recode thelibc’sprintffunction
- It must not do the buffer management like the realprintf
- It will manage the following conversions: cspdiuxX%
- It will manage any combination of the following flags: ’-0.*’ and 	minimum field width with all conversions
- It will be compared with the real printf
- You must use the commandarto create your librairy, using the 			commandlibtool is forbidden.