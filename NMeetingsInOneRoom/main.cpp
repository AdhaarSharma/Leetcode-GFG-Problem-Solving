class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int f[], int n)
    {
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            a.push_back({f[i],s[i]});
        }
        sort(a.begin(), a.end());
        int count = 1;
        int prev = 0;
        for(int i=1; i<n; i++){
            if(a[i].second>a[prev].first){
                count++;
                prev = i;
            }
        }
        return count;
    }
};