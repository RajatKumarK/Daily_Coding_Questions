class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string res="";
        int n = s.length();
        for(int i=0;i<n;i++){
            if(!stk.empty() && stk.top()==s[i]){
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        while(!stk.empty()){
            res+= stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};