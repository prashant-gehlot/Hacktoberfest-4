// LC 252. Meeting Rooms
/*
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true

*/

// TC - O(NlogN), SC - O(1)

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int, int> m;
        for(int i = 0; i < intervals.size(); ++i){
			m[intervals[i].start] = intervals[i].end; 
		}
		if(m.size() < intervals.size()) return false; 
		int tmp = 0;
		for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){ 
        if(tmp > it->first) return false;
        tmp = it->second;
        }
        return true;
    }
};
