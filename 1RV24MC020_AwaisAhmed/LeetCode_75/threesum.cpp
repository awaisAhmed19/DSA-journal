#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    std::qsort(nums.begin(), nums.end());
    int j, k;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        j = i + 1;
        k = nums.size() - 1;
        while (j < k) {
            if (nums[j] + nums[k] + nums[i] < 0) {
                j++;
            } else if (nums[j] + nums[k] + nums[i] > 0) {
                k--;
            } else if (nums[j] + nums[k] + nums[i] == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return res;
}

int main() {
    vector a = {-1, 0, 1, 2, -1, -4};
    std::cout << threeSum(a);
    return 0;
}
