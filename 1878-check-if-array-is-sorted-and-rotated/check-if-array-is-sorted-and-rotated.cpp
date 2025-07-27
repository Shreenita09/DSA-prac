class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] > nums[(i+1)%n] && ++count > 1) return false; // Loop through the array.

 //Compare each element with the next (wrap around using (i+1)%n).

// Count how many times nums[i] > nums[(i+1)%n].

   // If the count is more than 1, return false. Else, return true
        return true;
    }
};