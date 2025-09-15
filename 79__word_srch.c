#if(0)
bool dfs(char** board, int boardSize, int* boardColSize, char* word,
 int cur_i, int cur_j, char cur_word, int target){
    if(cur_word==target){
        return true;
    }

    if(cur_i<0 || cur_i>(boardSize-1) || cur_j<0 || cur_j> boardColSize[cur_j]){return ;}
    if(word[cur_word]!=board[cur_i][cur_j]){
        return false;
    }else{
        return (dfs(board,boardSize,boardColSize,word,cur_i-1,cur_j,cur_word,target)||
                dfs(board,boardSize,boardColSize,word,cur_i,cur_j+1,cur_word,target)||
                dfs(board,boardSize,boardColSize,word,cur_i+1,cur_j,cur_word,target)||
                dfs(board,boardSize,boardColSize,word,cur_i,cur_j-1,cur_word,target)
        );
    }
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int len=strlen(word);
    return dfs(board,boardSize,boardColSize,word, 0,0,len);
}
#endif
#include <string.h>
#include <stdbool.h>

// 這是我們用來進行深度優先搜尋的輔助函數
// k 代表目前在 word 中匹配到的字元索引
// word_len 代表單字的長度
bool dfs(char** board, int boardSize, int* boardColSize, char* word, int word_len, int cur_i, int cur_j, int k) {
    int rows = boardSize;
    int cols = boardColSize[0];

    // 第一個遞迴終止條件：如果 k 等於單字長度，表示已找到所有字元
    if (k == word_len) {
        return true;
    }

    // 第二個遞迴終止條件：
    // 1. 超出邊界
    // 2. 當前單元格的字元與 word[k] 不匹配
    if (cur_i < 0 || cur_i >= rows || cur_j < 0 || cur_j >= cols || board[cur_i][cur_j] != word[k]) {
        return false;
    }

    // 關鍵的回溯步驟：
    // 1. 為了避免走回頭路，暫時將當前單元格的字元替換掉
    char temp = board[cur_i][cur_j];
    board[cur_i][cur_j] = '\0'; // 用一個不會出現在字母表裡的字元來標記

    // 2. 嘗試往四個方向（上、下、左、右）進行遞迴搜尋
    bool found = dfs(board, rows, boardColSize, word, word_len, cur_i + 1, cur_j, k + 1) || // 下
                 dfs(board, rows, boardColSize, word, word_len, cur_i - 1, cur_j, k + 1) || // 上
                 dfs(board, rows, boardColSize, word, word_len, cur_i, cur_j + 1, k + 1) || // 右
                 dfs(board, rows, boardColSize, word, word_len, cur_i, cur_j - 1, k + 1);  // 左

    // 3. 回溯：將單元格的字元恢復原狀
    board[cur_i][cur_j] = temp;

    return found;
}

// 主函數：遍歷所有可能的起點
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    if (rows == 0) return false;
    int cols = boardColSize[0];
    
    // 在這裡只呼叫一次 strlen，並將長度存起來
    int word_len = strlen(word);

    // 遍歷網格中的每一個單元格
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 如果當前單元格的字元與 word 的第一個字元相同，就開始 DFS 搜尋
            if (board[i][j] == word[0]) {
                if (dfs(board, rows, boardColSize, word, word_len, i, j, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}
