class Solution {
public:
    int func(int a){
        if(a<=2){
            return 0;
        }
        else if(a<=5){
            return 3;
        }
        else
            return 6;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                else{
                    int n = (int)(board[i][j])-48;
                    
                    for(int a=0;a<9;a++){
                        if(board[i][a]!='.' && a!=j){
                            if(n==((int(board[i][a]))-48)){
                                return false;
                            }
                        }
                        if(board[a][j]!='.' && a!=i){
                            if(n==((int(board[a][j]))-48)){
                                return false;
                            }
                        }
                    }
                    
                    int p=func(i);
                    int q=func(j);
                    for(int a=p;a<p+3;a++){
                        for(int b=q;b<q+3;b++){
                            if(a==i && b==j){
                                continue;
                            }
                            else if(board[a][b]!='.' ){
                                if(n==((int(board[a][b]))-48)){
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};