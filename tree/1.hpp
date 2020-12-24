#ifndef __BINARY_TREE_1_HPP__
#define __BINARY_TREE_1_HPP__

#include "solution.hpp"



//括号 成对 
class SolutionTree1 : public Solution {
public:
	~SolutionTree1() {
        // if(input_) {
        //     TreeNode::Free(&input_);
        // }
    }

    virtual void solution() override {

        // param_ = {"3","9","20","#","null","15","7"};
        // param_ = {"3"};
        // param_ = {};
        // param_ = {"3","#","#","#","null","15","7"};

        // input_ = TreeNode::Create(param_);
		// timer_.calc([this]() -> void* {
		// 	output_ = levelOrder(input_);
        //     return nullptr;
		// });
    }

    // void test(std::vector<int>& expect) {
    //     dumpInput();

	// 	timer_.calc([this]() -> void* {
	// 		output_ = nextGreaterElement(input1_, input2_);
    //         return nullptr;
	// 	});

    //     dumpOutput();
    //     if(expect != output_) {
    //         std::cout << "expect != output"  << std::endl;
    //         std::cout << "failed test!." << std::endl;
    //         exit(0);
    //     }
    // }

    virtual void dumpInput() override {
    //     std::cout << "input : " << vec2Str(param_) << std::endl;
    }

    virtual void dumpOutput() override {
    //     std::cout << "output : " << std::endl;
    //     for(int i = 0 ; i < output_.size(); ++i) {
    //         std::cout << vec2Str(output_[i]) << std::endl;
    //     }
    //     timer_.dump();
    //     std::cout << "###################################################" << std::endl;
    }

	// // 非递归
	// std::vector<std::string> generateParenthesis(int n) {
	// 	arr.clear();
	// 	if (n <= 0) {
	// 		return arr;
	// 	}

	// 	std::vector<TreeNode> stack;
	// 	stack.emplace_back(Node({n-1, n, "("}));
		
	// 	while (true != stack.empty()) {
	// 		auto node = stack.back();
	// 		stack.pop_back();
	// 		if (0 == node.left && 0 == node.right) {
	// 			arr.emplace_back(node.str);
	// 			continue;
	// 		}

	// 		if (node.left > 0) {
	// 			stack.emplace_back(Node({ node.left - 1, node.right, node.str + "(" }));
	// 		}
	// 		if (node.right > 0 && node.left < node.right) {
	// 			stack.emplace_back(Node({ node.left, node.right - 1, node.str + ")" }));
	// 		}
	// 	}
	// 	return arr;
	// }



	// // 递归版本
	// std::vector<std::string> generateParenthesis(int n) {
	// 	arr.clear();
	// 	if (n <= 0) {
	// 		return arr;
	// 	}
		
	// 	generateLegalArr(n, n, std::string());
	// 	return arr;
	// }

	// void generateLegalArr(int left, int right, std::string str) {
	// 	if (0 == left && 0 == right) {
	// 		arr.emplace_back(str);
	// 		return;
	// 	}

	// 	if (left > 0) {
	// 		generateLegalArr(left - 1, right, str + "(");
	// 	}
	// 	if (right > 0 && left < right) {
	// 		generateLegalArr(left, right - 1, str + ")");
	// 	}
	// }
private:
	std::vector<std::string> arr;
};


#endif //__BINARY_TREE_1_HPP__