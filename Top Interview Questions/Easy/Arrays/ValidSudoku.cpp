class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(!checkValid(i,j,board))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    //Function to check if the element has duplicates in that row, column and small 3*3 box
    bool checkValid(int r, int c, vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            if(i != c && board[r][i] == board[r][c])
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(i!=r && board[i][c] == board[r][c])
            {
                return false;
            }
        }
        int nr = r/3*3;
        int nc = c/3*3;
        int cnt = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[nr+i][nc+j] == board[r][c]) cnt++; 
            } 
        }
        return cnt == 1;
    }
};