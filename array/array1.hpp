#ifndef __ARRAY1_HPP__
#define __ARRAY1_HPP__

#include <algorithm>
#include "solution.hpp"
// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

// 示例 1:

// 给定数组 nums = [1,1,2], 

// 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

// 你不需要考虑数组中超出新长度后面的元素。
// 示例 2:

// 给定 nums = [0,0,1,1,1,2,2,3,3,4],

// 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

// 你不需要考虑数组中超出新长度后面的元素。
//  

// 说明:

// 为什么返回数值是整数，但输出的答案是数组呢?

// 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

// 你可以想象内部操作如下:

// // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
// int len = removeDuplicates(nums);

// // 在函数里修改输入数组对于调用者是可见的。
// // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

class SolutionArray1 : public Solution{
public:	
	~SolutionArray1() {
	}

    virtual void solution() override {
        arr_ = {1,1,3,4,4,5};
		timer_.calc([this]() -> void* {
			int size = removeDuplicates(arr_);
            std::cout << "size=" << size << std::endl;
            return nullptr;
		});
    }

    virtual void dump() override {
        for_each(arr_.begin(), arr_.end(), [](int i){std::cout << i << ",";});
        std::cout << std::endl;
		std::cout << arr_.size() << std::endl;
        timer_.dump();
    }

    //32ms      13.7MB
    int removeDuplicates(std::vector<int>& nums) { 
        return unique(nums.begin(), nums.end()) - nums.begin();
    }

    // //24ms      13.9MB
    // int removeDuplicates(std::vector<int>& nums) { 
    //     nums.erase(unique(nums.begin(), nums.end()), nums.end());
    //     return nums.size();
    // }




    //20ms    14.1MB
    // int removeDuplicates(std::vector<int>& nums) {
    //     if(nums.empty()) {
    //         return nums.size();
    //     }
    //     std::vector<int> tmp;
    //     tmp.emplace_back(nums[0]);
    //     for(auto i : nums) {
    //         if(i != tmp.back()) {
    //             tmp.emplace_back(i);
    //         }
    //     }
    //     tmp.swap(nums);
    //     return nums.size();
    // }




    // 184ms    13.6MB
    // int removeDuplicates(std::vector<int>& nums) {
    //     for(auto it = nums.begin(); it != nums.end() && it + 1 != nums.end(); ) {
    //         if(*it == *(it + 1)) {
    //             it = nums.erase(it);
    //         } else {
    //             ++it;
    //         }
    //     }
    //     return nums.size();
    // }

private:
    std::vector<int> arr_;
};



#endif //__ARRAY1_HPP__