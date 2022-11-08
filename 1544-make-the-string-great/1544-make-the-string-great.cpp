class Solution {
public:
    string makeGood(string s) {
        int l = s.length();
        stack<char> stk;
        for(int i=0;i<l;i++){
            if(!stk.empty() &&(abs(stk.top()-s[i])==32)){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        string res="";
        while(!stk.empty()){
            res+= stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};