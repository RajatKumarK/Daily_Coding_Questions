class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        
        int n = nums.size();
        int i=0;
        while(i<n-2){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(a >= b+c){
                i++;
            }
            else
                return a+b+c;
        }
        
        return 0;
    }
};