class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    set<int> s;
    int dup = 0, miss = 0;
    for (auto i : nums) {
      if (s.count(i)) {
        dup = i;
      } else {
        s.insert(i);
      }
    }
    for (int i = 1; i <= nums.size(); i++)
      if (!s.count(i)) miss = i;
    return {dup, miss};
  }
};
