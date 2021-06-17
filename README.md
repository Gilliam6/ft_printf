# ft_printf

Rewrite of printf C function w/o any malloc!

This is not a complete implementation of the printf function. Details are described in the subject.pdf. The peculiarities of the solution are in the absence of dynamically allocated memory. In this program only the output of char, string, int, hex, pointer, percent types works. all numerical values are output by recursion. When comparing with other printf implementations, the speed was about the same and depended more on the execution of the write function. My main goal in this project is to practice with recursion (even though it's not the best programming technique) and to work with the stdarg library.
