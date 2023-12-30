class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // time = O(h^2 + v^2)
        // space = O(max(h,v) + min(h,v)^2)
        sort(hFences.begin(), hFences.end());
        hFences.reserve(hFences.size() + 2);
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        sort(vFences.begin(), vFences.end());
        vFences.reserve(vFences.size() + 2);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);
        if (hFences.size() < vFences.size())
            // reduce space
            swap(hFences, vFences);
        unordered_set<int> vsize(vFences.size()*(vFences.size() - 1)/2);
        for (unsigned i = 0; i < vFences.size(); ++i)
            for (unsigned j = i + 1; j < vFences.size(); ++j)
                vsize.insert(vFences[j] - vFences[i]);
        int maxs = -1;
        //for (auto h: hsize) cout << h << ' '; cout << endl;
        //for (auto h: vsize) cout << h << ' '; cout << endl;
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