class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>>pq(nums.begin(), nums.end());
        while(n-k>0){
            pq.pop();
            k++;
        }
        return pq.top();
    }
};