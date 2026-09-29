class Solution {
public:
    int fun(vector<int>& nums, int goal) {
        int l=0,r=0,sum=0,cnt=0;

        if(goal<0) return 0;

        while(r<nums.size()){
            sum = sum + (nums[r] % 2);

            while(sum>goal){
                sum = sum - (nums[l] % 2);
                l++;
            }

            cnt = cnt + (r-l+1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};