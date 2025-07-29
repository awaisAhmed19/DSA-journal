#include <cctype>
#include <iostream>
using namespace std;

// void isPalindrome(string s) {
bool isPalindrome(string s) {
    string a = "";
    for (char &c : s) {
        if (isalnum(c)) {
            a.push_back(tolower(c));
        }
    }
    // std::cout << a;
    int i = 0;
    int j = a.length() - 1;
    while (i < j) {
        if (a[i] != a[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    string a = "0P";
    // isPalindrome(a);
    std::cout << isPalindrome(a);
    return 0;
}
