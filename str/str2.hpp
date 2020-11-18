#ifndef __STR2_HPP__
#define __STR2_HPP__

#include "solution.hpp"
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

// 示例 1:

// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

class SolutionStr2 : public Solution{
public:	
	~SolutionStr2() {
    }

    virtual void solution() override {    
        std::string str;

        // str = "abcabcbb";   //abc 
        // str = "bbbbb";   //b 
        str = "pwwkew";   //wke 

		timer_.calc([this, &str]() -> void* {
			out_ = lengthOfLongestSubstring(str);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "output : " << out_ << std::endl;
        timer_.dump();
    }

    std::string lengthOfLongestSubstring(std::string s) {
        
        return "";
    }

private:
    std::string out_;
};



#endif //__STR2_HPP__