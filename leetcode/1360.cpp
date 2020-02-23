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

class MyDate{
    public:
        int year;
        int month;
        int day;
    public:
        MyDate(int y, int m, int d):
            year(y),
            month(m),
            day(d)
        {}
        
        long long get_timestamp() const {
            long long result = 0;
            long long second_in_day = 24 * 60 * 60;
            for (int i=1970; i<year; ++i) 
                if (is_leap(i)) result += 366 * second_in_day;
                else result += 365 * second_in_day; 
            for (int i=1; i<month;++i)
                result += get_days_in_month(year, i) * second_in_day;
            result += (day-1) * second_in_day; 
            return result;
        }
};

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        MyDate d1 = MyDate(stoi(date1.substr(0,4)), stoi(date1.substr(5,2)), stoi(date1.substr(8,2)));
        MyDate d2 = MyDate(stoi(date2.substr(0,4)), stoi(date2.substr(5,2)), stoi(date2.substr(8,2)));
        cout << d1.year <<"-"<< d1.month <<"-"<< d1.day << endl;
        cout << d2.year <<"-"<< d2.month <<"-"<< d2.day << endl;
        long long x = max(d2.get_timestamp(),d1.get_timestamp());
        long long y = min(d2.get_timestamp(),d1.get_timestamp());
        cout << x << " " << y << endl;
        return (x-y)/(24*3600);
    }
};
