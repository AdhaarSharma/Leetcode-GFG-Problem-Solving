class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = S[i] == C ? 0 : n;
        for (int i = 1; i < n; ++i)
            res[i] = min(res[i], res[i - 1] + 1);
        for (int i = n - 2; i >= 0; --i)
            res[i] = min(res[i], res[i + 1] + 1);
        return res;
    }
};