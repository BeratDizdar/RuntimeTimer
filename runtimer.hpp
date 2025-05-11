#pragma once
#include <chrono>
#include <iostream>

class RuntimeTimer {
private:
    std::chrono::time_point<std::chrono::steady_clock> _start;
    std::chrono::time_point<std::chrono::steady_clock> _end;
    std::chrono::duration<double> _elapsed_seconds;
public:
    void start() {
        _start = std::chrono::steady_clock::now();
    }
    void end() {
        _end = std::chrono::steady_clock::now();
        _elapsed_seconds = _end - _start;
    }
    double get_seconds() {
        return _elapsed_seconds.count();
    }
};