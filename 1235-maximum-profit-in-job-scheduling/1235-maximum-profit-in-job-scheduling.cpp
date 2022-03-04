class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs(n);
        for(int i=0; i<n; i++){
            int x = startTime[i];
            int y = endTime[i];
            int z = profit[i];
            jobs[i] = {x,y,z};
        }
        sort(jobs.begin(),jobs.end(),[](vector<int>a, vector<int>b){
            return a[1] < b[1];
        });
        int dp[n];
        dp[0]=jobs[0][2];
        for(int i=1; i<n; i++){
            int incl = jobs[i][2];
            int last = -1;
            int low = 0;
            int high = i-1;
            while(low<=high){
                int mid = (low+high)>>1;
                if(jobs[mid][1] <= jobs[i][0]){
                    last = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            if(last!=-1)
                incl+=dp[last];
            int excl = dp[i-1];
            dp[i] = max(incl,excl);
        }
        return dp[n-1];
    }
};