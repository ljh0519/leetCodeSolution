
#ifndef __ARRAY18_HPP__
#define __ARRAY18_HPP__

#include <memory.h>
#include <algorithm>
#include "solution.hpp"

// 39. 组合总和

// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的数字可以无限制重复被选取。

// 说明：

// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 


// 示例 1：
// 输入：candidates = [2,3,6,7], target = 7,
    // 所求解集为：
    // [
    //   [7],
    //   [2,2,3]
    // ]


// 示例 2：
// 输入：candidates = [2,3,5], target = 8,
    // 所求解集为：
    // [
    //   [2,2,2,2],
    //   [2,3,3],
    //   [3,5]
    // ]
//  

// 提示：
    // 1 <= candidates.length <= 30
    // 1 <= candidates[i] <= 200
    // candidate 中的每个元素都是独一无二的。
    // 1 <= target <= 500




class SolutionArray18 : public Solution{
public:	
	~SolutionArray18() {}

    virtual void solution() override {   
        
        // input_ = {10,1,2,7,6,1,5}, target_ = 8;
        input_ = {3,1,2,2,5,7,1,8,8,8}, target_ = 8;
        // input_ = {1,2,5,10}, target_ = 30;
        // input_ = {2,3,6,7}, target_ = 10;
        // input_ = {2,3,6,7}, target_ = 10;
     

		timer_.calc([this]() -> void* {
			output_ = combinationSum2(input_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "input : " << target_ << std::endl;
        std::cout << "output : " << std::endl;
        for(auto& str : output_) {
            std::cout << vec2Str(str, ",") << std::endl;
        }
        timer_.dump();
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