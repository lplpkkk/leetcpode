/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // reserver memory for m*n
        vector<vector<int>> ans(m,n,-1);

        // design 4 directions --> 0: to right, 1: to bottom, 2: to  left, 3: to up
        // designt 4 limiit      -->  m-1, n-1, 0, 0

        int dir=0;
        int cnt=m*n;
        int lim[4]={m-1,n-1,0,0};
        int cur_col=0;
        int cur_row=m-1;

        enum { 
          right_lim=0,
          bottom_lim,
          left_lim,
          top_lim,  
        };

        while(cnt){
            switch(dir){
                case 0:
                    //fill matrix, use cur_col/cur_row to track
                    //if reach lim, change direction

                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3: 
                    break;
                defualt:
                    panic();
            }
            cnt--;
        }

        return ans;

    }
};
*/


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // 0:right, 1:down, 2:left, 3:up
        int dir = 0;

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        int row = 0;
        int col = 0;

        while (head) {
            ans[row][col] = head->val;
            head = head->next;

            switch (dir) {
            case 0: // right
                if (col == right) {
                    dir = 1;
                    top++;
                    row++;
                } else {
                    col++;
                }
                break;

            case 1: // down
                if (row == bottom) {
                    dir = 2;
                    right--;
                    col--;
                } else {
                    row++;
                }
                break;

            case 2: // left
                if (col == left) {
                    dir = 3;
                    bottom--;
                    row--;
                } else {
                    col--;
                }
                break;

            case 3: // up
                if (row == top) {
                    dir = 0;
                    left++;
                    col++;
                } else {
                    row--;
                }
                break;
            }
        }

        return ans;
    }
};
