This is a slightly more complicated version of hello_basic.

Here we use a header file to define the functions used in the main (it is
useful when we have a lot of functions to include in the main, to not make
the main too long).
The header guard (#pragma once - non standard, in bigger projects we should
use the "canonical" one) avoids multiple incusions in the program of the
functions defined in the header file. In fact the compiler just copies the
functions in the header inside the main file; and using the header guard
we are just telling the compiler to do it only once.

To compile we must use: g++ main.cpp hello.cpp -o hello -I., where -I.
indicates the folder (in this case the current one) in which we should look
for the definition of the functions to include in the main (in other words
it tells the compiler where to look for the header file).
