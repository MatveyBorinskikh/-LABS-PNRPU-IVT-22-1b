#include "Time.h"


Time::Time() {
    seconds = 0;
    minutes = 0;
}

Time::Time(int m, int s) {
    seconds = s;
    minutes = m;
}

Time::Time(Time& t) {
    seconds = t.seconds;
    minutes = t.minutes;
}

Time& Time::operator=(const Time& t) {
    minutes = t.minutes;
    seconds = t.seconds;
    return *this;
}

Time& Time::operator+(Time& t) {
    int tmp = (60 * minutes + seconds) + (60 * t.minutes + t.seconds);
    minutes = tmp / 60;
    seconds = tmp % 60;
    return *this;
}

std::istream& operator>>(std::istream& in, Time& t) {
    int a, b;
    in >> a >> b;
    t.set_minutes(a);
    t.set_seconds(b);
    return in;
}

std::ostream& operator<<(std::ostream& out, Time& t) {
    std::cout << t.get_minutes() << " " << t.get_seconds();
    return out;
}

Time Time::operator/(int n) {
    int tmp = minutes * 60 + seconds;
    return { (tmp / n) / 60,(tmp / n) % 60 };
}