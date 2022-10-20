class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row checking
        for(int i=0; i<board.size(); i++){
            unordered_map<char, int> m;
            for(int j=0; j<board[i].size(); j++){
                m[board[i][j]]++;
                if(m[board[i][j]]>1 && board[i][j]!= '.') return 0;
            }
        }
        //column checking
        for(int i=0; i<board.size(); i++){
            unordered_map<char, int> m;
            for(int j=0; j<board[i].size(); j++){
                m[board[j][i]]++;
                if(m[board[j][i]]>1 && board[j][i]!= '.') return 0;
            }
        }
        
        //3x3 checking
        for(int i=0; i<board.size(); i+= 3){
            for(int j=0; j<board[i].size(); j+=3){
                unordered_map<char, int> m;
                for(int k=i; k<i+3; k++){
                    for(int f= j; f<j+3; f++){
                        m[board[k][f]]++;
                        if(m[board[k][f]]>1 && board[k][f]!= '.') return 0;
                    }
                }
                for(auto it: m) cout<<it.first<<" "<<it.second<<endl;
                
            }
        }
        return 1;
    }
};
