#ifndef __STR2_HPP__
#define __STR2_HPP__

#include <cstring>
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

        // input_ = "";   // 0 
        // input_ = "abcabcbb";   //abc 3
        // input_ = "bbbbb";   //b 1
        // input_ = "pwwkew";   //wke 3
        // input_ = "dvdf";   //vdf 3
        input_ = "abba";   //ab 2
        // input_ = "qwertyuiopasdfghjkl;'[]\\zxcvbnm,./=-0987654321`~!@#$%^&*()_+<>?:\"{}|";   // 68

		timer_.calc([this]() -> void* {
			len_ = lengthOfLongestSubstring(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "output : " << len_ << std::endl;
        timer_.dump();
    }

    //0-12ms        7.1MB
    int lengthOfLongestSubstring(std::string s) {
        if(s.empty()) {
            return 0;
        }
        int map[95];       //记录所有不重复字符的位置
        memset(map, -1, 95*sizeof(int));
        int size = s.size();
        int maxlen = 0;         //记录最长不重复子串大小
        int lp = 0, rp = 0;     //描述s中不重复字符字串的左右下标

        while( rp < size) {
            int debug = s[rp]-32;       //当前字符在map中的下标
            if(-1 != map[debug]) {
                if(maxlen < rp-lp) maxlen = rp - lp;

                if(lp <= map[debug]) lp = map[debug]+1; 
            }
            map[debug] = rp;
            ++rp;
        }

        return maxlen > rp-lp ? maxlen : rp-lp;
    }

private:
    std::string input_;
    int len_;
};



#endif //__STR2_HPP__