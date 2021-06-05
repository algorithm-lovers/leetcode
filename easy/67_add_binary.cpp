class Solution {
public:
  string addBinary(string a, string b) {
    int len = max(a.size(), b.size());
    while (a.size() < len)
      a = "0" + a;
    while (b.size() < len)
      b = "0" + b;
    string res = "";
    int rem = 0;
    for (int i = len - 1; i >= 0; i--) {
      int tmpa = a[i] - '0';
      int tmpb = b[i] - '0'; 
      if (tmpa + tmpb + rem == 0) {
        res = "0" + res;
        rem = 0;
      }
      else if (tmpa + tmpb + rem == 1) {
        res = "1" + res;
        rem = 0;
      }
      else if (tmpa + tmpb + rem == 2) {
        res = "0" + res;
        rem = 1;
      }
      else if (tmpa + tmpb + rem == 3) {
        res = "1" + res;
        rem = 1;
      }
    }
    if (rem == 1) res = "1" + res;
    return res;
  }
};

// Luu y: if block se chay lien tuc qua cac dieu kien, nen phai co continue hoac them
// TODO: refactor
// else

//    1010
//  + 1011
//   ------
//   10101
     
// B1: 0 + 1 + rem = 1 --> res = 1, rem = 0;
//    B2: 1 + 1 + rem = 2 --> res = 01, rem = 1;
//    B3: 0 + 0 + rem = 1 --> res = 101, rem = 0;
//    B4: 1 + 1 + rem = 2 --> res = 0101, rem = 1;
