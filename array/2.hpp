#ifndef __ARRAY2_HPP__
#define __ARRAY2_HPP__

#include "solution.hpp"
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

//  

// 示例 1:

// 给定 nums = [3,2,2,3], val = 3,

// 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

// 你不需要考虑数组中超出新长度后面的元素。
// 示例 2:

// 给定 nums = [0,1,2,2,3,0,4,2], val = 2,

// 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

// 注意这五个元素可为任意顺序。

// 你不需要考虑数组中超出新长度后面的元素。
//  

// 说明:

// 为什么返回数值是整数，但输出的答案是数组呢?

// 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

// 你可以想象内部操作如下:

// // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
// int len = removeElement(nums, val);

// // 在函数里修改输入数组对于调用者是可见的。
// // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

class SolutionArray2 : public Solution{
public:	
	~SolutionArray2() {}

    virtual void solution() override {
        // arr_ = {1};         //val=1,val=2
        arr_ = {1, 1};      //val=1,val=2
        // arr_ = {1,3,3,5,6}; //val=3,val=5
        int val = 3;
        int size;
		timer_.calc([this, val, &size]() -> void* {
			size = removeElement(arr_, val);
            return nullptr;
		});
        std::cout << "size=" << size << std::endl;
    }

    virtual void dump() override {
        for_each(arr_.begin(), arr_.end(), [](int i){std::cout << i << ",";});
        std::cout << std::endl;
		std::cout << arr_.size() << std::endl;
        timer_.dump();
    }

    //4ms       8.9MB
    int removeElement(std::vector<int>& nums, int val) {
        if(nums.empty()) {
            return 0;
        }

        int size = nums.size();
        for(int i = 0; i < size;) {
            if(nums[i] == val && 0 != --size) {
                nums[i] = nums[size];
            } else {
                ++i;
            }
        }
        return size;
    }

private:
    std::vector<int> arr_;
};



#endif //__ARRAY2_HPP__