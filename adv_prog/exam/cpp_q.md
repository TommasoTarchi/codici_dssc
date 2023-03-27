### C++ questions


#### Q

1) Name at least 5 variable types in c++

2) What is "int overflow"?

3) Why using namespace std might not be a
good idea?

4) Which header do you have to include for the access to std::cout?

2) What would be the simplest "legal" program in c++?

3) What is the difference in c++ between struct and class?

4) What does break statement do in a loop in c++?

5) What does continue statement do in a loop?

6) How do you define a static array of type int and size 7?

7) what can you use to read interactive user input?

8) What is a reference?

9) What is a difference between passing variables to functions by reference and by value?

10) Why do we want to pass variables to functions by reference rather than by pointer?

11) If the function accepts pointers (signature int function(int* a)), how do you pass a variable defined as int x to it?

12) Why do we want to use const modifier whenever possible?

13) If you have a pointer named p, how do you access a value it points to? What is the name of that process?

14) What value is stored in the pointer variable itself?

15) What can you say about a function that has signature void function()?

16) What is an auto keyword?

17) What is function overloading?

18) What is a recursive function?

19) What is the role of a constructor in
a class?

20) How can we change private member variables of a class?

2) How do you create an object file with g++?

3) Why can't you just have eveything in one file?

4) What is the purpose of a "header guard"?

5) What does -IFOLDER_NAME mean when passed to g++?

6) Do tabs matter in a Makefile?

7) What does $@ mean in a Makefile?

8) What does $^ mean in a Makefile?

9) How to use make with a makefile that is not named Makefile?

10) What does it mean if a function is a friend of a class?

11) Why should non-class member operators be friends of classes?

12) Which header do you need to include to work with files?

13) How do you open a file in append mode?

14) How do you allocate a dynamic array in C++?

15) Whats the difference between delete and delete[]?

16) When do you need to overload assignment operator for your class?

17) When do you need to create a copy constructor for your class?

18) When do you need to create a move constructor for your class?

19) What should you do if your class allocates resources, but you are sure you will never need a copy constructor?

20) What are protected class members?

21) What are virtual functions?

22) What is an abstract class?

23) Explain dynamic (runtime) polymorphism

24) Why destructors should be made virtual?

25) What is this [](){}()?

26) What's the general structure of a lambda function?

27) What does "mutable" keyword do in a lambda function?


#### Q-supp

1) What's the main advantage of using templates?

2) Why do people usually put definitions of templated functions directly into .hpp files?

3) Except on types, what else can we template on?

4) What is template specialization?

5) What is a variadic template?

6) Why using push_back for std::vector is a bad idea?

7) How do you pass data from std::vector to a "C-style" function that needs a pointer?

8) Why you shouldn't use a "vector of vectors"?



#### A

1) int, bool, char, double, float, std::string.

2) "int overflow" occurs when we try to store in an int variable a value that is larger than the maximum allowed by the memory assigned to int variables.

3) Because doing so we could be creating conflicts between namespaces. For example, there could be a function with the same name but a different purpose in both the namespace std and another namespace. In that case the compiler won't know which one to use.

4) \<iostream>

5) int main() {}.

6) By default all the members of classes are private, while the members of structs are public.

7) Break interrupts the loop and breaks out of it.

8) Continue skips to the following iteration of the loop.

9) int array_name[7].

10) You can use te function std::cin, followed by >> and the name of the variable in which you want to store the input.

11) It is a way to create an alias, that is a new variable with the same address as the old one (two "labels" for the same chunck of memory). From then on all the changes made to the reference variable are also applied to the original one.

12) When you pass a variable to a function by value all the changes made to the variable inside the function are not propagated out of it, when you pass by reference all the changes are propagated.

13) Because using a variable that was passed by pointer can be confusing, since you have to add & when passing it to the function, you have to add * to refer to the value inside the function, and since it could be hard to distinguish vectors from single variables. Instead passing by reference makes everything easier and clearer, since to pass it you just type the name of the variable, to use it inside the function you just use the plain name, and finally it helps to distinguish single variables from vectors (which are always passed by pointer).

14) You have to use &, in this case: function(&x).

15) Because it makes the code clearer, it raises an error if we wrongly try to change it, and also because it allows the compiler to make the code faster.

16) To access the value you use *p; the process is called dereferencing.

17) The memory address of the variable it points to.

18) I can say that it does not take any arguments as input and that it returns no argument as output.

19) The auto keyword is used in variable declaration to automatically determine the type of the variable.

20) It is when two or more functions have the same name (but different arguments). The compiler will then know which one to call based on the arguments passed to the function.

21) It is a function that contains a call to the function itself. For example, functions to build tree structures are usually recursive.

22) It is used to initialize the class memeber variables. It is called automatically when an instance of the class is created.

23) They can be changed using a class memeber function built for that purpose. In fact you cannot access them using object_name.member_variable, but all the class member functions (and friend functions) can access them.

24) You create it using 'g++ -c script_name.cpp'. It will create a file named script_name.o.

25) Because the file would be very long and messy. Splitting the code in different files allows you to make the project more organized and helps you to find more quickly what you need.

26) The header guard makes the compiler avoid multiple inclusions of the functions declared in the header file.

27) It indicates in which folder to look for the header file. What comes after -I is the path of the directory where the header file is.

28) Yes they do (they cannot be replaced by spaces).

29) Inside a command $@ evaluates the name of the target of that command.

30) Inside a command $^ evaluates the name of all the dependencies of that command (separated by space).

31) When you call make, you can use the option -f followed by the name of the makefile.

32) It means that the function, despite being defined outside the class, can access its private member variables.

33) Because in this way they can access the private members of the class.

34) \<fstream>.

35) variable_name.open("file_name", std::ios_base::app).

36) data_type* array_name=new data_type[size].

37) delete is used to free memory allocated for "single value" variables, while delete[] is used to free memory allocated for arrays.

38) When you have pointers in the class and you want to use the assignment operator for class instances. If you have pointers in your class but you don't want the assignment operator to be used, you should put =delete after its declaration, so that whoever will try to use it will get an error.

39) When you have pointers in your class and you want to pass instances of your class to a function by value. If you have pointers in your class but you don't want instances of the class to be passed by value, you should put =delete after the declaration of the copy constructor, so that whoever will try to do it will get an error.

40) When you have pointers in your class and you want to move instances of your class using std::move.

41) You should put =delete after the declaration of the copy constructor inside the class, so that whoever will try to use it will get an error.

42) They are the same as private class memebers (i.e. they cannot be accessed from outside the class, unless a class member function or a friend function is used) but they can be accessed by derived classes.

43) They are functions that can be overridden in derived classes.

44) It is a class that contains at least one pure virtual function. It cannot be instantiated, but it can be used as a base class for inheritance. If in the derived class the pure virtual functions are not overridden, then the derived class is abstract too.

45) In c++ pointers to base class are type compatible with derived class. This means that you can use a pointer to a base class to point to an object of a derived class. This is called dynamic polymorphism.

46) In dynamic polymorphism, if the base class destructor is not made virtual and then overridden in the derived class, then only the base class destructor will be called. This could lead to memory leaks. Making it virtual and overriding it, insted, makes sure that the derived class destructor is called before calling the base class one.

47) It defines a function without a name  that does nothing. It is the simplest lambda function possible.

48) \[CAPTURES]\(PARAMETERS)->return_type{ISTRUCTIONS}(), where CAPTURES are variables in the outer scope automatically "captured" by the function when defined and PARAMETERS are variables that are passed "manually" when the function is called.

49) It allows the lambda function to change the values of variables that were captured by value.


#### A-supp

1) Using templates you can write more flexible code. In fact you can write templated functions, which can manipulate parameters of different types depending on what you pass to them, and templated classes, which can have memebers of different types depending on how you instantiate them.

2) The compiler needs to instantiate the templates at compile time. If you split the definition of the templates from their declaration, then, when compiling the file with the definitions, the compiler is not able to instantiate the templates unless you declare all the instances that you will call in the main code. This can make templates useless. The easiest way to solve this issue is to put directly the definitions of the templates in the header file.

3) On integers.

4) Is a way to write functions that have different bodies depending on the type of the parameters you pass to them.

5) It is a kind of template to which you can pass a variabe number of arguments of any type (not necessarely all of the same type). This kind of template requires the definition of a "basic" function (taking a fixed number of arguments) and a "general" function taking an indefinite number of arguments, the latter built with a recursive structure.

6) Because if the previously allocated memory is not large enough, internally it allocates a new larger space in the heap and copies all the elements of the old vector in it. This operation can be extremely slow.

7) If v is the std::vector, then you can use &v[0].

8) Because in that way the operation of accessing to a single element can become very very slow. A more efficient way of storing "matrix-like" data structures is using a single vector in which you store all the data in a single row, so that the memory is allocaed contiguously and the element access is much faster.