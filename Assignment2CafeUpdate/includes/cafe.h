#ifndef CAFE_H
#include <iostream>
#include <string>
#include <vector>

class cafe
{
    public:
        cafe();

        double TheTotalCost;
        double TheReturnChange;

        std::vector<std::string> TheItemName = {"Expresso", "Latte", "Donut", "Cake Pops", "Vegan Sandwich", "Ham Sandwich", "Tomato Soup", "Broccoli Soup"};
        std::vector<double> TheItemPrice = {9.15, 6.75, 3.15, 1.05, 4.50, 4.25, 2.10, 2.35};
        
        void DisplayMenu();
        void Calculate(int itemType, int quantity, double money);
        void ReturnLowestAmount(double returnAmount);
        
        void Split()
        {
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }
};


#endif