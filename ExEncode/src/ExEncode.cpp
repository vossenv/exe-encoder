

#include <iostream>
#include "../include/exencode/exencode.h"

#ifndef CMAKEMACROSAMPLE
    #define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

auto sum(int a, int b) {
    return a + b;
}


int main()
{
    
    std::cout << CMAKEMACROSAMPLE;

    std::cout << "x";

    std::cout << "Hello World!\n";
}
