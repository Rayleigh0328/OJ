#include <sstream>

bool is_leap(int year){
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int get_days_in_month(int year, int month){
    int count_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap(year)) count_day[2] = 29;
    return count_day[month];
}

class Date{
    private:
        int year;
        int month;
        int day;
    public:
        Date(int y, int m, int d):
            year(y),
            month(m),
            day(d)
        {}
        
        long long get_timestamp() const {
            long long result = 0;
            long long second_in_day = 24 * 60 * 60;
            for (int i=1970; i<year; ++i) 
                if (is_leap(year)) result += 366 * second_in_day;
                else result += 365 * second_in_day; 
            for (int i=1; i<month;++i)
                result += get_days_in_month(year, i) * second_in_day;
            result += (day-1) * second_in_day; 
            return result;
        }
};



class Solution {
public:
    int dayOfYear(string date) {
        istringstream sin(date);
        int year, month, day;
        char ch;
        sin>>year>>ch>>month>>ch>>day;
        Date year_start = Date(year,1,1);
        Date current = Date(year, month, day);
        return (current.get_timestamp() - year_start.get_timestamp())/(24 * 60 * 60) + 1;
    }
};
