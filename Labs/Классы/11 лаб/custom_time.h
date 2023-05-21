#ifndef MAIN_CPP_CUSTOM_TIME_H
#define MAIN_CPP_CUSTOM_TIME_H

#include "iostream"
#include "fstream"

class custom_time {
protected:
    int seconds;
    int minutes;
public:
    custom_time();

    custom_time(int m, int s);

    custom_time(custom_time& t);

    ~custom_time() = default;

    [[nodiscard]] int get_minutes() const { return minutes; }

    [[nodiscard]] int get_seconds() const { return seconds; }

    void set_minutes(int m) { minutes = m; }

    void set_seconds(int s) { seconds = s; }

    custom_time& operator=(const custom_time& t);

    friend bool operator==(const custom_time& tl, const custom_time& tr) { return tl.minutes == tr.minutes && tl.seconds == tr.seconds; };

    custom_time& operator+(custom_time& t);

    void Show() const { std::cout << minutes << ":" << seconds << std::endl; };

    friend std::istream& operator>>(std::istream& in, custom_time& t);
    friend std::ostream& operator<<(std::ostream& out, custom_time& t);

    friend bool operator >(const custom_time& tl, const custom_time& tr) { return tl.minutes > tr.minutes || tl.minutes == tr.minutes && tl.seconds > tr.seconds; }
    friend bool operator <(const custom_time& tl, const custom_time& tr) { return tl.minutes < tr.minutes || tl.minutes == tr.minutes && tl.seconds < tr.seconds; }
    custom_time operator / (int n);

};

#endif //MAIN_CPP_CUSTOM_TIME_H