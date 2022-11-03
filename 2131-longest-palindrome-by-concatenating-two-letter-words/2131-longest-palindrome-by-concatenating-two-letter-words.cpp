class Solution {
    string reverse(string s){
        string ans = "";
        for(int i=s.length()-1;i>=0;i--){
            ans+=s[i];
        }
        return ans;
    }
    int max(int a,int b){
        return ((a>b)?a:b);
    }
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        int ans = 0;
        // map<string,int>::iterator itr;
        for(auto i= mp.begin();i!=mp.end();i++){
            string s = i->first;
            string r = reverse(s);
            if(mp[r]>0 && r!=s){
                int miniC = min(mp[s],mp[r]);
                ans+=2*s.length()*miniC;
                mp[r]-=miniC;
                mp[s]-=miniC;                
            }
           else if(mp[i->first]>0 && reverse(i->first)==(i->first)){
                int lC = 2*(mp[s]/2);
                ans +=lC*s.length();
                mp[r]-=lC;
            }
            // cout<<ans<<"*";
        }
        int maxi = INT_MIN;
        for(auto i=mp.begin();i!=mp.end();i++){
            // string s = i->first;
            // string r = reverse(s);
            if(mp[i->first]>0 && reverse(i->first)==(i->first)){
                maxi = max(maxi,(i->first).length());
            }
        }
        ans+=(maxi==INT_MIN?0:maxi);
        return ans;
    }
};