#ifndef __STR13_HPP__
#define __STR13_HPP__


#include <map>
#include <regex>
#include "solution.hpp"

// 409. 最长回文串

// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

// 注意:
// 假设字符串的长度不会超过 1010。

// 示例 1:

// 输入:
// "abccccdd"

// 输出:
// 7

// 解释:
// 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。





class SolutionStr13 : public Solution{
public:	
	~SolutionStr13() {
    }

    virtual void solution() override {

        X_SOLUTION_TEST(7, input_ = "abccccdd");
        X_SOLUTION_TEST(1, input_ = "AB");
        X_SOLUTION_TEST(3, input_ = "ABA");

    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = longestPalindrome( input_);
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
        std::cout << "input : " << input_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }


    //
    int longestPalindrome(std::string s) {
        if(s.empty()) return 0;

        char low[26] = {};
        char uper[26] = {};

        int maxLen = 0;
        int alone = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] > 96 && s[i] < 123) {
                char index = s[i]-97;
                if(1 == low[index]) {
                    maxLen += 2;
                    low[index] = 0;
                    --alone;
                } else {
                    low[index] = 1;
                    ++alone;
                }
            } else if(s[i] > 64 && s[i] < 91) {
                char index = s[i]-65;
                if(1 == uper[index]) {
                    maxLen += 2;
                    uper[index] = 0;
                    --alone;
                } else {
                    uper[index] = 1;
                    ++alone;
                }
            }
        }
        return alone > 0 ? maxLen + 1 : maxLen;
    }
private:
    int output_;
    std::string input_;
};


#endif //__STR13_HPP__