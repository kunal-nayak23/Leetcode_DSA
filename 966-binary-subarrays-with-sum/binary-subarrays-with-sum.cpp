class Solution {
public:
    int fun(vector<int>& nums, int goal) {
        int l=0,r=0,sum=0,cnt=0;

        if(goal<0) return 0;

        while(r<nums.size()){
            sum = sum + nums[r];

            while(sum>goal){
                sum = sum - nums[l];
                l++;
            }

            cnt = cnt + (r-l+1);
            r++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal) - fun(nums,goal-1);
    }
};