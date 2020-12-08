#ifndef __STR7_HPP__
#define __STR7_HPP__

#include <string.h>
#include "solution.hpp"

// 17. 电话号码的字母组合

// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



// 示例:

// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。


class SolutionStr7 : public Solution{
public:	
	~SolutionStr7() {
    }

    virtual void solution() override {

        input_ = "23";

		timer_.calc([this]() -> void* {
			output_ = letterCombinations(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << input_ << std::endl;
        std::cout << "output : " << vec2Str(output_) << std::endl;
        timer_.dump();
    }

    //0ms       6.6MB   ???
    std::vector<std::string> letterCombinations(std::string digits) {
        static const char * table[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> out;
        if(digits.empty()) {
            return out;
        }
        std::string tmp;

        letterCombinationsRecu(out, table, digits, 0, tmp);
        return out;
    }

    void letterCombinationsRecu(std::vector<std::string>& out, const char** table, const std::string& digits, int pos, std::string& tmp) {
        if(digits.size() == pos) {
            out.push_back(tmp);
            return ;
        }
        int key = digits[pos] - '2';
        if(key < 0
        || key > 7) {
            return ;
        }

        int size = strlen(table[key]);
        for(int i = 0; i < size; ++i) {
            tmp += table[key][i];
            letterCombinationsRecu(out, table, digits, pos+1, tmp);
            tmp.pop_back();
        }
    }

private:
    std::vector<std::string> output_;
    std::string input_;
};


#endif //__STR7_HPP__