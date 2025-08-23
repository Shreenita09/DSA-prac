class Solution {
public:
    //Kadane algo
    int maxSubArray(vector<int>& nums) {
       int sum=0;
       int maxsum=INT_MIN;
       int n=nums.size();
       for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum>maxsum){
            maxsum=sum;
        }
        if(sum <0){
            sum=0;
        }
       }
       return maxsum;
    }
};
    