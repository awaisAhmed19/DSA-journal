#include <iostream>

using namespace std;

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverse(string& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left <= right) {
        swap(s[left], s[right]);
        right--;
        left++;
    }
}

int main() {
    string s;
    cin >> s;
    reverse(s);
    cout << "s:" << s;
    return 0;
}
