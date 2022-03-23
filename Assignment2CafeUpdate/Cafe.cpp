#include "cafe.h"
#include <iostream>
#include <string>
#include <vector>

cafe::cafe() { }

void cafe::DisplayMenu()
{
    for(int i = 0; i < TheItemName.size(); i++)
    {
        int DisplayNumber = i + 1;
        std::cout << DisplayNumber << ". " << TheItemName[i] << " cost: $" << TheItemPrice[i] << std::endl;
    }
}

void cafe::Calculate(int itemType, int quantity, double money)
{

    std::cout << cafe::TheItemName[itemType] << " cost: $" << cafe::TheItemPrice[itemType] << ". The quantity is: "<< quantity << std::endl;

    std::cout << "You have: $" << money << std::endl;

    cafe::TheTotalCost = TheItemPrice[itemType] * quantity;

    std::cout << "Total cost is: $" << TheTotalCost << std::endl;
    

    if(money < TheTotalCost)
    {
        std::cout << "Not enough to purchase" << std::endl;
    }
    else
    {
        std::cout << "You can purchase" << std::endl;

        cafe::TheReturnChange = money - TheTotalCost;
        
        std::cout << "Return change is: $" << TheReturnChange << std::endl;
        ReturnLowestAmount(TheReturnChange);
    }

    Split();
}

void cafe::ReturnLowestAmount(double returnAmount)
{
    int MoneyReturned;

    MoneyReturned = returnAmount*100;

    if(MoneyReturned >= 10000)
    {    
    std::cout << "Returned " << MoneyReturned/10000 << ": $100" << std::endl;
    MoneyReturned = MoneyReturned % 10000;
    }

    if(MoneyReturned >= 5000)
    {
    std::cout << "Returned " << MoneyReturned/5000 << ": $50" << std::endl;
    MoneyReturned = MoneyReturned % 5000;
    }

    if(MoneyReturned >= 2000)
    {
    std::cout << "Returned " << MoneyReturned/2000 << ": $20" << std::endl;
    MoneyReturned = MoneyReturned % 2000;
    }

    if(MoneyReturned >= 1000)
    {
    std::cout << "Returned " << MoneyReturned/1000 << ": $10" << std::endl;
    MoneyReturned = MoneyReturned % 1000;
    }

    if(MoneyReturned >= 500)
    {
    std::cout << "Returned " << MoneyReturned/500 << ": $5" << std::endl;
    MoneyReturned = MoneyReturned % 500;
    }

    if(MoneyReturned >= 200)
    {
    std::cout << "Returned " << MoneyReturned/200 << ": $2" << std::endl;
    MoneyReturned = MoneyReturned % 200;
    }

    if(MoneyReturned >= 100)
    {
    std::cout << "Returned " << MoneyReturned/100 << ": $1" << std::endl;
    MoneyReturned = MoneyReturned % 100;
    }

    if(MoneyReturned >= 25)
    {
    std::cout << "Returned " << MoneyReturned/25 << ": $0.25"<< std::endl;
    MoneyReturned = MoneyReturned % 25;
    }

    if(MoneyReturned >= 10)
    {
    std::cout << "Returned " << MoneyReturned/10 << ": $0.10" << std::endl;
    MoneyReturned = MoneyReturned % 10;
    }

    if(MoneyReturned >= 5)
    {
    std::cout << "Returned " << MoneyReturned/5 << ": $0.05" << std::endl;
    MoneyReturned = MoneyReturned % 5;
    }

    if(MoneyReturned >= 1)
    {
    std::cout << "Returned " << MoneyReturned/1 << ":$0.01" << std::endl;
    }
}