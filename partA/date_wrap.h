#ifndef DATE_WRAP_H_
#define DATE_WRAP_H_
#include "exceptions.h"
#include <iostream>
extern "C" { 
    #include "date.h"
}

using std::ostream;


#define MIN_DAY 1
#define MAX_DAY 30
#define MIN_MONTH 1
#define MAX_MONTH 12

namespace mtm {
    class DateWrap{
            Date date;
            int tday, tmonth, tyear; 

        public:
            DateWrap(int in_day, int in_month, int in_year);
            DateWrap(const DateWrap& date1);
            ~DateWrap();
            int day();
            int month();
            int year();
            DateWrap& operator+=(const int days);
            friend bool operator==(const DateWrap& date1, const DateWrap& date2);
            friend bool operator<(const DateWrap& date1, const DateWrap& date2);
            friend ostream& operator<<(ostream& os, const DateWrap& date1);

    };

    bool operator==(const DateWrap& date1, const DateWrap& date2);         
    bool operator<(const DateWrap& date1, const DateWrap& date2);
    ostream& operator<<(ostream& os, const DateWrap& date1);
    DateWrap operator+(DateWrap& date1, const int days);
    DateWrap operator+(int days, DateWrap& date1);
    DateWrap operator++(DateWrap& date1, int);
    bool operator!=(const DateWrap& date1, const DateWrap& date2);
    bool operator<=(const DateWrap& date1, const DateWrap& date2);
    bool operator>=(const DateWrap& date1, const DateWrap& date2);
    bool operator>(const DateWrap& date1, const DateWrap& date2);
    bool isValidDate(int tday, int tmonth, int tyear);
}
#endif /**   DATE_WRAP_H_   */