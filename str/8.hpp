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

        // input_ = "()";
        // input_ = ")(";
        // input_ = "()[]{}";
        // input_ = "(]";
        // input_ = "([)]";
        X_SOLUTION_TEST(true, input_ = "{[]}");

    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = isValid(input_);
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
    
    bool isValid(std::string s) {
        int size = s.size();
        std::vector<int> stack;
        for(int i = 0 ; i < size; ++i) {
            if('(' == s[i]
            || '{' == s[i]
            || '[' == s[i]) {
                stack.push_back(s[i]);
            } else if (stack.empty()) {
                return false;
            } else if (')' == s[i]
            || '}' == s[i]
            || ']' == s[i]) {
                char chr = stack.back();
                if('(' == chr && ')' == s[i]
                || '{' == chr && '}' == s[i]
                || '[' == chr && ']' == s[i]) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }

        return stack.empty() ? true : false;
    }

private:
    bool output_;
    std::string input_;
};


#endif //__STR8_HPP__