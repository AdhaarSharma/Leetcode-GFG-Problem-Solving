class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        if (hFences.size() < vFences.size())
            swap(hFences, vFences);
        unordered_set<int> vsize(vFences.size()*(vFences.size() - 1)/2);
        for (unsigned i = 0; i < vFences.size(); ++i)
            for (unsigned j = i + 1; j < vFences.size(); ++j)
                vsize.insert(vFences[j] - vFences[i]);
        int maxs = -1;
        for (unsigned i = 0; i < hFences.size(); ++i)
            for (unsigned j = hFences.size(); --j > i; ) {
                auto s = hFences[j] - hFences[i];
                if (s <= maxs) break;
                if (vsize.count(s))
                    maxs = s;
            }
        return maxs > 0 ? ((int64_t)maxs)*maxs % (1000000000+7) : -1;
    }
};