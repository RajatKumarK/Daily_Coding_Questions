class Solution {
public:
    bool func(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int curr, int m, int n, int i, int j){
        if(curr==word.length())
            return true;
        
        if(i+1<m && board[i+1][j]==word[curr] && visit[i+1][j]==false){
            visit[i+1][j]=true;
            if(func(board,word,visit,curr+1,m,n,i+1,j))
                        return true;
            visit[i+1][j]=false;
        }
        if(j+1<n && board[i][j+1]==word[curr] && visit[i][j+1]==false){
            visit[i][j+1]=true;
            if(func(board,word,visit,curr+1,m,n,i,j+1))
                        return true;
            visit[i][j+1]=false;
        }
        if(i-1>=0 && board[i-1][j]==word[curr] && visit[i-1][j]==false){
            visit[i-1][j]=true;
            if(func(board,word,visit,curr+1,m,n,i-1,j))
                        return true;
            visit[i-1][j]=false;
        }
        if(j-1>=0 && board[i][j-1]==word[curr] && visit[i][j-1]==false){
            visit[i][j-1]=true;
            if(func(board,word,visit,curr+1,m,n,i,j-1))
                        return true;
            visit[i][j-1]=false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>> visit(m,vector<bool>(n,false));
                    visit[i][j]=true;
                    
                    if(func(board,word,visit,1,m,n,i,j))
                        return true;
                }
            }
        }
        return false;
    }
};