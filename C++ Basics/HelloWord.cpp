#include<iostream>//heaher files 

/*
* what are header files
* These are the files containing pre-defined classes and structures which we can use in 
* other programs by just include them using #include directive.
*
*/

//Main function - its a function from where our program's execution takes place 
int main()
{
  // "std" is _namespace 
  //namespace ? namespace is a region that provides a scope to the identifiers (the names of types, functions, variables, etc) inside it.
  // :: this is scoperesolution operator and its finding cout's scope in std ?
  std::cout<<"helloWold!"<<std::endl;
}
/*
std Namespace: The std namespace is part of the C++ Standard Library. It contains all the standard C++ library functions and classes, including things like input/output (cout, cin), strings, vectors, algorithms, etc.


What is the Scope Resolution Operator ::?

Scope Resolution Operator (::): This operator is used to specify the scope of a name. In other words, it tells the compiler where to look for an identifier.

Using :: with std: When you write std::cout, you're telling the compiler to look for cout within the std namespace. This is necessary because cout is not defined in the global scope; it's defined within the std namespace.

*/