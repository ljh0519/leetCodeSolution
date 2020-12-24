#ifndef __STR4_HPP__
#define __STR4_HPP__


#include "solution.hpp"
// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

// 请你实现这个将字符串进行指定行数变换的函数：

// string convert(string s, int numRows);
// 示例 1:

// 输入: s = "LEETCODEISHIRING", numRows = 3
// 输出: "LCIRETOESIIGEDHN"
// 示例 2:

// 输入: s = "LEETCODEISHIRING", numRows = 4
// 输出: "LDREOEIIECIHNTSG"
// 解释:

// L     D     R
// E   O E   I I
// E C   I H   N
// T     S     G


class SolutionStr4 : public Solution{
public:	
	~SolutionStr4() {
    }

    virtual void solution() override {

        X_SOLUTION_TEST("AB", input_ = "AB", numRows_ = 1);  
        X_SOLUTION_TEST("LIEESGEDHNTOIICR", input_ = "LEETCODEISHIRING", numRows_ = 5);  
        X_SOLUTION_TEST("LDREOEIIECIHNTSG", input_ = "LEETCODEISHIRING", numRows_ = 4);  
        X_SOLUTION_TEST("LCIRETOESIIGEDHN", input_ = "LEETCODEISHIRING", numRows_ = 3);  


    }

   void test(const char* expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = convert(input_, numRows_);
            return nullptr;
		});

        dumpOutput();
        if(expect != output_) {
            std::cout << "expect != output"  << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "numRows : " << numRows_ << std::endl;
        std::cout << "input : " << input_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }


    std::string convert(std::string s, int numRows) {
        if(s.size() <= numRows
        || 1 == numRows) {
            return s;
        }

        int size = s.size();
        int i = 0;
        int step1 = 2*numRows-2;  //回文间固定距离步进
        int step2;      //回文内部步进
        std::string out;
        for(; i < numRows; ++i) {
            step2 = 2*(numRows-1-i);
            for(int j = i; j < size; j += step1) {
                out.push_back(s[j]);
                if(0 != i && numRows - 1 != i
                && j+step2 < size) {
                    out.push_back(s[j+step2]);
                }
            }
        }

        return out;
    }

private:
    int numRows_;
    std::string input_;
    std::string output_;
};


#endif //__STR4_HPP__