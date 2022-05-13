#ifndef PARSER_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::reverse;
using std::set;
//Any other includes if needed

enum Result {Pass, Fail};

template <class T> set<T> dedup(vector<T> &&vect)
        {
            set<T> s(vect.begin(), vect.end());
            vect.assign(s.begin(), s.end());
            return std::move(s);
        }

class FoodInspect
{
    public:
        FoodInspect();

        void DisplayInspection();

        void ShowResult(Result r);

        void _Values(int date, string name, int zip, Result r);
        
        vector<string> Name; 
        vector<Result> _Results; 

        vector<int> Date;
        vector<int> Zip;



        void InsertTestData();

        void AnalysisA(); 
        void AnalysisB();
        void AnalysisC();

        int NumberOfFailed;

        
};


#endif