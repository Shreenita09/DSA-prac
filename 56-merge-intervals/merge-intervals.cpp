class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> curr=intervals[0];
        for(int i=0;i<n;i++) {
            if(intervals[i][0]<=curr[1]){
                curr[1]=max(curr[1],intervals[i][1]);
                curr[0]=min(curr[0],intervals[i][0]);
                //already sorted, so starting point u know,just see ending point
            }
            else{
                res.push_back(curr);
                curr=intervals[i];
            }
        }
        res.push_back(curr);
        return res; 
    }
};