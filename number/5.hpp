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
        
        X_SOLUTION_TEST(1, input_ = 100);
        X_SOLUTION_TEST(49, input_ = 940);
        X_SOLUTION_TEST(85, input_ = 58);
        X_SOLUTION_TEST(4991, input_ = 1994);
        X_SOLUTION_TEST(0, input_ = 2147483647);
        X_SOLUTION_TEST(0, input_ = 1534236469);
        X_SOLUTION_TEST(-1, input_ = -1);
        X_SOLUTION_TEST(-892, input_ = -298);
        X_SOLUTION_TEST(0, input_ = -2147483648);
        X_SOLUTION_TEST(0, input_ = -2147483647);
        X_SOLUTION_TEST(0, input_ = -1563847412);


    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = reverse(input_);
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
        std::cout << "input : " << input_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << out_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //大神解法，long在C99规定中至少比int取值范围大，所以不担心整数溢出，可以直接进行计算
    int reverse(int x) {
        long n = 0;
        while (x) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n > INT32_MAX || n < INT32_MIN ? 0 : n;
    }


    //4ms       6.4MB
    // int reverse(int x) {
    //     if(x > -10 && x < 10) {
    //         return x;
    //     }else if (INT32_MIN == x || INT32_MAX == x) {
    //         return 0;
    //     }

    //     std::string str = std::to_string(x);
    //     int size = str.size();
    //     if(x > 0 && 10 == size && str[9] > 50
    //     || x < 0 && 11 == size && str[10] > 50) {
    //         return 0;
    //     }
    //     int sum = 0, part;
    //     for(int i = size-1; i >= 0; --i) {
    //         if(x < 0) {
    //             if(0 == i)continue;
    //             part = pow(10, i-1) * (str[i] - 48);                
    //             if(INT32_MIN - sum  > -part) return 0;
    //             sum -= part;
    //         } else {
    //             part = pow(10, i) * (str[i] - 48);
    //             if(INT32_MAX - sum < part)  return 0;
    //             sum += part;
    //         }
    //     }

    //     return sum;
    // }

private:
    int out_;
    int input_;
};



#endif //__NUMBER5_HPP__