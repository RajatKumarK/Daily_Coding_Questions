class Solution {
public:
    int nextGreaterElement(int n) {
        int t = n;
        int curr = t%10;
        t/=10;
        vector<int> v;
        v.push_back(curr);
        while(t!=0){
            int a = t%10;
            t/=10;
            v.push_back(a);
            if(a<curr){
                int j;
                int ind;
                for(int i=0;i<v.size()-1;i++){
                    if(v[i]>a){
                        ind = i;
                        break;
                    }
                }
                string nw = to_string(v[ind]);
                v[ind]=-1;
                sort(v.begin(),v.end());
                for(int i=1;i<v.size();i++){
                    nw+= (char)(v[i]+48);
                }
                string res = to_string(t);
                res+= nw;
                try{
                    return stoi(res);
                }
                catch(...){
                    return -1;
                }
                break;
            }
            curr = a;
        }
        
        return -1;
        
    }
};