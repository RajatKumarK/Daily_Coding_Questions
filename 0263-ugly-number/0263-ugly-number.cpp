class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        int d = 2;
        while(n!=1){
            if(n%d==0){
                if(d==2 || d==3 || d==5)
                    n/=d;
                else
                    return false;
            }
            else if(d>5)
                return false;
            else{
                d++;
            }
        }
        return true;
    }
};