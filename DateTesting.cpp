#include <iostream>
#include "Date.h"
using namespace std;

void testConstructor();
void testAddOperators();
void testExtractionOperators();
bool checkCase(string name, bool condition);

template<class Type>
bool checkCase(const string &name, const Type &is, const Type &shouldBe);
int main()
{
    cout << "Date Class Testing!" << endl;
    testConstructor();
    testAddOperators();
    testExtractionOperators();
    return 0;
}

void testConstructor()
{
    checkCase("One Argument Constructor Month", Date(2024).getDay() ,1);
	checkCase("One Argument Constructor Day", Date(2024).getMonth() ,1);
	checkCase("One Argument Constructor Year", Date(2024).getYear() , 2024);
	
    checkCase("Two Argument Constructor Day", Date(2024).getDay() ,1);
	checkCase("Two Argument Constructor Month", Date(2024).getMonth() , 1);
	checkCase("Two Argument Constructor Year", Date(2024).getYear() ,2024);

}
void testAddOperators(){
    Date dd(2024, 9, 10);
    Date d = dd;

    d = dd; 
	checkCase("Operator+ test 1 Day", (d + 23).getDay() , 3);
	checkCase("Operator+ test 1 Month", (d + 23).getMonth() , 10);
	checkCase("Operator+ test 1 Year", (d + 23).getYear() , 2024);
	
	
    d = dd; 
	checkCase("Operator+ test 2 Day", (d + 38).getDay() , 18);
	checkCase("Operator+ test 2 Month", (d + 38).getMonth() , 10);
	checkCase("Operator+ test 2 Year", (d + 38).getYear() , 2024);
	
    d = dd; 
	checkCase("Operator+ test 3 Day", (d + 56).getDay() , 5);
	checkCase("Operator+ test 3 Month", (d + 56).getMonth() , 11);
	checkCase("Operator+ test 3 Year", (d + 56).getYear() , 2024);
	
    d = dd; 
	checkCase("Operator+ test 4 Day", (d + 91).getDay() , 10);
    checkCase("Operator+ test 4 Month", (d + 91).getMonth() , 12);
	checkCase("Operator+ test 4 Year", (d + 91).getYear() , 2024);
	
	d = dd; 
	checkCase("Operator+ test 5", (d + 134).getDay() , 22);
	checkCase("Operator+ test 5", (d + 134).getMonth() , 1);
	checkCase("Operator+ test 5", (d + 134).getYear() , 2025);
}

void testExtractionOperators(){
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;

    checkCase("Text Extraction Operator", sout.str() , string("Sep 10, 2018"));
}
bool checkCase(string name, bool condition)
{
    if(!condition)
    {
        cout << "Failed: " << name << endl;
    }
    else{
        cout << name << ": passed" << endl;
    }

    return condition;
}

template<class Type>
bool checkCase(const string &name, const Type &is, const Type &shouldBe){
	if(is == shouldBe){
		cout << name << ": passed" << endl;
		return true;
	}
	else{
		cout << name << ": failed... was " << is << " should be " << shouldBe << endl;
	}
	return false;
}