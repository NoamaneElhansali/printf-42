## 🚀 ft_printf: The Custom C Formatter

*A Simplified Reimplementation of the Standard C Library Function `printf()`*

| 🎯 Goal | 💡 Status | 🛠️ Language | 📚 Cursus |
| :--- | :--- | :--- | :--- |
| **Master C Variadic Functions & Format Parsing** | **Completed** | C (ISO C99) | 42 School |

---

## 📖 About the Project

The `ft_printf` project is a deep dive into the core mechanics of the famous C Standard Library function, `printf()`. This implementation focuses on recreating its essential functionality, providing a robust understanding of how C handles dynamic, variable-length argument lists and complex format string parsing.

### Key Learning Objectives

* **Variadic Functions Mastery:** Gaining proficiency with the `va_list` family of macros (`va_start`, `va_arg`, `va_end`) to securely and portably manage a variable number of arguments.
* **Format String Parsing:** Developing a structured approach to iterating through the format string and correctly interpreting different **Format Specifiers**.
* **Static Library Creation:** Building a reusable, clean **Static Library (`libftprintf.a`)** for modular use in future C projects.

### Function Prototype

The custom function signature mirrors the standard:

```c
int ft_printf(const char *format, ...);
```

## ✨ Mandatory Features Implemented

The following mandatory format conversion specifiers are **fully supported** and thoroughly tested:

| Specifier | Data Type | Description | Example Usage |
| :---: | :--- | :--- | :--- |
| **`%c`** | `char` | Prints a single character. | `ft_printf("%c", 'A')` |
| **`%s`** | `char *` | Prints a null-terminated string. | `ft_printf("%s", "Hello 42")` |
| **`%p`** | `void *` | Prints a pointer address in **lowercase hexadecimal**, prefixed with `0x`. | `ft_printf("%p", &var)` |
| **`%d` / `%i`** | `int` | Prints a signed decimal integer. | `ft_printf("%d", 42)` |
| **`%u`** | `unsigned int` | Prints an unsigned decimal integer. | `ft_printf("%u", 100)` |
| **`%x`** | `unsigned int` | Prints an unsigned integer in **lowercase hexadecimal**. | `ft_printf("%x", 255)` |
| **`%X`** | `unsigned int` | Prints an unsigned integer in **UPPERCASE hexadecimal**. | `ft_printf("%X", 255)` |
| **`%%`** | N/A | Prints a literal percent character. | `ft_printf("%%")` |



## 🛠️ Installation and Usage

Follow these simple steps to integrate libftprintf.a into your project.

# 1. Cloning the Repository

Start by getting the source code:
```bash
git clone [Your Repository URL] ft_printf
cd ft_printf
```

# 2. Compilation

Use the provided `Makefile` to compile the static library:
```bash
make
```
*📦 This command generates the static library file: `libftprintf.a`*

# 3. Linking in Your Code

To use `ft_printf` in a source file (e.g., `main.c`):

*1 . Include the Header:*
```c
#include "ft_printf.h"
```

*2 . `Compile and Link:` Choose one of the following methods:*

`Method A: Direct Library File`
```bash
gcc main.c libftprintf.a -o my_program
```

`Method B: Using Linker Flags (Recommended)`
```bash
gcc main.c -L. -lftprintf -o my_program
```