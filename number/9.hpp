

#ifndef __NUMBER9_HPP__
#define __NUMBER9_HPP__

#include <algorithm>
#include <cmath>
#include "solution.hpp"

// 401. 二进制手表

// 二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。

// 每个 LED 代表一个 0 或 1，最低位在右侧。

// [图片]   https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg

// 例如，上面的二进制手表读取 “3:25”。

// 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

//  

// 示例：

// 输入: n = 1
// 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//  

// 提示：

// 输出的顺序没有要求。
// 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
// 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
// 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。





class SolutionNumber9 : public Solution{
public:	
	~SolutionNumber9() {}

    virtual void solution() override {   
        
        X_SOLUTION_TEST(std::vector<std::string>({"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"}), input_ = 1); 

    }

   void test(std::vector<std::string>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = readBinaryWatch(input_);
            return nullptr;
		});

        dumpOutput();
        if(expect != out_) {
            std::cout << "expect != output"  << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << (input_) << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << vec2Str(out_) << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }


    std::vector<std::string> readBinaryWatch(int num) {
        std::vector<std::string> out;
        if(num < 0 && num > 10) {
            return out;
        }

        std::vector<bool> clock(10, false);
        readBinaryWatch(out, clock, num, -1);
        return out;
    }

private:
    void readBinaryWatch(std::vector<std::string>& out, std::vector<bool>& clock, int num, int pre_point) {
        if(0 == num) {
            const auto& str = getClockByWatch(clock);
            if(!str.empty()) {
                out.emplace_back(str);
            }
            return ;
        }

        for(int i = 9; i > pre_point; --i ) {
            if(clock[i]) continue;

            clock[i] = true;
            readBinaryWatch(out, clock, num-1, i);
            clock[i] = false;
        }
    }

    std::string getClockByWatch(std::vector<bool>& clock) {
        char str[6] = {};
        char hour = 0;
        char minute = 0;
        for(int i = 9; i >= 0; --i) {
            if(!clock[i]) continue;

            if(i > 3) { //minute
                minute += pow(2, 9-i);
                if(minute > 59) {
                    return "";
                }
            } else {    //hour
                hour += pow(2, 3-i);
                if(hour > 11) {
                    return "";
                }
            }
        }

        sprintf(str, "%d:%02d", hour, minute);
        return str;
    }

private:
    std::vector<std::string> out_;
    int input_;
};



#endif //__NUMBER9_HPP__