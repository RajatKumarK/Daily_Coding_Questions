class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int r = n-1;
        int l = 0;
        bool fl=false;
        bool fr=false;
        int i;
        while(l<r){
            i = l;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
              fl = true;
            }
            i = r;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
              fr = true;
            }
            if(fl&&fr){
                char t = s[r];
                s[r] = s[l];
                s[l] = t;
                r--;
                l++;
                fr=false;
                fl=false;
            }
            else if(fl){
                r--;
            }
            else if(fr){
                l++;
            }
            else{
                r--;
                l++;
            }
            
        }
        
        
        return s;
    }
};