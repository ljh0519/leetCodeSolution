#ifndef __ARRAY6_HPP__
#define __ARRAY6_HPP__

#include "solution.hpp"
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:

// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:

// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
// 说明:

// 所有输入只包含小写字母 a-z 。



class SolutionArray6 : public Solution{
public:	
	~SolutionArray6() {}

    virtual void solution() override {
        X_SOLUTION_TEST("fl", input_ = {"flower","flow","flight"});
        X_SOLUTION_TEST("", input_ = {"dog","racecar","car"});

    }

    void test(const char* expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = longestCommonPrefix(input_);
            return nullptr;
		});

        dumpOutput();
        if(expect != out_) {
            std::cout << "expect != output : " << expect << " != " << out_ << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
    }

    virtual void dumpOutput() override {
		std::cout << "out = " << out_ << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string CommonPrefix;
        if(strs.empty()) {
            return CommonPrefix;
        }

        for(int pos = 0; pos < strs[0].size(); ++pos) {
            char chr = strs[0][pos];
            for(int i = strs.size() - 1; i >= 1; --i) {
                if(pos >= strs[i].size()
                || chr != strs[i][pos]) {
                    return CommonPrefix;
                }
            }
            CommonPrefix.push_back(chr);
        }
        return CommonPrefix;
    }

private:
    std::vector<std::string> input_;
    std::string out_;
};



#endif //__ARRAY6_HPP__