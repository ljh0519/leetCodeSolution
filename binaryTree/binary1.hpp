#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

//括号 成对 
//class Solution {
//public:
	//struct Node {
	//	const int left;
	//	const int right;
	//	const std::string str;
	//};

	//非递归
	//std::vector<std::string> generateParenthesis(int n) {
	//	arr.clear();
	//	if (n <= 0) {
	//		return arr;
	//	}

	//	std::vector<Node> stack;
	//	stack.emplace_back(Node({n-1, n, "("}));
	//	
	//	while (true != stack.empty()) {
	//		auto node = stack.back();
	//		stack.pop_back();
	//		if (0 == node.left && 0 == node.right) {
	//			arr.emplace_back(node.str);
	//			continue;
	//		}

	//		if (node.left > 0) {
	//			stack.emplace_back(Node({ node.left - 1, node.right, node.str + "(" }));
	//		}
	//		if (node.right > 0 && node.left < node.right) {
	//			stack.emplace_back(Node({ node.left, node.right - 1, node.str + ")" }));
	//		}
	//	}
	//	return arr;
	//}









	//递归版本
	//std::vector<std::string> generateParenthesis(int n) {
	//	arr.clear();
	//	if (n <= 0) {
	//		return arr;
	//	}
	//	
	//	generateLegalArr(n, n, std::string());
	//	return arr;
	//}

	//void generateLegalArr(int left, int right, std::string str) {
	//	if (0 == left && 0 == right) {
	//		arr.emplace_back(str);
	//		return;
	//	}

	//	if (left > 0) {
	//		generateLegalArr(left - 1, right, str + "(");
	//	}
	//	if (right > 0 && left < right) {
	//		generateLegalArr(left, right - 1, str + ")");
	//	}
	//}
//private:
//	std::vector<std::string> arr;
//};



#endif //__BINARY_TREE_HPP__