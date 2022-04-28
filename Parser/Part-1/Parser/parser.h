#ifndef PARSER_H
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
//Any other includes if needed

enum Result {Pass, Fail, No_Entry, Out_of_Business, Pass_with_condtions, Not_Ready};

class FoodInspect
{
    public:
        FoodInspect();

        void DisplayInspection();

        void ShowResult(Result r);

        void Values(int id, string name, Result r);
        
        vector<int> Identification; 
        vector<string> Name;
        vector<Result> _Results;

        void InsertTestData();
};


#endif