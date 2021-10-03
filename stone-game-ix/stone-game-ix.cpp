class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for (int a: stones)
            cnt[a % 3]++;
        if (min(cnt[1], cnt[2]) == 0)
            return max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 > 0;
        return abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
    }
};