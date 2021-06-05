class Solution {
public:
  void duplicateZeros(vector<int>& arr) {
    vector<int> tmp;
    for (auto i : arr) {
      if (arr.size() > tmp.size())
        tmp.push_back(i);
      if (i == 0 && arr.size() > tmp.size()) tmp.push_back(0);
    }
    arr = tmp;
  }
};
