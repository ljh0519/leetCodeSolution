#ifndef __STR15_HPP__
#define __STR15_HPP__


#include <map>
#include <regex>
#include "solution.hpp"

// 43. 字符串相乘

// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
// 说明：

// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。






class SolutionStr15 : public Solution{
public:	
	~SolutionStr15() {
    }

    virtual void solution() override {

        X_SOLUTION_TEST("100", input1_ = "10", input2_ = "10");
        X_SOLUTION_TEST("310680", input1_ = "180", input2_ = "1726");
        X_SOLUTION_TEST("2500", input1_ = "50", input2_ = "50");
        X_SOLUTION_TEST("9801", input1_ = "99", input2_ = "99");
        
    }

    void test(const char* expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = multiply( input1_, input2_);
            return nullptr;
		});

        dumpOutput();

        if(expect != output_) {
            std::cout << "expect != output : " << expect << " != " << output_ << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input1 : " << input1_ << std::endl;
        std::cout << "input2 : " << input2_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //7ms
    std::string multiply(std::string num1, std::string num2) {
        if(num1.empty() || num2.empty()) return "";
        else if("0" == num1 || "0" == num2) return "0";

        std::string out;
        int carry = 0, size1 = num1.size(), size2 = num2.size();
        for(int i = size2 -1, j = size1 + size2 - 2; j >= 0 || carry > 0; --i, --j) {
            if(j >= 0) {
                for(int m = i; m < size2; ++m) {
                    if(m >= 0 && m - i < size1) {
                        carry += (num1[size1 - 1 - m + i] - '0') * (num2[m] - '0');
                    }
                }
            }

            out.push_back((carry%10) + '0');
            carry /= 10;
        }

        std::reverse(out.begin(), out.end());
        return out;
    }

private:
    std::string output_;
    std::string input1_;
    std::string input2_;
};


#endif //__STR15_HPP__