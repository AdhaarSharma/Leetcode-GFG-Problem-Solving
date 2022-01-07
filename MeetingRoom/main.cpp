class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(),intervals.end(), [](const Interval& x, const Interval& y) { return x.start < y.start; });
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i].start < intervals[i-1].end)
                return false;
        }
        return true;
    }
};