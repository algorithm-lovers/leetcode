class Solution {
public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size()) return false;
    int diff = 0;
    vector<int> v;
    set<char> se;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != goal[i]) {
        diff++;
        v.push_back(i);
      }
      se.insert(s[i]);
    }
    if (diff == 0) return se.size() < s.size();
    if (diff == 2) {
      swap(s[v[0]], s[v[1]]);
      return s == goal;
    }
    return false;
  }
};

// TH1: s.size() != goal.size() --> false
// TH2:
// s = aabcd
// aa (01), ab (02), ac (03), ad (04)
// ab (12), ac (13), ad (14)
// bc (23), bd (24)
// cd (34)

/* 
Step 1:
  for i in [0, s.size() - 2], j in [i + 1, s.size() - 1]:
    B1: swap(s[i], s[j])
    B2: if (s == goal) return true;
    B3: swap(s[i], s[j])
Step 2:
  When for loop ends: return false;
*/

// TH3:
// Neu co 0 vi tri khac nhau: neu co 2 ki tu trung nhau --> return true, nguoc lai return false
// Neu co 1 vi tri khac nhau --> return false
// Neu co 2 vi tri khac nhau --> doi 2 vi tri cho nhau, sau do kiem tra s == goal ? true : false
// Neu co tren 2 vi tri khac nhau --> return false