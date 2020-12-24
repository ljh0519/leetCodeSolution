#ifndef __STR3_HPP__
#define __STR3_HPP__

#include <cstring>
#include "solution.hpp"
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"


class SolutionStr3 : public Solution{
public:	
	~SolutionStr3() {
    }

    virtual void solution() override {

        // input_ = "";        // 
        // input_ = "bb";        // bb
        // input_ = "babad";   // bab  aba
        // input_ = "cbbd";    // bb
        // input_ = "ab";      // a       b
        // input_ = "a";        //a
        X_SOLUTION_TEST("cdc", input_ = "abcdc");    //cdc

    }

   void test(const char* expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = longestPalindrome(input_);
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


    //24ms      7.4MB
    std::string longestPalindrome(std::string s) {
        if(s.size() < 2) {
            return s;
        }
        
        int size = s.size();
        int sub_pos[2] = {};

        for(int i = 0; i < size; ++i) {
            int k = i, m = i;
            for(; k >= 0 && m < size;  --k, ++m) {
                if(s[k] != s[m]) break;
            }
            if(sub_pos[1]-sub_pos[0] < m-k-1) {
                sub_pos[0] = k+1;
                sub_pos[1] = m-1;
            }
            for(k = i, m = i+1; k >= 0 && m < size;  --k, ++m) {
                if(s[k] != s[m]) break;
            }
            if(sub_pos[1]-sub_pos[0] < m-k-1) {
                sub_pos[0] = k+1;
                sub_pos[1] = m-1;
            }
        }

        return s.substr(sub_pos[0], sub_pos[1]-sub_pos[0]+1);
    }

private:
    std::string input_;
    std::string output_;
};


#endif //__STR3_HPP__