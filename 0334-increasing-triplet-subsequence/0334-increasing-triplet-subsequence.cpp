class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return false;
        vector<int> lmin(n);
        vector<int> rmax(n);
        int cmin=nums[0];
        int cmax=nums[n-1];
        for(int i=0;i<n;i++){
            cmin=min(cmin,nums[i]);
            lmin[i]=cmin;
        }
        for(int i=n-1;i>=0;i--){
            cmax=max(cmax,nums[i]);
            rmax[i]=cmax;
        }
        for(int i=1;i<n-1;i++){
            if(lmin[i]<nums[i] && rmax[i]>nums[i]){
                return true;
            }
        }
        return false;
    }
};