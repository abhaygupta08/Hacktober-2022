class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col]=='.') // if blank put character ad validate in nex instruction
                {
                    for(char c='1';c<='9';c++) // to teat all values '1-9' in respective position
                    {
                        if(isValid(row,col,board,c))
                        {
                            board[row][col]=c; // to put '1-9' and check if valid
                            
                            if(solve(board)==true)
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    return false; // if the char already exist in row/col/3x3matrix return false which break recursion and puts '.'  in current position as it is popped (we have to backtrack) else of see 2 lines above
                }
            }
        }
        return true; // if the puzzle is already filled
    }
    
    bool isValid(int row,int col,vector<vector<char>>&board,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                return false;
            
            if(board[i][col]==c)
                return false;
            
            if(board[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == c)// '/' for row as we move to next row after 3 iteration ; '%' for col as for each iteration we have to move right.
                
                return false;
        }
        return true;
    }
    
}; 
