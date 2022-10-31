class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        
        for(int i=m-1;i>0;i--){
            int a=i;
            int b=0;
            int init = mat[a][b];
            while(a<m&&b<n){
                if(mat[a][b]!=init){
                    return false;
                }
                a++;
                b++;
            }
        }
        for(int i=0;i<n;i++){
            int a=0;
            int b=i;
            int init = mat[a][b];
            while(a<m&&b<n){
                if(mat[a][b]!=init){
                    return false;
                }
                a++;
                b++;
            }
        }
        return true;
    }
};