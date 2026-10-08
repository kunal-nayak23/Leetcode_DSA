class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high=x;
        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;

            if((long long)mid*mid<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};