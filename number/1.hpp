#ifndef __NUMBER1_HPP__
#define __NUMBER1_HPP__

#include "solution.hpp"
// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

// 返回被除数 dividend 除以除数 divisor 得到的商。

// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

//  

// 示例 1:

// 输入: dividend = 10, divisor = 3
// 输出: 3
// 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
// 示例 2:

// 输入: dividend = 7, divisor = -3
// 输出: -2
// 解释: 7/-3 = truncate(-2.33333..) = -2
//  

// 提示：

// 被除数和除数均为 32 位有符号整数。
// 除数不为 0。
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

class SolutionNumber1 : public Solution{
public:	
	~SolutionNumber1() {}

    virtual void solution() override {    //取值范围 [−2^31,  2^31 − 1] = [-2147483648, 2147483647]
        X_SOLUTION_TEST(-2147483648, dividend_ = -2147483648, divisor_ = -1);
        X_SOLUTION_TEST(-1073741824, dividend_ = -2147483648, divisor_ = 2);
        X_SOLUTION_TEST(715827882, dividend_ = -2147483648, divisor_ = -3);
        X_SOLUTION_TEST(0, dividend_ = -1010369383, divisor_ = -2147483648);
        X_SOLUTION_TEST(3, dividend_ = -10, divisor_ = -3);

    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			quotient_ = divide(dividend_, divisor_);
            return nullptr;
		});

        dumpOutput();
        if(expect != quotient_) {
            std::cout << "expect != output"  << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }

    }

    virtual void dumpInput() override {
    }

    virtual void dumpOutput() override {
        std::cout << dividend_ << " / " << divisor_ << " = " << quotient_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }
    
    int divide(int dividend, int divisor) {
        int out = 0;
        bool result_is_positive = true;
        bool dend_is_min = false;

        if(dividend < 0) {
            if(dividend == INT32_MIN) {
                if(1 == divisor)  return dividend;
                else if (-1 == divisor)  return INT32_MAX;
                else if (INT32_MIN == divisor)  return 1;

                if(divisor > 0) {
                    dividend = dividend + divisor;
                } else {
                    dividend = dividend - divisor;
                }
                dend_is_min = true;
            }
            dividend = 0 - dividend;
            result_is_positive = false;
        }

        if(divisor < 0) {
            if(INT32_MIN == divisor) return 0;
            
            divisor = 0 - divisor;
            result_is_positive = !result_is_positive;
        }

        if( 1 == divisor || -1 == divisor) {
            out = dividend; 
        } else {
            int32_t  high_bit = 1;
            while( dividend > divisor ) {
                const int32_t divisor_new = divisor << 1;
                if(divisor >= divisor_new) {
                    break;
                }            
                divisor = divisor_new;
                high_bit <<= 1;
            }
            while( high_bit > 0 ) {
                if( dividend >= divisor ) {
                    out += high_bit;
                    dividend -= divisor;
                }
                high_bit = high_bit >> 1;
                divisor = divisor >> 1;
            }
            
            if(dend_is_min) {
                out+=1;
            }
        } 

        if(result_is_positive) {
            return out;
        }    
        return 0 - out;
    }


    //解法思路
    //除法虽然不满足分配律，但是，例如7 / 3 = （3 + 3 + 1) / 3 = 3 /3 + 3 / 3 + 1 / 3 = 1 + 1 + 0 = 2
    //求最大除数，（最大除数=denom*2^(n)，即反复给除数向左移位1，相当于给除数乘2，使除数使用满足2的次方倍)，满足最大除数必须小于被除数的原则
    //当被除数大于最大除数时，则表明，不考虑余数的情况下，该被除数可以被该denom*2^n相除。 用被除数减最大除数，
    // int32_t int_div( const int32_t num_in, const int32_t denom_in ) {
    //     int64_t  num = num_in;
    //     int64_t  denom = denom_in; 
    //     int64_t  out = 0;
    //     bool result_is_positive = true;

    //     if(num < 0) {
    //         num = 0 - num_in;
    //         result_is_positive = false;
    //     }

    //     if(denom < 0) {
    //         denom = 0 - denom_in;
    //         result_is_positive = !result_is_positive;
    //     }

    //     if( 1 == denom || -1 == denom) {
    //         out = num;
    //     } else {
    //         //  先找到最高位
    //         int32_t  high_bit = 1;
    //         while( num > denom ) {
    //             const int32_t denom_new = denom << 1;
    //             if( denom < denom_new ) {
    //                 denom = denom_new;
    //                 high_bit <<= 1;
    //                 continue;
    //             }
    //         }
    //         while( high_bit > 0 ) {
    //             if( num >= denom ) {
    //                 out += high_bit;
    //                 num -= denom;
    //             }
    //             high_bit = high_bit >> 1;
    //             denom = denom >> 1;
    //         }
    //     } 
        
    //     if(out == INT32_MIN) {
    //         return INT32_MAX;
    //     }  

    //     if(result_is_positive) {
    //         return out;
    //     }    
    //     return 0 - out;
    // }
private:
    int dividend_;
    int divisor_;
    int quotient_;
};



#endif //__NUMBER1_HPP__