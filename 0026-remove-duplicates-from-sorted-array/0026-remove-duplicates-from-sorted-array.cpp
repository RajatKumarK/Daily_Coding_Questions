class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        int j=1;
        int k=1;
        int prev = nums[0];
        while(j<n){
            if(prev==nums[j]){
                j++;
            }
            else{
                nums[i] = nums[j];
                prev = nums[j];
                i++;
                j++;
                k++;
            }
        }
        return k;
    }
};