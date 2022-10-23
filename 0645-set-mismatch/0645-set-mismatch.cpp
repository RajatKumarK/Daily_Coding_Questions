class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int> st;
        int d;
        int m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(st.find(nums[i])!=st.end()){
                d = nums[i];
            }
            else 
                st.insert(nums[i]);
        }
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                m = i;
                break;
            }
        }
        return {d,m};
        
    }
};