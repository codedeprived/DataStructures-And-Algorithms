#include<iostream>

//i know why revisit and write basic code that i done years ago 
// and probably i should have done this then only but gotta start somewhere i think

// now we wrote int before main() ? why 
// int is a data type , but why we wrote int before main.

// int c++ whenever we make a function we implicily tell what should be returned by the function
// what is a function ? 

/*
 Funtions is just same function we studied in out maths class which is a relationship between input and output , function take an input and provides output 
*/

// now what is int ? 

// int is a data type , which as you might tell my name (data type ) tells what type of
// data we are dealing with , here is this case we are dealing with int (integer) -infinity to infinity without decimals. eg -1 , 0 , 1 .... so on. we have mutiliple data types in c++


#include <iostream>
#include <limits> // To use numeric_limits for precise ranges

int main()
{
    // int: Integer type, typically 4 bytes (32 bits) in size.
    // Range: -2,147,483,648 to 2,147,483,647
    int a;

    // float: Floating-point type for decimal numbers, typically 4 bytes (32 bits).
    // Range: Approximately 1.2E-38 to 3.4E+38 (6-7 decimal digits of precision)
    float b;

    // double: Double-precision floating-point type, typically 8 bytes (64 bits).
    // Range: Approximately 2.3E-308 to 1.7E+308 (15-16 decimal digits of precision)
    double c;

    // char: Character type, 1 byte (8 bits) in size.
    // Range: -128 to 127 or 0 to 255 (depends on signed/unsigned)
    char d;

    // bool: Boolean type, usually 1 byte in size.
    // Range: true (1) or false (0)
    bool e;

    // short: Short integer type, typically 2 bytes (16 bits).
    // Range: -32,768 to 32,767
    short f;

    // long: Long integer type, typically 4 bytes (32 bits).
    // Range: -2,147,483,648 to 2,147,483,647
    long g;

    // long long: Long long integer type, typically 8 bytes (64 bits).
    // Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    long long h;

    // unsigned int: Unsigned integer type, typically 4 bytes (32 bits).
    // Range: 0 to 4,294,967,295
    unsigned int i;

    // unsigned char: Unsigned character type, 1 byte (8 bits) in size.
    // Range: 0 to 255
    unsigned char j;

    // unsigned short: Unsigned short integer type, typically 2 bytes (16 bits).
    // Range: 0 to 65,535
    unsigned short k;

    // unsigned long: Unsigned long integer type, typically 4 bytes (32 bits).
    // Range: 0 to 4,294,967,295
    unsigned long l;

    // unsigned long long: Unsigned long long integer type, typically 8 bytes (64 bits).
    // Range: 0 to 18,446,744,073,709,551,615
    unsigned long long m;

    // wchar_t: Wide character type, size depends on the platform (usually 2 or 4 bytes).
    // Range: 0 to 65,535 or wider (platform-dependent)
    wchar_t n;

    // long double: Extended precision floating-point type, typically more than 8 bytes.
    // Range: Greater range and precision than double (varies by platform, often 10, 12, or 16 bytes)
    long double o;

    return 0;
}
