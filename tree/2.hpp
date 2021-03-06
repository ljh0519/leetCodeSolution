#ifndef __BINARY_TREE_2_HPP__
#define __BINARY_TREE_2_HPP__

#include "solution.hpp"
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

//  

// 示例：
// 二叉树：[3,9,20,null,null,15,7],

//    _3_ 
//   |   |
//   9  _20_
//     |    |
//     15   7
//

//    ____3____ 
//   |         |
//  _9_       _20_
// |   |     |    |
// 1   11   15    7

//    ____3____ 
//   |         |
//  _9_       _20_
// |   |     |    |
// 1   11   15    7




// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],    
//   [15,7]
// ]


class SolutionTree2 : public Solution{
public:	
	~SolutionTree2() {
        if(input_) {
            TreeNode::Free(&input_);
        }
    }

    virtual void solution() override {

        // param_ = {"3"};
        // param_ = {};

        //可能有隐患
        X_SOLUTION_TEST(std::vector<std::vector<int>>({{3}, {9,20}, {15,7}}), param_ = {"3","9","20","#","null","15","7"}, input_ = TreeNode::Create(param_));

    }

    void test(std::vector<std::vector<int>>&& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
			output_ = levelOrder(input_);
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
        std::cout << "input : " << vec2Str(param_) << std::endl;
    }

    virtual void dumpOutput() override {
        std::cout << "output : " << std::endl;
        for(int i = 0 ; i < output_.size(); ++i) {
            std::cout << vec2Str(output_[i]) << std::endl;
        }
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }


    //迭代
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> out;
        if(!root) {
            return out;
        }

        std::queue<TreeNode*> queue;
        int now_level = 1;
        int next_level = 0;
        queue.push(root);
        std::vector<int> level;
        while(!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            --now_level;
            level.emplace_back(node->val);
            if(node->left) {
                queue.push(node->left);
                ++next_level;
            }
            if(node->right) {
                queue.push(node->right);
                ++next_level;
            }

            if(0 == now_level) {
                out.push_back(level);
                level.clear();
                now_level = next_level;
                next_level = 0;
            }
        }

        return out;
    }

private:
    std::vector<std::string> param_;
    TreeNode* input_;
    std::vector<std::vector<int>> output_;
};




#endif //__BINARY_TREE_2_HPP__