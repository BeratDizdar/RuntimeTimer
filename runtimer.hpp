#pragma once
#include <chrono>

class RuntimeTimer {
private:
    using clock = std::chrono::steady_clock;
    using time_point = std::chrono::time_point<clock>;
    time_point _start;
    time_point _end;
    bool _running{false};
public:
    void start() {
        _start = clock::now();
        _running = true;
    }
    void end() {
        _end = clock::now();
        _running = false;
    }
    double get_seconds() {
        if(_running)
            return std::chrono::duration<double>(clock::now() - _start).count();
        else
            return std::chrono::duration<double>(_end - _start).count();
    }
};
