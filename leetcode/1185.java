
class Solution {

    int [] monthCount = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    String [] dateTable = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    private boolean isSpecial(int year){
        if (year % 400 == 0) return true;
        if (year % 100 == 0) return false;
        if (year % 4 == 0) return true;
        return false;
    }

    public String dayOfTheWeek(int day, int month, int year) {
        int count = 0;
        // 1971 Jan 1 is Friday
        for (int i=1971;i<year;++i)
            if (isSpecial(i)) count += 366;
            else count += 365;
        for (int i=1; i<month; ++i){
            if (i == 2){
                if (isSpecial(year)) count += 29;
                else count += 28;
            }
            else {
                count += monthCount[i];
            }
        }
        count += day - 1;
        return dateTable[(5 + count) % 7];
    }
}
