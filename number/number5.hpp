#ifndef __NUMBER5_HPP__
#define __NUMBER5_HPP__

#include <cmath>
#include "solution.hpp"
// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

// 示例 1:

// 输入: 123
// 输出: 321
//  示例 2:

// 输入: -123
// 输出: -321
// 示例 3:

// 输入: 120
// 输出: 21
// 注意:

// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。



class SolutionNumber5 : public Solution{
public:	
	~SolutionNumber5() {}

    virtual void solution() override {   
        
        // input_ = 100;       //C
        // input_ = 940;        //CMXL
        // input_ = 9;          //IX
        // input_ = 58;          //LVIII
        // input_ = 1994;         //MCMXCIV
        // input_ = 1994;         //MCMXCIV
        // input_ = 2147483647;         //MCMXCIV
        // input_ = -1;         //MCMXCIV
        // input_ = -298;         //MCMXCIV
        // input_ = -2147483648;         //MCMXCIV
        input_ = -2147483647;         //MCMXCIV

		timer_.calc([this]() -> void* {
			out_ = reverse(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "out : " << out_ << std::endl;
        timer_.dump();
    }

    int reverse(int x) {
        if(x > -10 && x < 10) {
            return x;
        }else if (INT32_MIN == x || INT32_MAX == x) {
            return 0;
        }

        std::string str = std::to_string(x);
        int size = str.size();
        int sum = 0;
        int pre = 0;
        for(int i = 0; i < size; ++i) {
            if(x < 0) {
                if(0 == i)continue;
                pre = sum - pow(10, i-1) * (str[i] - 48);                
                if(pre > sum) return 0;
            } else {
                pre = sum + pow(10, i) * (str[i] - 48);
                if(pre < sum)  return 0;
            }
            sum = pre;
        }
        return sum;
    }

private:
    int out_;
    int input_;
};



#endif //__NUMBER5_HPP__