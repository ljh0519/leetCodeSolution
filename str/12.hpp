#ifndef __STR12_HPP__
#define __STR12_HPP__


#include <map>
#include <regex>
#include "solution.hpp"

// 32. 最长有效括号

// 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

// 示例1:

// 输入: pattern = "abba", str = "dog cat cat dog"
// 输出: true
// 示例 2:

// 输入:pattern = "abba", str = "dog cat cat fish"
// 输出: false
// 示例 3:

// 输入: pattern = "aaaa", str = "dog cat cat dog"
// 输出: false
// 示例 4:

// 输入: pattern = "abba", str = "dog dog dog dog"
// 输出: false
// 说明:
// 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。   




class SolutionStr12 : public Solution{
public:	
	~SolutionStr12() {
    }

    virtual void solution() override {

        X_SOLUTION_TEST(true, input_ = "dog cat cat dog", pattern_ = "abba");
        X_SOLUTION_TEST(false, input_ = "dog cat cat fish", pattern_ = "abba");
        X_SOLUTION_TEST(false, input_ = "dog cat cat dog", pattern_ = "aaaa");
        X_SOLUTION_TEST(false, input_ = "dog dog dog dog", pattern_ = "abba");
    }

   void test(bool expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = wordPattern(pattern_, input_);
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
        std::cout << "pattern : " << pattern_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }


    //
    bool wordPattern(std::string pattern, std::string s) {
        if(s.empty()
        || pattern.empty()) {
            return false;
        }

        std::regex ws_re("\\w+");
        std::vector<std::string> tmp(std::sregex_token_iterator(s.begin(), s.end(), ws_re, 0), std::sregex_token_iterator());
        size_t tmp_size = tmp.size();
        if(tmp_size != pattern.size()) {
            return false;
        }

        std::map<std::string, char> s2c;
        std::map<char, std::string> c2s;
        for(int i = 0; i < tmp_size; ++i) {
            const auto& s2c_search = s2c.find(tmp[i]);
            const auto& c2s_search = c2s.find(pattern[i]);
            if(c2s_search == c2s.end()) {
                if(s2c_search != s2c.end()) {
                    return false;
                }
                c2s[pattern[i]] = tmp[i];
                s2c[tmp[i]] = pattern[i];
            } else {
                if(c2s_search->second != tmp[i]
                || s2c_search == s2c.end()
                || s2c_search->second != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool output_;
    std::string pattern_;
    std::string input_;
};


#endif //__STR12_HPP__