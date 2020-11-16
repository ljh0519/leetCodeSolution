#ifndef __LJH_TIMER_HPP__
#define __LJH_TIMER_HPP__

#include <functional>
#include <chrono>
#include <iostream>

class Timer{
public:
    using timeFunc1 = std::function<void*()>;
public:
    void* calc(const timeFunc1& func) {
        start = get_now_ms();
        void* obj = func();
        end = get_now_ms();
        return obj;
    }

    void dump() {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Total time spent : " << end - start << "ms" << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

private:
    static inline int64_t get_ms_since_1970(){
        return std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
    }
    
    static inline int64_t get_ms_relative_monotonic(){
        typedef std::chrono::milliseconds Milli;
        typedef std::chrono::steady_clock Time;
        static auto start = Time::now();
        auto elapsed = Time::now() - start;
        return std::chrono::duration_cast<Milli> (elapsed).count();
    }
    
    static inline int64_t get_ms_monotonic(){
        typedef std::chrono::milliseconds Milli;
        typedef std::chrono::steady_clock Time;
        return std::chrono::duration_cast<Milli> (Time::now().time_since_epoch()).count();
    }
    
    static inline int64_t get_now_ms(){
        static int64_t base = get_ms_since_1970()-get_ms_monotonic();
        return base + get_ms_monotonic();
    }
private:
    uint64_t start;
    uint64_t end;
};







#endif //__LJH_TIMER_HPP__