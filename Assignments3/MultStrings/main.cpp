#include <iostream>
#include <string>
#include <ostream>

using std::cout;
using std::endl;
using std::string;

class TheSolution
{
    public:
        string multiply(string num1, string num2)
        {
            if(num1 == "0" || num2 == "0")
            {
                return "0";
            }

            string Display = "";

            for(int i = 0; i < num1.length(); i++)
            {
                Display += "0";
            }

            for(int i = 0; i < num2.length(); i++)
            {
                Display += "0";
            }

            for(int i = num1.length() - 1; i >= 0; --i)
            {
                int zero = 0;
                for(int j = num2.length() - 1; j >= 0; --j)
                {
                    int position = i + j + 1;
                    int value = (num1[i] - '0') * (num2[j] - '0') + zero + (Display[position] - '0');

                    Display[position] = (value % 10) + '0';
                    position--;
                    while(zero)
                    {
                        int v = (Display[position] - '0') + zero;
                        Display[position] = (v % 10) + '0';
                        zero = v / 10;
                        position--;
                    }
                }
            }

            int l = 0;

            for(; l < Display.length(); l++)
            {
                if(Display[l] != '0')
                {
                    break;
                }
            }

            return Display.substr(l, Display.length() -1);
        }
};

int main()
{
    TheSolution ts = TheSolution();

    cout << ts.multiply("2", "3") << endl;
}