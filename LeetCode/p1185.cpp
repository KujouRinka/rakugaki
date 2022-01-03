const int month_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string day_map[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1970-12-31 Tuesday
        int days = 0;
        for (int i = 1971; i < year; ++i)
            days += isLeapYear(i) ? 366 : 365;
        for (int i = 1; i < month; ++i)
            days += month_day[i];
        if (isLeapYear(year) && month > 2)
            ++days;
        days += day;
        return day_map[(days + 4) % 7];
    }

private:
    static inline bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};

