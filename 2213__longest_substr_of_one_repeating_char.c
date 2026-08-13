/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;
    int prefix;
    int suffix;
    int best;
    char left_char;
    char right_char;
} Node;

static Node *tree;
static char *str;

static int max_int(int a, int b) {
    return a > b ? a : b;
}

static Node merge(Node a, Node b)
{
    Node res;

    res.len = a.len + b.len;

    res.left_char = a.left_char;
    res.right_char = b.right_char;

    res.prefix = a.prefix;
    res.suffix = b.suffix;

    res.best = max_int(a.best, b.best);

    if (a.right_char == b.left_char) {

        int cross = a.suffix + b.prefix;

        res.best = max_int(res.best, cross);

        /*
         * a 整段都是同一個 char，
         * prefix 才能延伸進 b
         */
        if (a.prefix == a.len) {
            res.prefix = a.len + b.prefix;
        }

        /*
         * b 整段都是同一個 char，
         * suffix 才能延伸進 a
         */
        if (b.suffix == b.len) {
            res.suffix = b.len + a.suffix;
        }
    }

    return res;
}

static void build(int node_idx, int left, int right)
{
    if (left == right) {
        tree[node_idx].len = 1;
        tree[node_idx].prefix = 1;
        tree[node_idx].suffix = 1;
        tree[node_idx].best = 1;
        tree[node_idx].left_char = str[left];
        tree[node_idx].right_char = str[left];
        return;
    }

    int mid = left + (right - left) / 2;

    build(node_idx * 2, left, mid);
    build(node_idx * 2 + 1, mid + 1, right);

    tree[node_idx] =
        merge(tree[node_idx * 2],
              tree[node_idx * 2 + 1]);
}

static void update(
    int node_idx,
    int left,
    int right,
    int idx,
    char new_char)
{
    if (left == right) {
        /*
         * leaf 永遠代表長度 1
         */
        tree[node_idx].left_char = new_char;
        tree[node_idx].right_char = new_char;
        tree[node_idx].prefix = 1;
        tree[node_idx].suffix = 1;
        tree[node_idx].best = 1;

        return;
    }

    int mid = left + (right - left) / 2;

    if (idx <= mid) {
        update(
            node_idx * 2,
            left,
            mid,
            idx,
            new_char
        );
    } else {
        update(
            node_idx * 2 + 1,
            mid + 1,
            right,
            idx,
            new_char
        );
    }

    /*
     * child 更新後，重新算 parent
     */
    tree[node_idx] =
        merge(tree[node_idx * 2],
              tree[node_idx * 2 + 1]);
}

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* longestRepeating(
    char* s,
    char* queryCharacters,
    int* queryIndices,
    int queryIndicesSize,
    int* returnSize)
{
    int n = strlen(s);

    *returnSize = queryIndicesSize;

    int *ans =
        (int *)malloc(sizeof(int) * queryIndicesSize);

    tree =
        (Node *)malloc(sizeof(Node) * 4 * n);

    str = s;

    /*
     * tree[1] 當 root
     */
    build(1, 0, n - 1);

    for (int i = 0; i < queryIndicesSize; i++) {

        int idx = queryIndices[i];
        char c = queryCharacters[i];

        /*
         * 更新原始 string
         * 其實這版 update 不一定需要 str，
         * 但保持資料一致比較直覺
         */
        str[idx] = c;

        update(
            1,
            0,
            n - 1,
            idx,
            c
        );

        /*
         * root.best 永遠就是整條 string 的答案
         */
        ans[i] = tree[1].best;
    }

    free(tree);

    return ans;
}

/*
int* longestRepeating(char* s, char* queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize) {
    //dp[i][j]
    //   (start idx, from left to right) (char index)

    //dp2[i][j]
    //   (start idx, from right to left) (char index)

    //when update s at index i, also update dp2[i-1][char_before_change]
    //                                      dp2[i-1][queryChar[queryindices]]
    // just need to check +1 or -1;

    //when update s at index i, also update dp[i+1][char_before_change]
    //                                      dp[i+1][queryChar[queryindices]]

    //merge this two dp arrary 
    
    //for loop search dp[0][x]
}
*/
