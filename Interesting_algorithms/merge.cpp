#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

Node* merge(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;

    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a) ? a : b;
    return dummy.next;
}

// Merge K sorted linked lists
Node* mergeKLists(vector<Node*>& lists) {
    if (lists.empty()) return nullptr;

    Node* res = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        res = merge(res, lists[i]);
    }
    return res;
}

int main() {
    // Input data
    vector<vector<int>> nums = {{1, 3, 5}, {1, 3, 4}, {2, 24, 24}};

    vector<Node*> lists;
    for (auto& arr : nums) {
        Node* head = new Node(arr[0]);
        Node* curr = head;
        for (int j = 1; j < arr.size(); j++) {
            curr->next = new Node(arr[j]);
            curr = curr->next;
        }
        lists.push_back(head);
    }

    // Merge all lists
    Node* ret = mergeKLists(lists);

    // Print merged list
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
