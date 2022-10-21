class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> um;

        for(int i=0; i<nums.size(); i++){
            if(um.find(nums[i])==um.end()){
                um[nums[i]]=i;
            }else{
                auto itr = um.find(nums[i]);
                if((i-itr->second)<=k) return true;
                else{
                    itr->second = i;
                }
            }
        }

        return false;
    }
};