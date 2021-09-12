class Solution {
public:
    int palSize(string &s, int mask) {
    int p1 = 0, p2 = s.size(), res = 0;
    while (p1 <= p2) {
        if ((mask & (1 << p1)) == 0)
            ++p1;
        else if ((mask & (1 << p2)) == 0)
            --p2;
        else if (s[p1] != s[p2])
            return 0;
        else
            res += 1 + (p1++ != p2--);
    }
    return res;
}
int maxProduct(string s) {
    int dp[4096] = {}, res = 0, mask = (1 << s.size()) - 1;
    for (int m = 1; m <= mask; ++m)
        dp[m] = palSize(s, m);
    for (int m1 = mask; m1; --m1)
        if (dp[m1] * (s.size() - dp[m1]) > res)
            for(int m2 = mask ^ m1; m2; m2 = (m2 - 1) & (mask ^ m1))
                res = max(res, dp[m1] * dp[m2]);
    return res;
}
};