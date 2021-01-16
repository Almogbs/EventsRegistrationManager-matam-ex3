#include "date_wrap.h"

using mtm::DateWrap;

DateWrap::DateWrap(int in_day, int in_month, int in_year){
    if(!isValidDate(in_day, in_month, in_year)){
        throw mtm::InvalidDate();
    }
    tday = in_day, tmonth = in_month, tyear = in_year;
    date = dateCreate(tday, tmonth, tyear);
    if(!date){
        throw std::bad_alloc();
    }
}

DateWrap::DateWrap(const DateWrap& date1){
    tday = date1.tday, tmonth = date1.tmonth, tyear = date1.tyear;
    date = dateCopy(date1.date);
    if(!date){
        throw std::bad_alloc();
    }
}

DateWrap::~DateWrap(){
    dateDestroy(date);
}

DateWrap& DateWrap::operator=(const DateWrap& date1){
    dateDestroy(date);
    date = dateCopy(date1.date);
    if(!date){
        throw std::bad_alloc();
    }
    return *this;
}

int DateWrap::day(){
    return tday;
}

int DateWrap::month(){
    return tmonth;
}

int DateWrap::year(){
    return tyear;
}

DateWrap& DateWrap::operator+=(const int days){
    if(days < 0){
        throw mtm::NegativeDays();
    }
    for(int i = 0; i < days; i++){
        dateTick(date);
    }
    int *pday = &tday, *pmonth = &tmonth, *pyear = &tyear;
    dateGet(date, pday, pmonth, pyear);

    return *this;
}

bool mtm::operator==(const DateWrap& date1, const DateWrap& date2){
    if(dateCompare(date1.date, date2.date) == 0){
        return true;
    }
    return false;
}   

bool mtm::operator<(const DateWrap& date1, const DateWrap& date2){
    if(dateCompare(date1.date, date2.date) < 0){
        return true;
    }
    return false;
}

ostream& mtm::operator<<(ostream& os, const DateWrap& date1){
    os << date1.tday << SLASH << date1.tmonth <<  SLASH << date1.tyear;
    return os;
}

DateWrap mtm::operator+(DateWrap& date1 , const int days){
    DateWrap date2(date1);
    date2 += days;
    return date2;
}

DateWrap mtm::operator+(const int days, DateWrap& date1){
    return date1 + days;
}

DateWrap mtm::operator++(DateWrap& date1, int){
    DateWrap date2(date1);
    date1 += MIN_DAY;
    return date2;
}

bool mtm::operator!=(const DateWrap& date1, const DateWrap& date2){
    return !(date1 == date2);
}

bool mtm::operator<=(const DateWrap& date1, const DateWrap& date2){
    return date2 >= date1;
}

bool mtm::operator>=(const DateWrap& date1, const DateWrap& date2){
    return !(date1 < date2);
}

bool mtm::operator>(const DateWrap& date1, const DateWrap& date2){
    return date2 < date1;
}

bool mtm::isValidDate(int tday, int tmonth, int tyear){
    if(tday < MIN_DAY || tday > MAX_DAY || tmonth < MIN_MONTH || tmonth > MAX_MONTH){
        return false;
    }
    return true;
}
