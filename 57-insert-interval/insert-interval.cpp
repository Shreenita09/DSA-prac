class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int n=intervals.size();
        //left portion, ending of old<starting of new
        while(i<n && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        //middle portion starting of old<ending of new
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;

        }
        res.push_back(newInterval);

        //right , whatever left keep adding
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
    
};