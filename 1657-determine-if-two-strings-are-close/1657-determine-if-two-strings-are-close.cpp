class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<word1.length();i++)
            mp1[word1[i]]++;
        for(int i=0;i<word2.length();i++)
            mp2[word2[i]]++;
        unordered_map<int,int> count1,count2;
        for(auto x: mp1){
            if(mp2.find(x.first)==mp2.end())
                return false;
            count1[x.second]++;
        }
        for(auto x: mp2){
            count2[x.second]++;
        }
        for(auto x: count1){
            if(count2.find(x.first)==count2.end())
                return false;
            else if(count2[x.first]!=x.second)
                return false;
        }
        return true;
    }
};