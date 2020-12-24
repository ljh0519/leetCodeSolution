#ifndef __NUMBER4_HPP__
#define __NUMBER4_HPP__


#include "solution.hpp"
// 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

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
// 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

// 示例 1:

// 输入: 3
// 输出: "III"
// 示例 2:

// 输入: 4
// 输出: "IV"
// 示例 3:

// 输入: 9
// 输出: "IX"
// 示例 4:

// 输入: 58
// 输出: "LVIII"
// 解释: L = 50, V = 5, III = 3.
// 示例 5:

// 输入: 1994
// 输出: "MCMXCIV"
// 解释: M = 1000, CM = 900, XC = 90, IV = 4.



class SolutionNumber4 : public Solution{
public:	
	~SolutionNumber4() {}

    virtual void solution() override {   
        
        X_SOLUTION_TEST("C", input_ = 100);
        X_SOLUTION_TEST("CMXL", input_ = 940);
        X_SOLUTION_TEST("III", input_ = 3);
        X_SOLUTION_TEST("IV", input_ = 4);
        X_SOLUTION_TEST("LVIII", input_ = 58);
        X_SOLUTION_TEST("IX", input_ = 9 );
        X_SOLUTION_TEST("MCMXCIV", input_ = 1994);


    }

   void test(const char* expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = intToRoman(input_);
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

    //0ms       6.2MB
    std::string intToRoman(int num) {
        std::string out;
        intToRomanInternal(out, num/1000, "M", "", "");
        num%=1000;
        intToRomanInternal(out, num/100, "C", "D", "M");
        num%=100;
        intToRomanInternal(out, num/10, "X", "L", "C");
        num%=10;
        intToRomanInternal(out, num, "I", "V", "X");

        return out;
    }

private:
    inline void intToRomanInternal(std::string& out, int num, const char* one , const char* five, const char* ten) {
        if(0 == num) {
            return ;
        }
        
        if(num < 4) {
            while(num--) {
                out += one;
            }
        } else if(4 == num) {
            out = out + one + five;
        } else if (num > 4 && num < 9) {
            out += five;
            while(num-- > 5) {
                out += one;
            }
        } else if (9 == num) {
            out = out + one + ten;
        }
    }

private:
    std::string out_;
    int input_;
};



#endif //__NUMBER4_HPP__