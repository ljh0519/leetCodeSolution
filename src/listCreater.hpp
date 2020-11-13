#ifndef __LISTCREATER_HPP__
#define __LISTCREATER_HPP__

#include <vector>
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class ListCreater {
public:
	static
	ListNode* generateNewList(std::vector<int>&& vec) {
		if (vec.empty()) {
			return nullptr;
		}
		ListNode* first = nullptr;
		ListNode* node = nullptr;
		for (auto i : vec) {
			if (!first) {
				first = new ListNode();
				node = first;
			}
			else {
				node->next = new ListNode();
				node = node->next;
			}
			node->val = i;
		}
		return first;
	}

	static
	void dump(ListNode* list) {
		if (!list) {
			return;
		}

		for (auto node = list; node != nullptr; node = node->next) {
			std::cout << node->val << "->";
		}
		std::cout << "null" << std::endl;
	}


	static
	void free(ListNode** pnode) {
		if (!pnode) {
			return;
		}
		for (auto node = *pnode; node != nullptr; ) {
			auto next = node->next;
			delete node;
			node = next;
		}
		
		*pnode = nullptr;
	}
};








#endif //__LISTCREATER_HPP__