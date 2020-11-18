#ifndef __NUMBER2_HPP__
#define __NUMBER2_HPP__

#include <algorithm>
#include "solution.hpp"
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

// 不能改变数组中元素位置

// 示例:

// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]

// 给定 nums = [3, 2, 4], target = 6

// 因为 nums[1] + nums[2] = 2 + 4 = 6
// 所以返回 [1, 2]

class SolutionNumber2 : public Solution{
public:	
	~SolutionNumber2() {}

    virtual void solution() override {    //取值范围 [−2^31,  2^31 − 1] = [-2147483648, 2147483647]
        int target;
        std::vector<int> input;

        // target = 9, input = {2, 5, 7, 11, 15};
        target = 6, input = {3, 2, 3, 4};
        // target = 9, input = {2, 5, 7, 11, 15};
        // target = 9, input = {2, 5, 7, 11, 15};
        // target = 9, input = {2, 5, 7, 11, 15};

		timer_.calc([this, &input, &target]() -> void* {
			out_ = twoSum(input, target);
            return nullptr;
		});
    }

    virtual void dump() override {
        for_each(out_.begin(), out_.end(), [](int i) {
            std::cout << i << ", ";
        });
        std::cout << std::endl;
        timer_.dump();
    }


 

    // 368ms        52.2MB
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        if(nums.size() < 2) {
            return {};
        }

        std::vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());

        int i = 0 ;
        int j = tmp.size() - 1;
        while(i != j) {
            if(tmp[i] + tmp[j] == target) {
                break;
            } else if(tmp[i] + tmp[j] > target) {
                --j;
            } else if (tmp[i] + tmp[j] < target) {
                ++i;
            }
        }
        if(i == j) {
            return {};
        }

        bool got_reali = false;
        bool got_realj = false;
        for(int w = 0; w < nums.size(); ++w) {
            if(!got_reali && tmp[i] == nums[w]) {
                i = w;
                got_reali = true;
            } else if(!got_realj && tmp[j] == nums[w]) {
                j = w;
                got_realj = true;
            }
        }

        return i <= j ? std::vector<int>({i,j}):std::vector<int>({j,i});
    }


    // 548ms        82.7MB
    // std::vector<int> twoSum(std::vector<int>& nums, int target) {
    //     if(nums.size() < 2) {
    //         return {};
    //     }

    //     std::multimap<int, int> num_map;
    //     for(int i = 0; i < nums.size(); ++i) {
    //         num_map.emplace(std::pair<int,int>(nums[i], i));
    //     }

    //     std::vector<int> out;
    //     auto lit = num_map.begin(), rit = num_map.end();
    //     --rit;
    //     while( lit != rit) {
    //         if(lit->first + rit->first == target) {
    //             if(lit->second > rit->second) {
    //                 out.emplace_back(rit->second);
    //                 out.emplace_back(lit->second);
    //             } else {
    //                 out.emplace_back(lit->second);
    //                 out.emplace_back(rit->second);
    //             }
    //             return std::move(out);
    //         } else if(lit->first + rit->first > target) {
    //             --rit;
    //         } else {
    //             ++lit;
    //         }
    //     }
    //     return std::move(out);
    // }

private:
    std::vector<int> out_;
};



#endif //__NUMBER2_HPP__