Assignment 5: Inheritance and Polymorphism
In this assignment, you will use concepts of inheritance and polymorphism in C++ to implement simple arithmetic expression trees.

Download and study the given header file "Expression.h". This defines an abstract base class that represents the interface to all expression trees. In this assignment, you will be defining subclasses that implement this interface. At minimum, these subclasses should provide definition for "eval" and "print" functions (unless they are abstract classes themselves).

Design a type hierarchy, with "Expression" at the top, that represents a set of simple arithmetic expressions. The operations in this set include binary operations such as addition, subtraction, multiplication, and division over real numbers (which you may represent using floats in C++), as well as the negation operation. For example, you should be able to represent an expression such as "(3.0 + 4) * -(5.0)".

Hints: Think about the following: What are the common characteristics or behaviors among different expressions? What are the differences? Which functions/fields should be inherited, and which should be implemented separately?

Implement the methods "eval" and "print". The "eval" method evaluates the expression and returns the resulting float. For example, the expression "(3.0 + 4) * -(5.0)" should return -35.0. The "print" method should print the raw (i.e. unevaluated) expression in the infix notation.

Write test cases to show that your methods work correctly. Include your test cases in "test_expression.cc".

Answer the following questions, and put your responses in a text file called "answers.txt":

5.1. Let us suppose that we want to add an extra operation "exponentiation" that takes a base expression and an exponent. How would you modify/extend your type hierarchy to do this?

5.2. This time, we want to add an operation "sum" that takes an arbitrary list of reals and add them together. How would modify/extend your type hierarchy? Why?

5.3. Does your design allow invalid or undefined mathematical expressions? Why or why not?

Submit all of your files (*.h, *.cc, answers.txt) in a compressed .zip or .tar.gz file, along with a README describing (1) the command(s) you used to compile your program and (2) the command(s) you used to test your program. If you choose to include tests, you should also describe them. If you used a Makefile, please include that as well.