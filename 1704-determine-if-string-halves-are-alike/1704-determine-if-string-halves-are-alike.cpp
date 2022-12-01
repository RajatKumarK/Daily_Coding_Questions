class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        unordered_set<char> st ={'a','e','i','o','u','A','E','I','O','U'};
        int count1=0, count2=0;
        for(int i=0;i<n/2;i++){
            if(st.find(s[i])!=st.end())
                count1++;
        }
        for(int i=n/2;i<n;i++){
            if(st.find(s[i])!=st.end())
                count2++;
        }
        return count1==count2;
    }
};