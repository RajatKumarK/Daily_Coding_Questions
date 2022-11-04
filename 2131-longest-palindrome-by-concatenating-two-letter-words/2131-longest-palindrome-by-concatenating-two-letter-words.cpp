class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        unordered_map<string,int> same;
        int n = words.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(words[i][0]!=words[i][1]){
                mp[words[i]]++;
            }
            else{
                same[words[i]]++;
            }
        }
        for(auto &x: mp){
            string t="";
            t+=x.first[1];
            t+=x.first[0];
            if(mp.find(t)!=mp.end()){
                res+= min(x.second,mp[t]);
            }
        }
        res*=2;
        bool odd=false;
        for(auto &x: same){
            if(odd){
                if(x.second%2==1){
                    res+= 2*(x.second-1);
                }
                else{
                    res+= 2*(x.second);
                }
            }
            else{
                if(x.second%2==1){
                    odd=true;
                }
                res+= 2*(x.second);
            }
            
        }
        return res;
    }
};