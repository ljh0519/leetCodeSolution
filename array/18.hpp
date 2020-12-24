
#ifndef __ARRAY18_HPP__
#define __ARRAY18_HPP__

#include <memory.h>
#include <algorithm>
#include "solution.hpp"

// 40. 组合总和 II

// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用一次。

// 说明：

// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 
// 示例 1:

// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// 示例 2:

// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]





class SolutionArray18 : public Solution{
public:	
	~SolutionArray18() {}

    virtual void solution() override {   
        
        X_SOLUTION_TEST(std::vector<std::vector<int>>({{1, 7},
               {1, 2, 5},
               {2, 6},
               {1, 1, 6} }), input_ = {10,1,2,7,6,1,5}, target_ = 8);

        X_SOLUTION_TEST(std::vector<std::vector<int>>({{1,2,2},
               {5} }), input_ = {2,5,2,1,2}, target_ = 5);
        // X_SOLUTION_TEST(input_ = {3,1,2,2,5,7,1,8,8,8}, target_ = 8);
        // input_ = {1,2,5,10}, target_ = 30;
        // input_ = {2,3,6,7}, target_ = 10;
        // input_ = {2,3,6,7}, target_ = 10;
     
    }

    void test(std::vector<std::vector<int>>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = combinationSum2(input_, target_);
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
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "input : " << target_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << std::endl;
        for(auto& str : output_) {
            std::cout << vec2Str(str, ",") << std::endl;
        }
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> out;
        std::vector<int> sub_out;
        int size = candidates.size();
        std::sort(candidates.begin(), candidates.end());
        combinationSum2Recu(candidates, size, out, sub_out, target, 0, 0);
        return out;
    }

private:
    void combinationSum2Recu(std::vector<int>& candidates, int size
                            , std::vector<std::vector<int>>& out, std::vector<int>& sub_out
                            , int target, int index, int sum) {
        if(index == size) return ;

        for(int i = index; i < size;) {
            if(target == sum + candidates[i]) {
                sub_out.push_back(candidates[i]);
                out.emplace_back(sub_out);
                sub_out.pop_back();
                return ;
            } else if(target > sum + candidates[i]) {
                sub_out.push_back(candidates[i]);
                combinationSum2Recu(candidates, size, out, sub_out, target, i+1, sum + candidates[i]);
                sub_out.pop_back();
            } else {
                break;
            }
            for(++i; i < size && candidates[i-1] == candidates[i]; ++i) ;
        }
    }

private:
    std::vector<std::vector<int>> output_;
    std::vector<int> input_;
    int     target_;
};



#endif //__ARRAY18_HPP__