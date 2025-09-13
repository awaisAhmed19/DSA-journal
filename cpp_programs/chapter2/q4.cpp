#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

struct linkedlist {
    int val;
    linkedlist* next;
    linkedlist(int val) : val(val), next(nullptr) {};
};

void swap(int& a, int& b) {
    int tm = 0;
    tm = a;
    a = b;
    b = tm;
}

void sort(linkedlist* head) {
    if (head == nullptr) return;

    linkedlist* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->val > (temp->next)->val) {
            swap(temp->val, (temp->next)->val);
        }
        temp = temp->next;
    }
}

void print(linkedlist* head) {
    linkedlist* temp = head;
    while (temp != nullptr) {
        cout << " " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
}

bool detect_a_cycle(linkedlist* head) {
    linkedlist* sp = head;
    linkedlist* fp = head;
    while (fp != nullptr && fp->next != nullptr) {
        sp = sp->next;
        fp = fp->next->next;
        if (fp == sp) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(0));
    int n;
    cin >> n;

    linkedlist* head = nullptr;
    linkedlist* tail = nullptr;

    for (int i = 0; i < n; i++) {
        linkedlist* newnode = new linkedlist(rand() % 100);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    // tail->next = head;
    if (!detect_a_cycle(head)) {
        sort(head);
        print(head);
    } else {
        cout << "a cycle aexists ma";
    }
    return 0;
}
