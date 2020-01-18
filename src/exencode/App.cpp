

#include <iostream>
#include <exencode/exencode.h>
#include <CLI11.hpp>

#ifndef PLATFORM
    #define PLATFORM "NO SYSTEM NAME"
#endif

auto sum(int a, int b) {
    return a + b;
}


int main()
{
    
    std::cout << PLATFORM;

    std::cout << "x";

    std::cout << "Hello World!\n";
}
