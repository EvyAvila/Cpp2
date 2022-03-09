#include <vector>
#include <iostream>
#include <string>
#include <ostream>

class TheSolution
{
    public:
        std::vector<std::string> res;

        void Map(std::string digits, int number, std::string letter)
        {
            if(number >= digits.length())
            {
                res.push_back(letter);
                return;
            }

            switch(digits[number])
            {
                case '2':
                    Map(digits, number + 1, letter+'a');
                    Map(digits, number + 1, letter+'b');
                    Map(digits, number + 1, letter+'c');
                    break;
                case '3':
                    Map(digits, number + 1, letter+'d');
                    Map(digits, number + 1, letter+'e');
                    Map(digits, number + 1, letter+'f');
                    break;
                case '4':
                    Map(digits, number + 1, letter+'g');
                    Map(digits, number + 1, letter+'h');
                    Map(digits, number + 1, letter+'i');
                    break;
                case '5':
                    Map(digits, number + 1, letter+'j');
                    Map(digits, number + 1, letter+'k');
                    Map(digits, number + 1, letter+'l');
                    break;
                case '6':
                    Map(digits, number + 1, letter+'m');
                    Map(digits, number + 1, letter+'n');
                    Map(digits, number + 1, letter+'o');
                    break;
                case '7':
                    Map(digits, number + 1, letter+'p');
                    Map(digits, number + 1, letter+'q');
                    Map(digits, number + 1, letter+'r');
                    Map(digits, number + 1, letter+'s');
                    break;
                case '8':
                    Map(digits, number + 1, letter+'t');
                    Map(digits, number + 1, letter+'u');
                    Map(digits, number + 1, letter+'v');
                    break;
                case '9':
                    Map(digits, number + 1, letter+'w');
                    Map(digits, number + 1, letter+'x');
                    Map(digits, number + 1, letter+'y');
                    Map(digits, number + 1, letter+'z');
                    break;
                default: return Map(digits, number++, letter);
            }

            return;
        }

        std::vector<std::string> letterCombination(std::string digits)
        {
            if(digits.size() == 0)
            {
                return res;
            }

            std::string theLetters = "";
            int theNumber = 0;
            Map(digits, theNumber, theLetters);
            return res;
        }
};

int main()
{
    std::cout << "Display all possible outcome" << std::endl;
    
    TheSolution ts = TheSolution();  
    std:: string InsertNumber = "52"; //Can change number from here
    
    ts.res.push_back(InsertNumber);
    for(std::string i: ts.letterCombination(InsertNumber))
    {
        std::cout << i << std::endl;
    }
}