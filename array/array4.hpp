#ifndef __ARRAY4_HPP__
#define __ARRAY4_HPP__

#include "solution.hpp"
// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：

// 答案中不可以包含重复的四元组。

// 示例：

// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]



class SolutionArray4 : public Solution{
public:	
	~SolutionArray4() {}

    virtual void solution() override {
        input_ = {1, 0, -1, 0, -2, 2}, target_ = 0;       //2

		timer_.calc([this]() -> void* {
			output_ = fourSum(input_, target_);
            return nullptr;
		});
    }

    virtual void dump() override {
		std::cout << "target = " << target_ << std::endl;
        for(int i = 0; i < input_.size(); ++i) {
            if(0 == i) {
                std::cout << input_[0];
            } else {
                std::cout << "," << input_[i];
            }
        }
        std::cout << std::endl;
        for(auto str : output_) {
            for(int i = 0; i < str.size(); ++i) {
                if(0 == i) {
                    std::cout << str[0];
                } else {
                    std::cout << "," << str[i];
                }
            }
            std::cout << std::endl;
        }
        timer_.dump();
    }

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        if(nums.size() < 4) {
            return {};
        }

        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> out;
        std::vector<int> tmp;
    }

private:
    void dfs(std::vector<std::vector<int>>& out, std::vector<int>& input, std::vector<int>& tmp, int pos, int sum, int target) {
        if(sum + input[pos] > target
        || tmp.size() > 4
        || 4 == tmp.size() && sum + input[pos] != target_) {
            return ;
        }else if(4 == tmp.size() && sum + input[pos] == target) {
            tmp.push_back(input[pos]);
            out.push_back(tmp);
            return ;
        }

        for()

    }
private:
    std::vector<std::vector<int>> output_;
    std::vector<int> input_;
    int target_;
};



#endif //__ARRAY4_HPP__