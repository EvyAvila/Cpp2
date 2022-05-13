#include "parser.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
//#include <random>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::reverse;
using std::set;

FoodInspect::FoodInspect() {}

void FoodInspect::DisplayInspection()
{
    //Some things are hardcoded for doing overcomplicated items. Would definitely try to fix it 
    //to make it more optimal.
    InsertTestData();

    cout << "\n~~~~~ General Display ~~~~~" << endl;
    for(int i = 0; i < Date.size(); i++)
    {
        _Values(Date[i], Name[i], Zip[i], _Results[i]); //To display the data
    }   

    cout << "\n~~~~~ Analysis 1: Number of failed inspections in each Zip code ~~~~~" << endl;
    
    AnalysisA();

    cout << "\n~~~~~ Analysis 2: Order descending ~~~~~" << endl;
    
    AnalysisB();

    cout << "\n~~~~~ Analysis 3: Date descending ~~~~~" << endl;

    AnalysisC();
}


void FoodInspect::InsertTestData()
{
    Date.push_back(10062021);
    Name.push_back("TAMALERIA LUPITA");
    Zip.push_back(60638);
    _Results.push_back(Fail);

    Date.push_back(4082022);
    Name.push_back("Nick JR.'s GRILL");
    Zip.push_back(60707);
    _Results.push_back(Fail);

    Date.push_back(3182022);
    Name.push_back("MARISCOS EL OCEANO");
    Zip.push_back(60638);
    _Results.push_back(Fail);

    Date.push_back(3252022);
    Name.push_back("FAIRGROUNDS");
    Zip.push_back(60647);
    _Results.push_back(Fail);

    Date.push_back(3312022);
    Name.push_back("FIVE IRON GOLF");
    Zip.push_back(60642); 
    _Results.push_back(Fail);

    Date.push_back(4082022);
    Name.push_back("WINGSTOP");
    Zip.push_back(60642);
    _Results.push_back(Fail);

    Date.push_back(1042022);
    Name.push_back("PODHANKA RESTAURANT");
    Zip.push_back(60642);
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
    }
}



void FoodInspect::AnalysisA()
{
    for(int it = 0; it < Zip.size(); it++)
    {
        sort(Zip.begin(), Zip.end());
        if(std::count(Zip.begin(), Zip.end(), Zip[it]) != it + 1)
        {
            cout << "The zip code - " << Zip[it]; 
            NumberOfFailed = std::count(Zip.begin(), Zip.end(), Zip[it]);
            cout << " failed inspections " << NumberOfFailed << "x" << endl;

        }
    }
}

void FoodInspect::AnalysisB()
{   
    vector <int> FailedNum;

    for(int i = 0; i < Zip.size(); i++)
    {
        sort(Zip.begin(), Zip.end());
        if(std::count(Zip.begin(), Zip.end(), Zip[i]) != i + 1)
        {
            FailedNum.push_back(std::count(Zip.begin(), Zip.end(), Zip[i]));
            sort(FailedNum.begin(), FailedNum.end());
            reverse(FailedNum.begin(), FailedNum.end());
              
        }

    }
    
    for(int j = 0; j < FailedNum.size(); j++)
    {
        cout << FailedNum[j] << endl;
    }
}

void FoodInspect::AnalysisC()
{
    vector<int> ArrA;
    vector<int> ArrB;
    vector<int> ArrC;
    vector<int> ArrD;
    
    
    ArrA.push_back(Date[0]);
    ArrA.push_back(Date[2]);

    ArrB.push_back(Date[1]);

    ArrC.push_back(Date[3]);

    ArrD.push_back(Date[4]);
    ArrD.push_back(Date[5]);
    ArrD.push_back(Date[6]);

    sort(ArrD.begin(), ArrD.end());
    for(int i= 0; i < ArrD.size(); i++)
    {
        cout << ArrD[i] << endl;
    }

    sort(ArrA.begin(), ArrA.end());
    for(int i =0; i < ArrA.size(); i++)
    {
        cout << ArrA[i] << endl;
    }


    for(int i =0; i < ArrB.size(); i++)
    {
        cout << ArrB[i] << endl;
        cout << ArrC[i] << endl;
    }

    
}

void FoodInspect::_Values(int date, string name, int zip, Result r)
{
    
    cout << date << " - " << name << " - "<< zip << ": ";
    ShowResult(r);
}




