# Implemented-BigInt-CPP-Library

#### Contents

* [Overview](#overview)
* [Functionalities](#functionalities)
* [Features](#features)
* [Installation](#installation)
* [Contributing](#contributing)
* [License](#license)

## Overview
BigInt is a header-only C++ library that provides **`arbitrary-precision integer arithmetic`**, allowing users to perform arithmetic operations on integers of practically unlimited size. This library is designed to be easy to use, efficient, and suitable for a wide range of applications where standard integer types are insufficient due to their limited range.
### Creating a BigInt library for C++ would offer several benefits:

--> Simplicity: Developers won't have to reinvent the wheel for handling large integers, simplifying code and reducing potential bugs.

--> Portability: Having a standardized BigInt library would ensure compatibility across different platforms and environments.

--> Performance: While performance might not match low-level C++ operations, a well-designed BigInt library can still provide acceptable performance for many use cases.

--> Applications: A BigInt library would be invaluable for **`cryptography, big data processing, numerical simulations`**, and any other application requiring precise arithmetic with large integers.

## Functionalities
### Operators

* #### Assignment: `=`

  The second operand can either be a `BigInt`, an integer (up to `long long`)
  or a string (`std::string` or a string literal).

  ```c++
  big1 = 1234567890;
  big1 = "123456789012345678901234567890";
  big1 = big2;
  ```

* #### Binary arithmetic: `+`, `-`, `*`, `/`, `%`

  One of the operands has to be a `BigInt` and the other can be a `BigInt`, an
  integer (up to `long long`) or a string (`std::string` or a string literal).

  ```c++
  big1 = big2 + 1234567890;
  big1 = big2 - "123456789012345678901234567890";
  big1 = big2 * big3;
  big1 = 1234567890 / big2;
  big1 = "123456789012345678901234567890" % big2;
  ```

* #### Arithmetic-assignment: `+=`, `-=`, `*=`, `/=`, `%=`

  The second operand can either be a `BigInt`, an integer (up to `long long`)
  or a string (`std::string` or a string literal).

  ```c++
  big1 += big2;
  big1 -= 1234567890;
  big1 *= "123456789012345678901234567890";
  big1 /= big2;
  big1 %= 1234567890;
  ```

* #### Increment and decrement: `++`, `--`

  ```c++
  big1 = ++big2;   // pre-increment
  big1 = --big2;   // pre-decrement

  big1 = big2++;   // post-increment
  big1 = big2--;   // post-decrement
  ```

* #### Relational: `<`, `>`, `<=`, `>=`, `==`, `!=`

  One of the operands has to be a `BigInt` and the other can be a `BigInt`, an
  integer (up to `long long`) or a string (`std::string` or a string literal).

  ```c++
  if (big1 < 1234567890
      or big1 > "123456789012345678901234567890"
      or big1 <= big2
      or 1234567890 >= big1
      or "123456789012345678901234567890" == big1
      or big1 != big3) {
      ...
  }
  ```

* #### I/O stream: `<<`, `>>`

  ```c++
  std::cout << big1 << ", " << big2 << "\n";
  output_file << big1 << ", " << big2 << "\n";

  std::cin >> big1 >> big2;
  input_file >> big1 >> big2;
  ```

### Functions

* #### Math

  * #### `pow`

    ```c++
    big1 = big1^5000;  
    ```

  * #### `sqrt`

    Get the integer square root of a `BigInt`.

    ```c++
    big1 = sqrt(big2);
    ```
### Computing Methods

 * #### `NthCatalan`
 - Generate the Catalan series upto a predefined integer number.

    ```c++
    for (int i = 0; i <= 100; i++)
    {
        BigInt Cat;
        Cat = NthCatalan(i);
        cout << "Catalan " << i << ": " << Cat << '\n';
    }  
    ```
    
 * #### `NthFibonacci`
 - Generate the Fibonacci series upto a predefined integer number.

    ```c++
    for (int i = 0; i <= 100; i++)
    {
        BigInt Fib;
        Cat = NthFibonacci(i);
        cout << "Fibonacci " << i << ": " << Fib << '\n';
    }  
    ```
 * #### `Factorial`
 - Computes factorial of a given integer. 

    ```c++
    for (int i = 0; i <= 100; i++)
    {
        BigInt fact;
        fact = Factorial(i);
        cout << "Factorial of "
             << i << ": ";
        cout << fact << '\n';
    }
    ```
    
## Features
1) Arbitrary Precision: Perform arithmetic operations on integers of any size, limited only by available memory.
2) Header-Only: No need for compilation or linking; simply include the header file in your project to start using BigInt.
3) Efficient: Optimized algorithms for arithmetic operations to ensure high performance.
4) Intuitive Interface: Simple and intuitive interface similar to built-in integer types in C++, making it easy to integrate BigInt into existing codebases.
5) Tested: Thoroughly tested with a comprehensive suite of test cases to ensure correctness and reliability.

## Installation
To use BigInt Library in your project, simply download the **`"bigint.h"`** header file from this GitHub repository and include it in your project. No additional installation steps are required.
Make sure to add a valid relative path in the include statement.

## Contributing
Contributions to BigInt are welcome! Whether you find a bug, have a feature request, or want to contribute code, please feel free to open an issue or submit a pull request on the GitHub repository.

## License
This project is licensed under the MIT License, allowing for both personal and commercial use with minimal restrictions.
