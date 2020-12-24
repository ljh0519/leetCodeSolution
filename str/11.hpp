#ifndef __STR11_HPP__
#define __STR11_HPP__

#include <memory.h>
#include "solution.hpp"

// 32. 最长有效括号

// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

// 示例 1:

// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:

// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"



class SolutionStr11 : public Solution{
public:	
	~SolutionStr11() {
    }

    virtual void solution() override {

        X_SOLUTION_TEST(8, input_ = "((()())(()()()()");
        X_SOLUTION_TEST(2, input_ = "(()");
        X_SOLUTION_TEST(4, input_ = ")()())");

    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = longestValidParentheses(input_);
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


    //4ms   7MB
    int longestValidParentheses(std::string s) {
        if(s.empty()) return 0;

        size_t size = s.size();

        for(size_t i = 0; i < size; ++i) {
           if(')' == s[i]) {
               for(size_t j = i; j > 0; --j) {
                   if(')' == s[j-1]) {
                       break;
                   } else if('(' == s[j-1]) {
                       s[j-1] = '0';
                       s[i] = '0';
                       break;
                   }
               }
           } 
        }
        
        size_t tmp = 0, maxLen = 0;
        for(size_t i = 0; i < size; ++i ) {
            if(s[i] != '0') {
                if(maxLen < tmp) {
                    maxLen = tmp;
                }
                tmp = 0;
            } else {
                ++tmp;
            }
        }
        return maxLen > tmp ? maxLen : tmp;
    }


    //12ms      8.6MB
    // struct legal {
    //     char chr;
    //     size_t pos;

    //     legal(char cr, size_t ps) :chr(cr), pos(ps){}
    // };

    // int longestValidParentheses(std::string s) {
    //     if(s.empty()) return 0;
    //     int maxLen = 0;
    //     size_t size = s.size();

    //     std::vector<legal> tmp;
    //     for(size_t i = 0; i < size; ++i) {
    //         if('(' == s[i]) {
    //             tmp.emplace_back(legal({'(', i}));
    //         } else if (')' == s[i]) {
    //             if(!tmp.empty() && tmp.back().chr == '(') {
    //                 tmp.pop_back();
    //             } else {
    //                 tmp.emplace_back(')', i);
    //             }
    //         }
    //     }

    //     if(!tmp.empty()) {
    //         if(tmp[0].pos != 0 && maxLen < tmp[0].pos - 1) {
    //             maxLen = tmp[0].pos;
    //         }
    //         for(size_t i = 1;  i < tmp.size(); ++i) {
    //             if(tmp[i].pos - tmp[i-1].pos - 1 > maxLen) {
    //                 maxLen = tmp[i].pos - tmp[i-1].pos - 1;
    //             }
    //         }
    //         int ss = (size - tmp.back().pos - 1);
    //         if(ss > maxLen ){
    //             maxLen = ss;
    //         }
    //     } else {
    //         maxLen = size;
    //     }

    //     return maxLen;
    // }
private:
    int output_;
    std::string input_;
};


#endif //__STR11_HPP__