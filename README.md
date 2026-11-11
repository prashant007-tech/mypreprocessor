Mini C Preprocessor



A modular C project that implements a simplified version of the C preprocessor using C programming and file handling concepts.



Overview



The Mini C Preprocessor processes C source files and generates an expanded output file by performing preprocessing operations.



Features



\- User-defined Header Inclusion: Includes contents of user-defined header files.

\- Comment Removal: Removes single-line ("//") and multi-line ("/\* \*/") comments.

\- Macro Substitution: Supports object-like macro definitions and replacement.

\- Modular Design: Implementation divided into separate C source and header files.

\- File Handling: Uses standard C file operations to read, process and write source files.



Technologies Used



\- C Programming

\- Embedded C fundamentals

\- File Handling

\- Pointers and Strings

\- Structures

\- Makefile / GCC



Project Structure



mypreprocessor/

│

├── main.c

├── file\_inclusion.c

├── comment\_removal.c

├── comment\_removal.h

├── macro\_substitution.c

├── macro\_extended.c

├── input.c

├── header.h

├── header1.h

├── header2.h

├── .gitignore

└── README.md



Compilation



Compile the project using GCC and the provided build file:



make -f make



Execution



./exe



Learning Outcomes



\- Understanding how preprocessing works.

\- Practical implementation of file handling in C.

\- String parsing and manipulation.

\- Working with structures and pointers.

\- Developing a modular C application.



Future Enhancements



\- Function-like macro substitution.

\- Support for multiple macro parameters.

\- Nested header file inclusion.

\- Improved error handling.



Author



Prashant



GitHub: "prashant007-tech" (https://github.com/prashant007-tech)

