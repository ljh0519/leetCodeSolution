#ifndef __STR8_HPP__
#define __STR8_HPP__

#include "solution.hpp"

// 20. 有效的括号

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true


class SolutionStr8 : public Solution{
public:	
	~SolutionStr8() {
    }

    virtual void solution() override {

        input_ = "23";
        // input_ = "23";
        // input_ = "23";
        // input_ = "23";
        // input_ = "23";

		timer_.calc([this]() -> void* {
			output_ = isValid(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    bool isValid(std::string s) {
        
        return true;
    }

private:
    bool output_;
    std::string input_;
};


#endif //__STR8_HPP__