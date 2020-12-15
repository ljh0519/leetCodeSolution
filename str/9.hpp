#ifndef __STR9_HPP__
#define __STR9_HPP__

#include <memory.h>
#include "solution.hpp"

// 205. 同构字符串

// 给定两个字符串 s 和 t，判断它们是否是同构的。

// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

// 示例 1:

// 输入: s = "egg", t = "add"
// 输出: true
// 示例 2:

// 输入: s = "foo", t = "bar"
// 输出: false
// 示例 3:

// 输入: s = "paper", t = "title"
// 输出: true
// 说明:
// 你可以假设 s 和 t 具有相同的长度。


class SolutionStr9 : public Solution{
public:	
	~SolutionStr9() {
    }

    virtual void solution() override {

        // input1_ = "egg", input2_ = "abb";
        // input1_ = "foo", input2_ = "bar";
        // input1_ = "paper", input2_ = "title";
        // input1_ = "ab", input2_ = "aa";
        input1_ = "12", input2_ = "34";

		timer_.calc([this]() -> void* {
			output_ = isIsomorphic(input1_, input2_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input1 : " << input1_ << std::endl;
        std::cout << "input2 : " << input2_ << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    bool isIsomorphic(std::string s, std::string t) {
        if(s.empty() && t.empty()) {
            return true;
        }
        int size1 = s.size();
        if(size1 != t.size() ) {
            return false;
        }

        char map1[127] = {};
        char map2[127] = {};
        for(int i = 0; i < size1; ++i) {
            char index1 = s[i];
            char index2 = t[i];
            if(index1 < 1 || index1 > 127
            || index2 < 1 || index2 > 127) {
                return false;
            }
            if(0 == map1[index1] && 0 == map2[index2]) {
                map1[index1] = t[i];
                map2[index2] = s[i];
            } else if(0 != map1[index1] && 0 != map2[index2]) {
                if(map1[index1] != t[i]
                || map2[index2] != s[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }

private:
    bool output_;
    std::string input1_;
    std::string input2_;
};


#endif //__STR9_HPP__