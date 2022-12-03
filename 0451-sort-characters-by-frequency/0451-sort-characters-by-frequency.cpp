class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        multimap<int,char> mp2;
        for(auto &x: mp){
            mp2.insert({x.second,x.first});
        }
        string res="";
        for(auto &x: mp2){
            for(int i=0;i<x.first;i++)
                res += x.second;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};