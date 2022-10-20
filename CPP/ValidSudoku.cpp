class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.') // if blank put character ad validate in nex instruction
                {
                    for(int k=0;k<9;k++)
                        if( (i!=k && board[k][j]==board[i][j]) || (j!=k && board[i][k]==board[i][j]) )
                            return 0;
                    for(int row=3*(i/3); row<3*(i/3)+3; row++)
                        for(int col=3*(j/3); col<3*(j/3)+3; col++)
                            if( (row!=i || col!=j) && board[row][col]==board[i][j])
                                return 0;
                }
            }
        }
        return 1; // if the puzzle is already filled
    }
    
    
}; 
