
#ifndef __STR6_HPP__
#define __STR6_HPP__

#include <cmath>
#include "solution.hpp"

// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

//  
// 示例 1：

// 输入：s = "aa" p = "a"
// 输出：false
// 解释："a" 无法匹配 "aa" 整个字符串。
// 示例 2:

// 输入：s = "aa" p = "a*"
// 输出：true
// 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 示例 3：

// 输入：s = "ab" p = ".*"
// 输出：true
// 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 示例 4：

// 输入：s = "aab" p = "c*a*b"
// 输出：true
// 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 示例 5：

// 输入：s = "mississippi" p = "mis*is*p*."
// 输出：false
//  

// 提示：

// 0 <= s.length <= 20
// 0 <= p.length <= 30
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
// 保证每次出现字符 * 时，前面都匹配到有效的字符



class SolutionStr6 : public Solution{
public:	
	~SolutionStr6() {
    }

    virtual void solution() override {

    }

   void test(int expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = isMatch(input1_, input2_);
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
        std::cout << "input : " << input1_ << std::endl;
        std::cout << "input : " << input2_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }


    bool isMatch(std::string s, std::string p) {
        if(s.empty() || p.empty()) {
            if(s.empty() && p.empty()) {
                return true;
            }
            return false;
        }

        int pre = 0, now = 1;
        int i = 0;
        while(1) {
            if('*' == p[pre]) {
                return false;
            } else if('*' != p[now]) {       // .a     ba

            } else if ('.' == p[pre] && '*' == p[now]) {      // .*

            } else if ('.' != p[pre] && '*' == p[now]) {      // a*

            }
        }
        return true;
    }

private:
    std::string input1_;
    std::string input2_;
    int output_; 
};


#endif //__STR6_HPP__