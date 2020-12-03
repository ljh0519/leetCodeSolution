#ifndef __NUMBER6_HPP__
#define __NUMBER6_HPP__

#include <cmath>
#include "solution.hpp"
// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:

// 输入: 121
// 输出: true
// 示例 2:

// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 示例 3:

// 输入: 10
// 输出: false
// 解释: 从右向左读, 为 01 。因此它不是一个回文数。
// 进阶:

// 你能不将整数转为字符串来解决这个问题吗？



class SolutionNumber6 : public Solution{
public:	
	~SolutionNumber6() {}

    virtual void solution() override {   
        
        // input_ = 100;
        input_ = 121;

		timer_.calc([this]() -> void* {
			out_ = isPalindrome(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "out : " << out_ << std::endl;
        timer_.dump();
    }

    //12ms       6.3MB
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int y = x;
        long sum = 0;
        while ( y ) {
            sum  = sum * 10 + y % 10;
            y /= 10;
        }

        return sum == x;
    }   




    //4ms       6.3MB
    // bool isPalindrome(int x) {
    //     if(x < 0) {
    //         return false;
    //     }
        
    //     const std::string& str = std::to_string(x);
    //     for( int i = 0, j = str.size() - 1; i <= j; ++i, --j) {
    //         if(str[i] != str[j]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

private:
    bool out_;
    int input_;
};



#endif //__NUMBER6_HPP__