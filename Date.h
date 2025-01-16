#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
  int getDay() const { return day; }
  int getMonth() const { return month; }
  int getYear() const { return year; }
  
  Date(int y): year(y), 
               month(1), 
               day(1) {}
               
  Date(int y, 
       int m, 
       int d): 

  year(y), month(m), day(d){}

  Date(int y, int m): year(y), 
                      month(m), 
                      day(1){

                      }


  Date& addMonths(int n){

    year  += (month + n) / 12;
    month = (month + n) % 12;
    
    return *this;


  }

  Date& addDays(int n) {

    int d = daysToDate() + n;

    int y = year, m = 1;

    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }

    day = d;
    month = m;
    year = y;

    return *this;
  }


  static bool isLeapYear(int y) {
    return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
  }

  string toString() {
    stringstream ss;
    
    ss << year << "/" 
               << (month < 10 ? "0" : "") 
               << month 
               << "/" 
               << (day < 10 ? "0" : "") << day;
    
    return ss.str();

  }


  int daysToDate(){
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;

    for(int m = 0; m < month - 1; m++){
      days += days_in_month[m];
    }
    days += day;
    return days;
  }

  Date operator+(int n) {
    Date newDate = *this;
    newDate.addDays(n);
    return newDate;
  }

 friend ostream& operator<<(ostream& os, const Date& date) {

    static const char* monthsName[] = {"Jan", 
                                        "Feb", 
                                        "Mar", 
                                        "Apr", 
                                        "May", 
                                        "Jun", 
                                        "Jul", 
                                        "Aug", 
                                        "Sep", 
                                        "Oct", 
                                        "Nov", 
                                        "Dec"};

    os << monthsName[date.month - 1] << date.day << "," << date.year;
    return os;
  }

  

private:
  int year, month, day;

  static int daysInMonth(int y, int m){
    
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};

    return days_in_month[m - 1];

  }
};