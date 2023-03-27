### Python questions


#### Q

1) How do you create markdown cell in Jupyter? (with keyboard commands)

2) How do you delete a cell in Jupyter (with keyboard command)?

3) How do you add a cell above the current one in Jupyter (with keyboard command)?

4) What advantage does conda environment provide over a system-wide installation of python?

5) What does it mean that variables are dynamically typed in python?

6) What's the difference between python and C/C++ integers?

7) Explain the difference between lists, sets and tuples in python.

8) What does negative index mean when accessing list elements?

9) How do you print the first N elements of a list?

10) How do you print every Nth element of a list?

11) How do you print the reverse list?

12) Give an example of a list comprehension.

13) Give an example of cell and line magic commands in Jupyter.

14) Write a "hello world" function in python (syntax errors are not ok in hello world even on paper).

15) What are keyword function arguments in python and what is their advantage?

16) Why shouldn't you do from numpy import *?

17) What is the advantage of using numpy arrays over lists? What are the dangers?

18) What's the most widely used package for plotting in python?

19) What's the purpose of \__str__ method in a python class?

20) What package can you use in python for symbolic calculations?

21) What are decorators? Write an example (minor syntax errors are ok here)

22) Name two ways of calling c++ code from python.

23) What is pandas? Name at least 5 functions from that package.


#### A

1) If you are inside a cell you have to press ESC and then the M key. If you are already in command mode just press the M key.

2) If you are inside a cell you have to press ESC and then the D key twice. If you are already in command mode just press the D key twice.

3) If you are inside a cell you have to press ESC and then the A key. If you are already in command mode just press the A key.

4) Using conda you can create different enviroments in which you can use different versions of python and packages that are incompatible one with the other.

5) It means that when declaring a variable the programmer doesn't have to specify the type (since it is automatically inferred by the value assigned to the variable), and that the type of the variable can be changed.

6) That in python you can't have integer overflow, since there is no limit to the integer number you can store in a variable. Anyway, if possible it is better not to store a too large number in a variable, since it can cause the program to be slow.

7) Lists are collections of objects (also of different types) accessible by indexing, and mutable (meaning that they can be changed adding, removing or substituting elements). Tuples are just like lists but they are immutable. Sets are similar to lists and tuples but they are mutable, they don't have repetitions and they cannot be accessed by indexing.

8) It is used to access the element starting to count from the end of the list. For example list[-1] is the last element of the list, list[-2] is the previous one, and so on.

9) We can use: print(list_name[:N]).

10) We can use: print(list_name[N-1::N]).

11) We can use: print(list_name[::-1]).

12) [x**2 for x in range(1, 20) if x%2==0], which prints the squares of the even numbers from 2 to 18 included.

13) A cell magic command: %%timeit (to time the code in a cell); a line magic command: %timeit (to time one line of code).

14) def hello():
        print("hello world!").

15) They are arguments that are passed to a function preceded by a keyword, for example: func(argument_keyword=argument_value). The advantage is that you do not have to remember the order of the arguments (as for positional argument).

16) When you use a function or a class of a library in python you have to specify the name of the library (for example: numpy.array); that unless you use 'from library_name import *', in which case all the functions and classes from the library become available without library specification. This is considered to be bad practice, since it can create conflicts of names between functions or classes with same name but different purpose. Also specifying the name of the library makes the code more readable.

17) Some of the advantages are vectorization (which in many cases makes possible to avoid for loops), availability of multidimensional objects, speed and a large number of functions not available for lists. Some of the dangers are for instance integer overflow (not present in the standard library) and the fact that a poor use of numpy arrays can make the program slow.

18) Matplotlib.

19) It allows you to create an output that is displayed everytime the function print() is called with an instance of the class as argument.

20) SymPy.

21) A decorator allows you to modify a function using another function.

For instance we can define the decorator:

    def add_1(f):
        def wrapper(*args, **kwarg):
            return f(*args, **kwargs)+1
        return wrapper

This function takes as input another function and returns a function that does the same as the input function but adding 1 to the result. Then we can use the decorator syntax to modify a certain function, in the following way:

    @add_1
    def prod(a, b):
        return a*b

The function prod() now is a function that takes two numbers as input and returns their product plus one.

22) Ctypes and pybind11.

23) Pandas is a python package that allows you to manipulate data similarly to R. For example you can use a dataframe structure very similar to R's dataframe. Some of the functions available in pandas are: read_csv(), concat(), DataFrame.loc(), DataFrame.head(), DataFrame.tail().