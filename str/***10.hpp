#ifndef __STR10_HPP__
#define __STR10_HPP__

#include <memory.h>
#include "solution.hpp"

// 30. 串联所有单词的子串

// 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

//  

// 示例 1：

// 输入：
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// 输出：[0,9]
// 解释：
// 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
// 输出的顺序不重要, [9,0] 也是有效答案。
// 示例 2：

// 输入：
//   s = "wordgoodgoodgoodbestword",
//   words = ["word","good","best","word"]
// 输出：[]


class SolutionStr10 : public Solution{
public:	
	~SolutionStr10() {
    }

    virtual void solution() override {

        input1_ = "barfoothefoobarman", input2_ = {"bar", "foo"};

		timer_.calc([this]() -> void* {
			output_ = findSubstring(input1_, input2_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input1 : " << input1_ << std::endl;
        std::cout << "input2 : " << vec2Str(input2_) << std::endl;
        std::cout << "output : " << vec2Str(output_) << std::endl;
        timer_.dump();
    }

    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> out;
        if(s.empty()) return out;

        int size = s.size();
        std::vector<int> map;
        for(size_t i = 0; i < size; ) {
            map.assign(size, 0);
            for(size_t j = words.size() - 1; j >= 0; --j) {
                if(size - i >= words[j].size()) {
                    if(s[i] == words[j][0] && strncmp(s.data()+i, words[j].data(), words[j].size()) == 0) {
                        map[j] = 1;
                    }
                } else {
                    return out;
                }
            }
        }

        return out;
    }

private:
    std::vector<int> output_;
    std::string input1_;
    std::vector<std::string> input2_;
};


#endif //__STR10_HPP__