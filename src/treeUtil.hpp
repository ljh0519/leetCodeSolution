#ifndef __TREE_UTIL_HPP__
#define __TREE_UTIL_HPP__

#include <vector>
#include <string>
#include <queue>

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int x) : val(x) {}

    static
    TreeNode* Create(const std::vector<std::string>& nums) {
        if(nums.empty()
        || 1 == nums.size() && "#" == nums[0]) {
            return nullptr;
        }

        std::queue<TreeNode*> queue;
        int size = nums.size();
        TreeNode* root = new TreeNode(atoi(nums[0].c_str()));
        queue.push(root);
        for(int i = 1; i < size; ) {
            auto node = queue.front();
            queue.pop();
            if(i < size && nums[i] != "#") {
                node->left = new TreeNode(atoi(nums[i].c_str()));
                queue.push(node->left);
                ++i;
            }
            if(i < size && nums[i] != "#") {
                node->right = new TreeNode(atoi(nums[i].c_str()));
                queue.push(node->right);
                ++i;
            }
        }

        return root;
    }

    static
    void Free(TreeNode** tree) {
        if(!tree || !*tree) {
            return ;
        }
        //前序遍历销毁二叉树

        std::vector<TreeNode*> stack;
        stack.emplace_back(*tree);
        while(!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            if(node->right) {
                stack.emplace_back(node->right);
                node->right = nullptr;
            }
            if(node->left) {
                stack.emplace_back(node->left);
                node->left = nullptr;
            }
            std::cout << node->val << std::endl;
            delete node;
            node = nullptr;
        }
        *tree = nullptr;
    }
};








#endif 