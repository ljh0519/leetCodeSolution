
#ifndef __ARRAY14_HPP__
#define __ARRAY14_HPP__

#include "memory.h"
#include "solution.hpp"

// 36. 有效的数独

// 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


// 上图是一个部分填充的有效的数独。

// 数独部分空格内已填入了数字，空白格用 '.' 表示。

// 示例 1:

// 输入:
// [
//   [5,3,.|,.,7,.|,.,.,.],
//   [6,.,.|,1,9,5|,.,.,.],
//   [.,9,8|,.,.,.|,.,6,.],
// --------+------+---------
//   [8,.,.|,.,6,.|,.,.,3],
//   [4,.,.|,8,.,3|,.,.,1],
//   [7,.,.|,.,2,.|,.,.,6],
// --------+------+---------
//   [.,6,.|,.,.,.|,2,8,.],
//   [.,.,.|,4,1,9|,.,.,5],
//   [.,.,.|,.,8,.|,.,7,9]
// ]
// 输出: true


// 示例 2:

// 输入:
// [
//   [8,3,.,.,7,.,.,.,.],
//   [6,.,.,1,9,5,.,.,.],
//   [.,9,8,.,.,.,.,6,.],
//   [8,.,.,.,6,.,.,.,3],
//   [4,.,.,8,.,3,.,.,1],
//   [7,.,.,.,2,.,.,.,6],
//   [.,6,.,.,.,.,2,8,.],
//   [.,.,.,4,1,9,.,.,5],
//   [.,.,.,.,8,.,.,7,9]
// ]
// 输出: false
// 解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//      但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
// 说明:

// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 给定数独序列只包含数字 1-9 和字符 '.' 。
// 给定数独永远是 9x9 形式的。




class SolutionArray14 : public Solution{
public:	
	~SolutionArray14() {}

    virtual void solution() override {   
        input_ = {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
                };
    
        // input_ = {
        //         {'8','3','.','.','7','.','.','.','.'},
        //         {'6','.','.','1','9','5','.','.','.'},
        //         {'.','9','8','.','.','.','.','6','.'},
        //         {'8','.','.','.','6','.','.','.','3'},
        //         {'4','.','.','8','.','3','.','.','1'},
        //         {'7','.','.','.','2','.','.','.','6'},
        //         {'.','6','.','.','.','.','2','8','.'},
        //         {'.','.','.','4','1','9','.','.','5'},
        //         {'.','.','.','.','8','.','.','7','9'}
        //         };
     

		timer_.calc([this]() -> void* {
			output_ = isValidSudoku(input_);
            return nullptr;
		});
    }

    virtual void dump() override {
        std::cout << "input : " << std::endl;
        for(auto& str : input_) {
            std::cout << vec2Str(str, ",") << std::endl;
        }
        std::cout << "output : " << output_ << std::endl;
        timer_.dump();
    }

    //36ms      可以继续优化，开辟3个9x9的cache，保存出现过的数，如果重复就返回false，这样只需要遍历依次棋盘
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {
            if(!isValidRow(board, i)) {
                return false;
            }
            if(!isValidColumn(board, i)) {
                return false;
            }
            if(0 == i%3 && !isValidLattice(board,i)) {
                return false;
            }
        }
        return true;
    }

private:
    bool isValidRow(std::vector<std::vector<char>>& board, int row) {
        const auto& row_data = board[row];
        char row_valid[9] = {};
        for(int i = 0; i < 9; ++i) {
            char index = row_data[i] - '1';
            if('.' == row_data[i]) {
                continue;
            }
            if(1 == row_valid[index]) {
                return false;
            }
            row_valid[index] = 1;
        }
        return true;
    }

    bool isValidColumn(std::vector<std::vector<char>>& board, int column) {
        char column_valid[9] = {};
        for(int j = 0; j < 9; ++j) {
            char index = board[j][column] - '1';
            if('.' == board[j][column]) {
                continue;
            }
            if(1 == column_valid[index]) {
                return false;
            }
            column_valid[index] = 1;
        }
        return true;
    }

    bool isValidLattice(std::vector<std::vector<char>>& board, int row) {
        char lattice[9] = {};
        for(int i = 0; i < 3; ++i) {
            for(int j = i*3; j < (i+1)*3; ++j) {
                for(int m = 0; m < 3; ++m) {
                    char index = board[row+m][j] - '1';
                    if('.' == board[row+m][j]) {
                        continue;
                    }
                    if(1 == lattice[index]) {
                        return false;
                    }
                    lattice[index] = 1;
                }
            }
            memset(lattice, 0x0, 9);
        }
        return true;
    }

private:
    std::vector<std::vector<char>> input_;
    int     output_;
};



#endif //__ARRAY14_HPP__