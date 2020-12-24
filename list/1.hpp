#ifndef __LIST1_HPP__
#define __LIST1_HPP__

#include <map>
#include "solution.hpp"
// 升序合并多个链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class SolutionList1 : public Solution {
public:
    virtual void solution() override {

    }

    void test(std::vector<int>& expect) {
        dumpInput();

		timer_.calc([this]() -> void* {
            return nullptr;
		});

        dumpOutput();
        // if(expect != output_) {
        //     std::cout << "expect != output"  << std::endl;
        //     std::cout << "failed test!." << std::endl;
        //     exit(0);
        // }
    }

    virtual void dumpInput() override {
    }

    virtual void dumpOutput() override {
        timer_.dump();
        std::cout << "###################################################" << std::endl;
    }

	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}

		std::multimap<int, ListNode*> map;
		for (auto list : lists) {
			for (auto node = list; node != nullptr; node = node->next) {
				map.emplace(std::pair<int, ListNode*>({ node->val, node }));
			}
		}
		
		if (map.empty()) {
			return nullptr;
		}

		ListNode* first = nullptr;
		ListNode* list_node = nullptr;
		{
			auto it = map.begin();
			first = first = it->second;
			list_node = list_node = first;
			map.erase(it);
		}

		while (true != map.empty()) {
			auto it = map.begin();
			list_node->next = it->second;
			list_node = list_node->next;
			map.erase(it);
		}

		return first;
	}
private:
};


#endif //__LIST1_HPP__