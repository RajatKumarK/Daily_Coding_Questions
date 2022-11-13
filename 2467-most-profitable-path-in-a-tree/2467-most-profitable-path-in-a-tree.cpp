class Solution {
public:
    int func(vector<vector<int>>& v,vector<int>& pathb,vector<int>& amount, vector<bool>&visit, int ind, int indexb){
        int n = v[ind].size();
        int c=0;
        bool flag = false;
        int s;
        if(pathb.size()>indexb){
            flag = true;
            s = amount[pathb[indexb]];
            if(pathb[indexb]==ind){
                c = (amount[pathb[indexb]]/2);
                amount[pathb[indexb]]=0;
            }
            else{
                amount[pathb[indexb]]=0;
                c=amount[ind];
            }
            indexb++;
        }
        else{
            c=amount[ind];
            //c=0;
        }
        
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            if(visit[v[ind][i]]==false){
                visit[v[ind][i]]=true;
                res = max(res,func(v,pathb,amount,visit,v[ind][i],indexb));
                
            }
        }
        if(flag==true){
            indexb--;
            amount[pathb[indexb]] = s;
        }
        if(res==INT_MIN)
            return c;
        else
            return (c+res);
    }
    
    bool bpath(vector<vector<int>>& v,vector<int>& pathb, vector<bool>&visited, int ind) {
        if(ind==0){
            pathb.push_back(ind);
            return true;
        }
        else{
            for(int i=0;i<v[ind].size();i++){
                if(visited[v[ind][i]]==false){
                    visited[v[ind][i]]=true;
                    if(bpath(v,pathb,visited,v[ind][i])==true){
                       pathb.push_back(ind);
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> v(n);
        for(int i=0;i<n-1;i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> pathb;
        vector<bool> visited(n,false);
        visited[bob]=true;
        bool b = bpath(v,pathb,visited,bob);
        
        reverse(pathb.begin(),pathb.end());
        
        vector<bool> visit(n,false);
        visit[0]=true;
        return func(v,pathb,amount,visit,0,0);
        
    }
};