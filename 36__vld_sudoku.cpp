class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    continue;
                }

                char v=board[r][c];
                int boxidx=(r/3)*3+(c/3);

                if(rows[r].count(v)||cols[c].count(v)||boxes[boxidx].count(v)){
                    return false;
                }

                rows[r].insert(v);
                cols[c].insert(v);
                boxes[boxidx].insert(v);
            }
        }

        return true;
    }
};
