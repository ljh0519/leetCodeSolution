


#ifndef __ARRAY21_HPP__
#define __ARRAY21_HPP__

#include <memory.h>
#include <algorithm>
#include <stack>
#include <map>
#include "solution.hpp"

// 496. 下一个更大元素 I

// 给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

// nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

//  

// 示例 1:

// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
// 解释:
//     对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
//     对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
//     对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
// 示例 2:

// 输入: nums1 = [2,4], nums2 = [1,2,3,4].
// 输出: [3,-1]
// 解释:
//     对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
//     对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
//  

// 提示：

// nums1和nums2中所有元素是唯一的。
// nums1和nums2 的数组大小都不超过1000。



class SolutionArray21 : public Solution{
public:	
	~SolutionArray21() {}

    virtual void solution() override {   
        
        X_SOLUTION_TEST(std::vector<int>({-1,3,-1}), input1_ = {4,1,2}, input2_ = {1,3,4,2}); 
        X_SOLUTION_TEST(std::vector<int>({7,7,7,7,7}), input1_ = {1,3,5,2,4}, input2_ = {6,5,4,3,2,1,7}); 
        X_SOLUTION_TEST(std::vector<int>({3,-1}), input1_ = {2,4}, input2_ = {1,2,3,4}); 

    }

    void test(std::vector<int>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = nextGreaterElement(input1_, input2_);
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
        std::cout << "input1 : " << vec2Str(input1_) << std::endl;
        std::cout << "input2 : " << vec2Str(input2_) << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << vec2Str(output_) << std::endl;
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //递增栈
    // 12ms     9.2MB
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        if(nums1.empty()) return {};
        std::vector<int> out(nums1.size(), -1);
        if(nums2.empty()) return out;

        std::stack<int> stack;
        std::map<int, int> map;
        int size2 = nums2.size();
        for(int i = 0 ; i < size2; ) {
            if(stack.empty()
            || stack.top() >= nums2[i]) {
                stack.push(nums2[i]);
                ++i;
            } else if (stack.top() < nums2[i]) {
                map[stack.top()] = nums2[i];
                stack.pop();
            }
        }

        for(int i = nums1.size() - 1; i >= 0; --i) {
            const auto& search = map.find(nums1[i]);
            if(search == map.end()) {
                continue;
            }
            out[i] = search->second;
        }
        return out;
    }


    //53ms
    // std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
    //     if(nums1.empty()) return {};
    //     std::vector<int> arr(nums1.size(), -1);
    //     if (nums2.empty()) return arr;
    //     std::sort(nums2.begin(), nums2.end());
    //     int size1 = nums1.size(), size2 = nums2.size();
    //     int left, right, next_num;
    //     for(int i=0;i<size1;++i)
    //     {
    //         left = 0, right = size2 - 1;
    //         next_num = -1;
    //         while(left <= right) {
    //             int mid = left + (right - left) / 2;
    //             if(nums2[mid] == nums1[i]) {
    //                 if(mid != right) {
    //                     next_num = nums2[right];
    //                 }
    //                 break;
    //             } else if (nums2[mid] > nums1[i]) {
    //                 right = mid - 1;
    //             } else if (nums2[mid] < nums1[i]) {
    //                 left = mid + 1;
    //             }
    //         }
    //         arr[i] = next_num;
    //     }
    //     return arr;
    // }

private:
    std::vector<int> input1_;
    std::vector<int> input2_;
    std::vector<int> output_;
};



#endif //__ARRAY21_HPP__

