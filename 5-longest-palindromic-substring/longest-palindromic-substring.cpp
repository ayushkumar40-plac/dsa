class Solution {
public:
    bool solve(string &s, int i, int j) {
        if (i >= j) return true;
        if (s[i] != s[j]) return false;
        return solve(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 0;
        int sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    int len = j - i + 1;
                    if (len > maxlen) {
                        maxlen = len;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};