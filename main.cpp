#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    int closest;
    sort(nums.begin(), nums.end());
    int minDist = numeric_limits<int>::max();
    for (size_t i = 0; i < nums.size(); ++i) {
      const int a = nums[i];
      const int target2 = target - a;
      const int sum2 = twoSumClosest(nums, i + 1, target2);
      const int dist = abs(target2 - sum2);
      if (0 == dist) { return target; }
      else {
        if (dist < minDist) {
          closest = sum2 + a;
          minDist = dist;
        }
      }
    }

    return closest;
  }

  int twoSumClosest(vector<int> &nums, size_t offset, int target) {
    int closest;
    size_t right = nums.size() - 1;
    int minDist = numeric_limits<int>::max();
    while (offset < right) {
      int sum = nums[offset] + nums[right];
      int dist = abs(target - sum);
      if (0 == dist) {
        return target;
      } else {
        if (dist < minDist) {
          closest = sum;
          minDist = dist;
        }
        if (sum < target) { ++offset; }
        else { --right; }
      }
    }

    return closest;
  }
};

void TestThreeSumClosest() {
  Solution s;
  {
    vector<int> nums{-1, 2, 1, -4};
    assert(2 == s.threeSumClosest(nums, 1));
  }
  {
    vector<int> nums{0, 0, 0};
    assert(0 == s.threeSumClosest(nums, 1));
  }
}

int main() {
  TestThreeSumClosest();
  std::cout << "Ok!" << std::endl;
  return 0;
}
