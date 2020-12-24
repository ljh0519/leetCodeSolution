#ifndef __NUMBER3_HPP__
#define __NUMBER3_HPP__


#include "solution.hpp"
// 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

// 字符          数值
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
// 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

//  

// 示例 1:

// 输入: "III"
// 输出: 3
// 示例 2:

// 输入: "IV"
// 输出: 4
// 示例 3:

// 输入: "IX"
// 输出: 9
// 示例 4:

// 输入: "LVIII"
// 输出: 58
// 解释: L = 50, V= 5, III = 3.
// 示例 5:

// 输入: "MCMXCIV"
// 输出: 1994
// 解释: M = 1000, CM = 900, XC = 90, IV = 4.
//  

// 提示：

// 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
// IC 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
// 关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics 。


class SolutionNumber3 : public Solution{
public:	
	~SolutionNumber3() {}

    virtual void solution() override {   
        
        X_SOLUTION_TEST(100, input_ = "C");
        X_SOLUTION_TEST(940, input_ = "CMXL");
        X_SOLUTION_TEST(3, input_ = "III");
        X_SOLUTION_TEST(4, input_ = "IV");
        X_SOLUTION_TEST(58, input_ = "LVIII");
        X_SOLUTION_TEST(9, input_ = "IX");
        X_SOLUTION_TEST(1994, input_ = "MCMXCIV");

    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = romanToInt(input_);
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
        std::cout << "roman : " << input_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << out_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    int romanToInt(std::string s) {
        int sum = 0, pre = 0;
        int now;
        for(int j = s.size() - 1; j >= 0; --j) {
            switch(s[j]) {
                case 'I':   now=1;
                break;
                case 'V':   now=5;
                break;
                case 'X':   now=10;
                break;
                case 'L':   now=50;
                break;
                case 'C':   now=100;
                break;
                case 'D':   now=500;
                break;
                case 'M':   now=1000;
                break;
            }
            if(0 == pre) {
                pre = now;
                continue;
            }
            if(pre <= now) {
                sum+= pre;
                pre = now;
            } else {
                sum += (pre - now);
                pre = 0;
            }
        }

        return sum + pre;
    }

private:
    std::string input_;
    int out_;
};



#endif //__NUMBER3_HPP__