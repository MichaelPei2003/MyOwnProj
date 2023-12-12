#include <iostream>

using namespace std;

class Date {
protected:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    virtual ~Date() {}

    int IntDate() {
        return day + month * 100 + year * 10000;
    }

    void ShowDate() {
        cout << " " << year << "/" << month << "/" << day;
    }
};

class Time {
protected:
    int hour;
    int minute;
    int second;
public:
    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    virtual ~Time() {}

    int IntTime() {
        return hour * 10000 + minute * 100 + second;
    }

    void ShowTime() {
        cout << " " << hour << ":" << minute << ":" << second;
    }
};

class Schedule : public Date, public Time {
    int ID;
public:
    Schedule(int y, int m, int d, int h, int min, int s, int id) : Date(y, m, d), Time(h, min, s) {
        ID = id;
    }

    virtual ~Schedule() {}

    bool operator<(Schedule s2) {
        if (this->IntDate() != s2.IntDate()) {
            return IntDate() < s2.IntDate();
        } else {
            return IntTime() < s2.IntTime();
        }
    }

    void Show() {
        cout << "No." << ID << ":";
        Date::ShowDate();
        Time::ShowTime();
    }
};

int main() {
    int yer, mon, day, hour, min, sec;
    Schedule s2(9999, 99, 99, 99, 99, 99, 0);
    while (true) {
        int id;
        cin >> id;
        if (id == 0) {
            break;
        }
        scanf("%d/%d/%d %d:%d:%d", &yer, &mon, &day, &hour, &min, &sec);
        Schedule s1(yer, mon, day, hour, min, sec, id);
        if (s1 < s2) {
            s2 = s1;
        }
    }
    cout<<"The urgent schedule is ";
    s2.Show();
}
