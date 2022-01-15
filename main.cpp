#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    // FIXME
    return 0;
  }
};

void TestThreeSumClosest() {
  Solution s;
  {
    vector<int> nums{-1,2,1,-4};
    assert(2 == s.threeSumClosest(nums, 1));
  }
  {
    vector<int> nums{0,0,0};
    assert(0 == s.threeSumClosest(nums, 1));
  }
}

int main() {
  TestThreeSumClosest();
  std::cout << "Ok!" << std::endl;
  return 0;
}
