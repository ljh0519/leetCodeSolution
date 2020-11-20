#ifndef __ARRAY3_HPP__
#define __ARRAY3_HPP__

#include "solution.hpp"
// 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

// 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

//  

// 示例 1：

// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
// 示例 2：

// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 示例 3：

// 输入：nums1 = [0,0], nums2 = [0,0]
// 输出：0.00000
// 示例 4：

// 输入：nums1 = [], nums2 = [1]
// 输出：1.00000
// 示例 5：

// 输入：nums1 = [2], nums2 = []
// 输出：2.00000


class SolutionArray3 : public Solution{
public:	
	~SolutionArray3() {}

    virtual void solution() override {
        // nums1_ = {1, 3}, nums2_ = {2};       //2
        nums1_ = {1, 2}, nums2_ = {3, 4};    //2.5
        // nums1_ = {0}, nums2_ = {0};          //0
        // nums1_ = {}, nums2_ = {1};           //1
        // nums1_ = {2}, nums2_ = {0};          //2

		timer_.calc([&]() -> void* {
			median_ = findMedianSortedArrays(nums1_, nums2_);
            return nullptr;
		});
    }

    virtual void dump() override {
        for(int i = 0; i < nums1_.size(); ++i) {
            if(0 == i) {
                std::cout << nums1_[0];
            } else {
                std::cout << "," << nums1_[i];
            }
        }
        std::cout << std::endl;
        for(int i = 0; i < nums2_.size(); ++i) {
            if(0 == i) {
                std::cout << nums2_[0];
            } else {
                std::cout << "," << nums2_[i];
            }
        }
        std::cout << std::endl;
		std::cout << "median = " << median_ << std::endl;
        timer_.dump();
    }

    //56ms      87.8MB
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int pos = nums1.size() + nums2.size();
        if(0 == pos) {
            return 0;
        } else if(1 == pos) {
            return nums1.size() > 0 ? nums1[0] : nums2[0];
        }

        int *arr = new int[pos];
        pos /= 2;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int k = 0, i = 0, j = 0;
        for(; i < size1 && j < size2; ++k) {
            if(nums1[i] > nums2[j]) {
                arr[k] = nums2[j];
                ++j;
            } else {
                arr[k] = nums1[i];
                ++i;
            }
        }
        for(;i < size1; ++k, ++i) {
            arr[k] = nums1[i];
        }
        for(; j < size2; ++k, ++j) {
            arr[k] = nums2[j];
        }

        if(0 == k%2) {
            return (arr[pos] + arr[pos-1])/2.0;
        }
        
        return arr[pos];
    }

private:
    std::vector<int> nums1_;
    std::vector<int> nums2_;
    double median_;
};



#endif //__ARRAY3_HPP__