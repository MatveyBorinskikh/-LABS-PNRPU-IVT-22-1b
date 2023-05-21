#include "custom_time.h"


custom_time::custom_time() {
    seconds = 0;
    minutes = 0;
}

custom_time::custom_time(int m, int s) {
    seconds = s;
    minutes = m;
}

custom_time::custom_time(custom_time& t) {
    seconds = t.seconds;
    minutes = t.minutes;
}

custom_time& custom_time::operator=(const custom_time& t) {
    minutes = t.minutes;
    seconds = t.seconds;
    return *this;
}

custom_time& custom_time::operator+(custom_time& t) {
    int tmp = (60 * minutes + seconds) + (60 * t.minutes + t.seconds);
    minutes = tmp / 60;
    seconds = tmp % 60;
    return *this;
}

std::istream& operator>>(std::istream& in, custom_time& t) {
    int a, b;
    in >> a >> b;
    t.set_minutes(a);
    t.set_seconds(b);
    return in;
}

std::ostream& operator<<(std::ostream& out, custom_time& t) {
    std::cout << t.get_minutes() << " " << t.get_seconds();
    return out;
}

custom_time custom_time::operator/(int n) {
    int tmp = minutes * 60 + seconds;
    return { (tmp / n) / 60,(tmp / n) % 60 };
}