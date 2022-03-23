#include <iostream>
#include <string>
#include <vector>
#include "cafe.h"

int main()
{
    cafe theCafe;
    theCafe.Calculate(0, 5, 50); //test 1 - can purchase
    
    theCafe.Calculate(3, 2, 1); //test 2 - cannot purchase
    theCafe.Calculate(5, 50, 230.75); //test 3 - most returned with lowest amount possible
    theCafe.Calculate(7, 4, 35.42); //test 4
}