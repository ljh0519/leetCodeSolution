#ifndef __STR14_HPP__
#define __STR14_HPP__


#include <map>
#include <regex>
#include "solution.hpp"

// 415. 字符串相加

// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

//  

// 提示：

// num1 和num2 的长度都小于 5100
// num1 和num2 都只包含数字 0-9
// num1 和num2 都不包含任何前导零
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式





class SolutionStr14 : public Solution{
public:	
	~SolutionStr14() {
    }

    virtual void solution() override {

        // input1_ = "10", input2_ = "10";
        // input1_ = "99", input2_ = "99";
        // input1_ = "50", input2_ = "50";
        // input1_ = "132", input2_ = "68";
        

		timer_.calc([this]() -> void* {
			output_ = addStrings( input1_, input2_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input1 : " << input1_ << std::endl;
        std::cout << "input2 : " << input2_ << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    //
    std::string addStrings(std::string num1, std::string num2) {
        if(num1.empty()) {
            return num2;
        } else if (num2.empty()) {
            return num1;
        }

        
        std::string sum;
        int carry = 0;
        for(int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; ++i, ++j) {
            int sub_sum = carry;
            if(i >= 0) {
                sub_sum += num1[i] - '0';
            }
            if(j >= 0) {
                sub_sum += num2[j] - '0';
            }
            carry = sub_sum / 10;
            sum.insert(sum.begin(), sub_sum % 10 + '0');
        }
        if(carry > 0) sum.insert(sum.begin(), carry % 10 + '0');
        return sum;
    }
private:
    std::string output_;
    std::string input1_;
    std::string input2_;
};


#endif //__STR14_HPP__