
#ifndef __ARRAY17_HPP__
#define __ARRAY17_HPP__

#include "memory.h"
#include "solution.hpp"

// 37. 解数独

// 编写一个程序，通过填充空格来解决数独问题。

// 一个数独的解法需遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
// 空白格用 '.' 表示。

// [图片] http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png

// 一个数独。

// [图片] http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png

// 答案被标成红色。

// 提示：

// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。




class SolutionArray17 : public Solution{
public:	
	~SolutionArray17() {}

    virtual void solution() override {   
        // input_ = {4,3,2,7,8,2,3,1};
        // input_ = {2,2};
        input_ = {5,4,6,7,9,3,10,9,5,6};

		timer_.calc([this]() -> void* {
			output_ = findDisappearedNumbers(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " <<  vec2Str(input_) << std::endl;
        std::cout << "output : " << vec2Str(output_) << std::endl;
        timer_.dump();
    }

    //
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::vector<int> out;
        if(nums.empty()) return out;

        int size = nums.size();
        out.assign(size, 1);
        for(int i = 0; i < size; ++i) {
            if(out[nums[i] - 1]) {
                out[nums[i] - 1] = 0;
            }
        }
        int index = 0;
        for(int i = 1; i < size && index < size;) {
            if(out[index]) {
                out[index] = index+1;
                ++index;
                i = index;
            } else  {
                if(out[i]) {
                    out[i] = 0;
                    out[index] = i+1;
                    ++index;
                }
                ++i;
            }
        }
        out.erase(out.begin() + index, out.end());
        return out;
    }


private:
    std::vector<int> input_;
    std::vector<int> output_;
};



#endif //__ARRAY17_HPP__