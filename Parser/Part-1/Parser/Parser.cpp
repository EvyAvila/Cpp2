#include "parser.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

FoodInspect::FoodInspect() {}

void FoodInspect::DisplayInspection()
{
    InsertTestData();

    for(int i = 0; i < Identification.size(); i++)
    {
        Values(Identification[i], Name[i], _Results[i]);
    }   
}


void FoodInspect::InsertTestData()
{
    //id number
    Identification.push_back(2554375);
    Identification.push_back(2554085);
    Identification.push_back(2553403);
    Identification.push_back(2546873);
    Identification.push_back(2545887);

    //Name
    Name.push_back("St. Joseph Hospital");
    Name.push_back("Nick jr.Grill");
    Name.push_back("JJ Fish");
    Name.push_back("Sizzling Pot King");
    Name.push_back("Best Bar");
    
    //result of inspection
    _Results.push_back(Pass);
    _Results.push_back(Fail);
    _Results.push_back(Pass);
    _Results.push_back(Out_of_Business);
    _Results.push_back(Fail);
}



void FoodInspect::ShowResult(Result res)
{
    switch(res)
    {
        case Pass:
            cout << "Pass" << endl;
            break;
        case Fail:
            cout << "Fail" << endl;
            break;
        case No_Entry:
            cout << "No Entry" << endl;
            break;
        case Out_of_Business:
            cout << "Out of business" << endl;
            break;
        case Pass_with_condtions:
            cout << "Pass with conditions" << endl;
            break;
        case Not_Ready:
            cout << "Not Ready" << endl;
            break;
    }
}

void FoodInspect::Values(int num, string name, Result r)
{
    cout << num << " - " << name << ": ";
    ShowResult(r);
}




