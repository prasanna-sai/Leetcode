class Solution {
public:
    int rowMax;
    int celMax;
    
    bool exist(vector<vector<char>>& board, string word) {
        rowMax = board.size();
        celMax = board[0].size();
                
        for (int i=0; i< rowMax; i++) {
            for (int j=0; j< celMax; j++) {
                if(helper(i, j, board, word, 0)) {
                    return true; 
                }
            }
        }
        return false;
    }
    //Straight forward solution with backtracking
    bool helper(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        
        if (idx == word.length()) //if length matches it's true
            return true;
        
        if (i>= rowMax || i<0 || j>=celMax || j<0) //to check out of bounds
            return false;
        
        char target = word[idx]; //letter we need to match
        
        if (board[i][j] != target) { //If the letter didn't match
            return false;
        }
                
        board [i][j] = '*'; // flag to mark it as traversed

        //Now search for the surrounding elements
        if (helper(i-1, j, board, word, idx+1)) return true;
        if (helper(i+1, j, board, word, idx+1)) return true;
        if (helper(i, j-1, board, word, idx+1)) return true;
        if (helper(i, j+1, board, word, idx+1)) return true;
            
        board [i][j] = target; // reverse the marking
        
        return false;
    }
};