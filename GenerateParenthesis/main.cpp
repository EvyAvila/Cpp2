#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution
{
    public:
        vector<string> Answer;
        void Generate(int openP, int closedP, const string &parenth)
        {
            if(openP == 0 && closedP == 0)
            {
                Answer.push_back(parenth);
                return;
            }

            if(openP > 0)
            {
                Generate(openP-1, closedP, parenth + "(");
            }

            if(openP < closedP)
            {
                Generate(openP, closedP-1, parenth + ")");
            }
        }

        vector<string> generateParenthesis(int n)
        {
            Generate(n, n, "");
            return Answer;
        };
};

int main()
{
    Solution ts = Solution();

    int n = 3;

    ts.generateParenthesis(n);

    cout << n << endl;
    for(auto s: ts.Answer)
    {
        cout << s << endl;
    }
}