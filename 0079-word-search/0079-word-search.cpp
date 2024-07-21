class Solution {
public:
    
      bool solve(vector<vector<char>>& board,string word,int i,int j,int k,vector<vector<int>>& visited)
        {
           int n = board.size();
        int m = board[0].size();
            if(i<0 || j<0 ||i>=n||j>=m|| board[i][j]!=word[k] || visited[i][j]==1)
            {
                return false;
            }
          
          if(k==word.length()-1)return true;
          
            visited[i][j]=1;
          if(solve(board,word,i+1,j,k+1,visited)||solve(board,word,i-1,j,k+1,visited)||solve(board,word,i,j+1,k+1,visited)||solve(board,word,i,j-1,k+1,visited))  return true;
          
          visited[i][j]=0;
          return false;
        }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if (board[i][j] == word[0])
                {
                   if(solve(board,word,i,j,0,visited))
                       return true;
                }
            }
        }
       return false;
    }
};