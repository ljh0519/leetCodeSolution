
#ifndef __ARRAY15_HPP__
#define __ARRAY15_HPP__

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




class SolutionArray15 : public Solution{
public:	
	~SolutionArray15() {}

    virtual void solution() override {   
        X_SOLUTION_TEST(std::vector<std::vector<char>>({
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
                }), input_ = {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
                });
    
        X_SOLUTION_TEST(std::vector<std::vector<char>>({
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
                }), input_ = {
                {'8','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
                });

    }

    void test(std::vector<std::vector<char>>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			solveSudoku(input_);
            return nullptr;
		});

        dumpInput();
        dumpOutput();
        if(expect != input_) {
            std::cout << "expect != output" << std::endl;
            std::cout << "failed test!." << std::endl;
            exit(0);
        }
    }

    virtual void dumpInput() override {
        std::cout << "input : " << std::endl;
        for(auto& str : input_) {
            std::cout << vec2Str(str, ",") << std::endl;
        }
    }

    virtual void dumpOutput() override {
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

    //
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solveSudokuRecu(board,  0);
    }

private:
    bool solveSudokuRecu(std::vector<std::vector<char>>& board, char index) {
        if(81 == index) return true;

        char row = index / 9;
        char column = index % 9;
        if('.' != board[row][column]) {
            return solveSudokuRecu(board, index+1);
        }

        for(int i = 0; i < 9; ++i) {
            if(checkValidSudoku(board, row, column, i+'1')) {
                board[row][column] = i+'1';
                if(solveSudokuRecu(board, index+1)) {   
                    return true;
                }
                board[row][column] = '.';
            }
        }

        return false;
    }

    bool checkValidSudoku(std::vector<std::vector<char>>& board, int row, int column, char chr) {
        int lattice_row = row >= 6 ? 6 : (row >= 3 ? 3 : 0);
        int lattice_column = column >= 6 ? 6 : (column >= 3 ? 3 : 0);
        for(int i = 0; i < 9; ++i) {
            if(chr == board[row][i]
            || chr == board[i][column]
            || chr == board[lattice_row + i/3][lattice_column + i%3]) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<std::vector<char>> input_;
    int     output_;
};



#endif //__ARRAY15_HPP__