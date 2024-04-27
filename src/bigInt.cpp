#include "include\bigInt\bigInt.h"

int main()
{
    BigInt first("9876543210");
    cout << "The number of digits"
         << " in first big integer are: "
         << length(first) << '\n';
    BigInt second(987654);
    if (first == second)
    {
        cout << "First and Second are equal!\n ";
    }
    else
        cout << "NOT EQUAL!\n";

    BigInt third("56785345897738");
    BigInt fourth("56785345897731");
    if (third < fourth)
    {
        cout << "Third is smaller than Fourth!\n";
    }
    BigInt fifth("56785345897744");
    if (fifth > fourth)
    {
        cout << "Fifth is larger than Fourth!\n";
    }

    // Printing all the numbers
    cout << "First = " << first << '\n';
    cout << "Second = " << second << '\n';
    cout << "Third = " << third << '\n';
    cout << "Fourth = " << fourth << '\n';
    cout << "Fifth = " << fifth << '\n';

    // Incrementing the value of first
    first++;
    cout << "After incrementing the"
         << " value of first is: ";
    cout << first << '\n';
    BigInt sum;
    sum = (fourth + fifth);
    cout << "Sum of fourth and fifth is: "
         << sum << '\n';
    BigInt product;
    product = second * third;
    cout << "Product of second and third: "
         << product << '\n';

    // Print the fibonacci number from 1 to 100
    cout << "-------------------------Fibonacci Sequence (1-100)"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        BigInt Fib;
        Fib = NthFibonacci(i);
        cout << "Fibonacci " << i << ": " << Fib << '\n';
    }
    cout << "-------------------------Catalan Series (1-100)"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        BigInt Cat;
        Cat = NthCatalan(i);
        cout << "Catalan " << i << ": " << Cat << '\n';
    }

    // Calculating factorial of from 1 to 100
    cout << "-------------------------Factorial (1-100)"
         << "------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        BigInt fact;
        fact = Factorial(i);
        cout << "Factorial of "
             << i << ": ";
        cout << fact << '\n';
    }

    return 0;
}
