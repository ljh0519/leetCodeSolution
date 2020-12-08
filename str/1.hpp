#ifndef __STR1_HPP__
#define __STR1_HPP__

#include "solution.hpp"
// 实现 strStr() 函数。

// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:

// 输入: haystack = "hello", needle = "ll"
// 输出: 2
// 示例 2:

// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1
// 说明:

// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

class SolutionStr1 : public Solution{
public:	
	~SolutionStr1() {}

    virtual void solution() override {
        std::string sub;

        // str_ = "hello",sub = "ll";
        // str_ = "substring searching algorithm",sub = "search";
        // str_ = "bbc abcdab abcdabcdabde",sub = "abcdabd";
        // str_ = "mississippi", sub = "issi";
        // str_ = "ababcaababcaabc", sub = "ababcaabc";
        int pos;
		timer_.calc([this, sub]() -> void* {
			pos_ = strStr(str_, sub);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << str_.c_str() + pos_ << std::endl;
        std::cout << "pos=" << pos_ << std::endl;
        timer_.dump();
    }

    //Sunday算法
    int strStr(std::string haystack, std::string needle) {
        if(needle.empty()) {
            return 0;
        } else if(haystack.empty()) {
            return -1;
        }

        int scan_pos = 0;
        while(1) {
            int i, j;
            for(i = scan_pos, j = 0; i < haystack.size() && j < needle.size(); ++i, ++j) {
                if(haystack[i] != needle[j] ) {
                    break;
                }
            }
            if(needle.size() == j) {
                return scan_pos;
            }
            i = scan_pos + needle.size();
            if(i >= haystack.size()) {
                break;
            }
            for(j = needle.size();j > 0; --j) {
                if(haystack[i] == needle[j-1]) {
                    break;
                }
            }
            if(j > 0 ) {
                j = needle.size() - j;
            } else {
                j = needle.size();
            }
            scan_pos += j + 1;
        }

        return -1;
    }

private:
    std::string str_;
    int pos_;
};



#endif //__STR1_HPP__