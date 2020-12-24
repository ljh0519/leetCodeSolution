#ifndef __NUMBER2_HPP__
#define __NUMBER2_HPP__

#include <algorithm>
#include "solution.hpp"

// 1. 两数之和

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

        X_SOLUTION_TEST(std::vector<int>({0,1}), target_ = 9, input_ = {2, 7, 11, 15});
        X_SOLUTION_TEST(std::vector<int>({1,2}), target_ = 6, input_ = {3, 2, 4});
        // target = 9, input = {2, 5, 7, 11, 15};
        // target = 9, input = {2, 5, 7, 11, 15};
        // target = 9, input = {2, 5, 7, 11, 15};


    }

   void test(std::vector<int>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			out_ = twoSum(input_, target_);
            return nullptr;
		});

        dumpOutput();
        if(expect != out_) {
            std::cout << "expect != output"  << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << vec2Str(input_) << std::endl;
        std::cout << "target : " << target_ << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << vec2Str(out_) << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
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
    std::vector<int> input_;
    int target_;
};



#endif //__NUMBER2_HPP__