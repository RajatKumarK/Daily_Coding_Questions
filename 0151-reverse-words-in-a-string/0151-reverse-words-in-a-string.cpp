class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        int n = s.length();
        for(int i=0;i<n;){
            while(i<n && s[i]==' '){
                i++;
            }
            int j = i;
            while(i<n  && s[i]!=' '){
                i++;
            }
            string res="";
            if(i!=j){
                for(int k=j;k<i;k++){
                    res+=s[k];
                }
                stk.push(res);
            }
            
        }
        string res="";
        while(!stk.empty()){
            res.append(stk.top());
            stk.pop();
            if(!stk.empty())
            res+=' ';
        }
        return res;
    }
};