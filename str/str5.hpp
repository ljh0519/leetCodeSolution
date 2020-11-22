#ifndef __STR5_HPP__
#define __STR5_HPP__

#include <cmath>
#include "solution.hpp"

// 请你来实现一个 atoi 函数，使其能将字符串转换成整数。

// 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

// 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。

// 提示：

// 本题中的空白字符只包括空格字符 ' ' 。
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
 

// 示例 1:

// 输入: "42"
// 输出: 42
// 示例 2:

// 输入: "   -42"
// 输出: -42
// 解释: 第一个非空白字符为 '-', 它是一个负号。
//      我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
// 示例 3:

// 输入: "4193 with words"
// 输出: 4193
// 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
// 示例 4:

// 输入: "words and 987"
// 输出: 0
// 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
//      因此无法执行有效的转换。
// 示例 5:

// 输入: "-91283472332"
// 输出: -2147483648
// 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
//      因此返回 INT_MIN (−231) 。


class SolutionStr5 : public Solution{
public:	
	~SolutionStr5() {
    }

    virtual void solution() override {

        // input_ = "42";  
        // input_ = "AB";  
        // input_ = "   -42";  
        // input_ = "4193 with words";  
        // input_ = "words and 987";  
        // input_ = "-91283472332";  
        // input_ = "   -";  
        // input_ = "   -9";  
        // input_ = "   9";  
        // input_ = "09";  
        // input_ = "    ";  
        // input_ = "-2147483648";  
        // input_ = "2147483648";  
        // input_ = "+2147483648";  
        // input_ = "+2147483647";  
        // input_ = "    +111111";  
        // input_ = "    +";  
        input_ = "    2000000000000000000000000";  
        // input_ = "    0000000000000000000000002";  
        // input_ = "    -0000000000000000000112233";  

		timer_.calc([this]() -> void* {
			output_ = myAtoi(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    int myAtoi(std::string s) {
        if(s.empty()) {
            return 0;
        }

        long sum = 0;
        bool flag = true;
        int size = s.size();
        int i = 0, j;

        for(; i < size && s[i] == ' '; ++i);
        if(s[i] == '-') {
            flag = false;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        } else if (s[i] >= '0' && s[i] <= '9') {
        } else {
            return 0;
        }
        for(j = i; j < size && s[j] >= '0' && s[j] <= '9'; ++j) ;
        if(i == j) return 0;
        if( j - i > 10) return flag ? INT32_MAX : INT32_MIN;
        --j;

        for(; j >= i; ++i) {
            sum = sum * 10 + (s[i] - '0');
        }
        sum = flag ? sum : -sum;

        if(sum < INT32_MIN) {
            return INT32_MIN;
        } else if( sum > INT32_MAX) {
            return INT32_MAX;
        }
        return sum;
    }

private:
    std::string input_;
    int output_;
};


#endif //__STR5_HPP__