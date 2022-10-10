class Solution {
public:
    string breakPalindrome(string str) {
        if(str.length()==1){
            return "";
        }
        int n = str.length();
        int count=0;
        int i=0;
        while(i<n){
            if(str[i]!='a')
                break;
            i++;
            count++;
        }
        if(count==n||(n%2!=0 && count==n/2)){
            str[n-1]='b';
            return str;
        }
        str[count]='a';
        return str;
    }
};
/*
"Anna"
"civic"
"kayak"
"level"
"madam"
"mom"
"noon"
"racecar"
"radar"
"redder"
"refer"
"repape"
*/