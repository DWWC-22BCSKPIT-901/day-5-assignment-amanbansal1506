#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-Heap to store the nodes
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap: smaller value has higher priority
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // Push the head of each list into the priority queue
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // While the priority queue is not empty, extract the smallest element
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            current->next = node;
            current = current->next;
            
            // If the extracted node has a next node, push it into the queue
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<ListNode*> lists;
    
    // Create multiple linked lists
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));
    
    Solution sol;
    ListNode* mergedList = sol.mergeKLists(lists);
    
    // Print the merged linked list
    printList(mergedList);
    
    return 0;
}
