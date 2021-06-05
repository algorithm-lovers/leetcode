class Solution {
public:
  string rotateOne(string s) {
    if (s == "") return "";
    char tmp = s[0];
    for (int i = 0; i < s.size() - 1; i++)
      s[i] = s[i + 1];
    s[s.size() - 1] = tmp;
    return s;
  }
  bool rotateString(string s, string goal) {
    for (int i = 0; i <= s.size(); i++) {
      s = rotateOne(s);
      if (s == goal) return true;
    }
    return false;
  }
};

// abcdef, tmp = a
// _bcdef
// s[0] = s[1], s[1] = '_' --> b_cdef
// s[1] = s[2], s[2] = '_' --> bc_def
// s[2] = s[3], s[3] = '_' --> bcd_ef
// s[3] = s[4], s[4] = '_' --> bcde_f
// s[4] = s[5], s[5] = '_' --> bcdef_
// s[5] = tmp
