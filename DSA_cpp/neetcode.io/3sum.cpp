#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for (int i : nums) {
            cout << i << " ";
        }
        return output;
    }
};
ostream& operator<<(ostream& os, const vector<vector<int>>& af) {
    for (const auto& a : af) {
        os << "[ ";
        for (int b : a) {
            os << b << " ";
        }
        os << "]";

        return os;
    }
    int main() {
        Solution s;

        vector<int> af = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> a = s.threeSum(af);
        cout << a << endl;
    }
