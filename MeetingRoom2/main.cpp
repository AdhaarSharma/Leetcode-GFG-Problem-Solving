/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        vector<int> start(n), end(n);
        for(int i=0; i<n; i++){
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 0, j = 0;
        int count = 0;
        int res = 0;
        while(i!=n){
            if(start[i] < end[j]){
                count++;
                i++;
            } else {
                count--;
                j++;
            }
            res = max(res, count);
        }
        return res;
    }
};