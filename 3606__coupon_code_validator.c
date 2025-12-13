/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
bool check_code(char* code){

} 

bool check_bs(char* businessLine){

}

bool check_act(bool isActive){

}

char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
    char** ans=malloc(sizeof(char*)*codeSize);
    
    for(int i=0;i<codeSize;i++){//use codeSize as n
        if(!check_code(code[i])){
            continue;
        }
        if(!check_bs(businessLine[i])){
            continue;
        }
        if(!check_act(isActive[i])){
            continue;
        }
        ans[i]=malloc(sizeof(char)*strlen(code[i]));
        strcpy(str[i],code[i]);
    }
}
*/

#include <stdlib.h> // for malloc, free, qsort
#include <string.h> // for strcmp, strdup
#include <stdbool.h> // for bool type
#include <ctype.h>  // for isalnum

// --- 輔助結構體：用於儲存通過驗證的優惠券資訊，方便排序 ---
typedef struct {
    char* code;
    char* businessLine;
} CouponInfo;

// --- 1. 驗證函數：檢查 Code ---
// 條件：非空，且僅包含字母數字 (a-z, A-Z, 0-9) 和下劃線 (_)
bool check_code(char* code) {
    if (code == NULL || code[0] == '\0') {
        return false;
    }
    for (int i = 0; code[i] != '\0'; i++) {
        char c = code[i];
        // 必須是字母數字或下劃線
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
} 

// --- 2. 驗證函數：檢查 Business Line ---
// 條件：必須是 "electronics", "grocery", "pharmacy", "restaurant" 之一
bool check_bs(char* businessLine) {
    if (strcmp(businessLine, "electronics") == 0 ||
        strcmp(businessLine, "grocery") == 0 ||
        strcmp(businessLine, "pharmacy") == 0 ||
        strcmp(businessLine, "restaurant") == 0) {
        return true;
    }
    return false;
}

// --- 3. 驗證函數：檢查 Active 狀態 ---
// 條件：必須是 true
bool check_act(bool isActive) {
    return isActive;
}

// --- 4. 排序輔助函數：獲取業務線的固定順序 ---
// 這是實現主要排序依據 (固定順序) 的關鍵
int getBusinessOrder(const char* bs) {
    if (strcmp(bs, "electronics") == 0) return 0;
    if (strcmp(bs, "grocery") == 0) return 1;
    if (strcmp(bs, "pharmacy") == 0) return 2;
    if (strcmp(bs, "restaurant") == 0) return 3;
    return 4; // 理論上不應該到達，因為 check_bs 已過濾
}

// --- 5. 比較函數：用於 qsort 的排序邏輯 ---
// 優先按 getBusinessOrder 排序，其次按 code 的字典順序排序
int compareCoupons(const void* a, const void* b) {
    const CouponInfo* couponA = (const CouponInfo*)a;
    const CouponInfo* couponB = (const CouponInfo*)b;

    // A. 主要排序依據：Business Line 的固定順序
    int orderA = getBusinessOrder(couponA->businessLine);
    int orderB = getBusinessOrder(couponB->businessLine);

    if (orderA != orderB) {
        // 如果順序值不同，直接返回差值 (升序)
        return orderA - orderB;
    }

    // B. 次要排序依據：Code 的字典升序
    return strcmp(couponA->code, couponB->code);
}

// --- 6. 主函數：驗證、篩選、排序和返回結果 ---
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
    // 雖然題目提供了三個 size 參數，但它們應該都等於 n (codeSize)
    // 假設 codeSize 就是 n
    
    // Step 1: 篩選和收集通過驗證的優惠券
    // 使用一個動態數組 (或預先分配最大空間) 來儲存結果
    CouponInfo* valid_coupons = (CouponInfo*)malloc(sizeof(CouponInfo) * codeSize);
    int valid_count = 0; // 記錄合法優惠券的數量

    for (int i = 0; i < codeSize; i++) {
        if (check_code(code[i]) && 
            check_bs(businessLine[i]) && 
            check_act(isActive[i])) 
        {
            // 如果驗證通過，記錄 code 和 businessLine
            valid_coupons[valid_count].code = code[i];
            valid_coupons[valid_count].businessLine = businessLine[i];
            valid_count++;
        }
    }

    // Step 2: 排序
    // 使用 qsort 函式和我們定義的比較器進行排序
    qsort(valid_coupons, valid_count, sizeof(CouponInfo), compareCoupons);

    // Step 3: 準備最終的結果陣列
    // LeetCode 要求返回一個包含 codes 的 char**，並且是新 malloc 的
    char** ans = (char**)malloc(sizeof(char*) * valid_count);
    for (int i = 0; i < valid_count; i++) {
        // 使用 strdup (或 malloc + strcpy) 複製字串
        ans[i] = strdup(valid_coupons[i].code); 
    }

    // Step 4: 清理和返回
    *returnSize = valid_count;
    free(valid_coupons); // 釋放中間結構的記憶體
    
    return ans;
}

// 注意：在 LeetCode 環境中，您需要將上述代碼塊（除了 include 和 main 函式）
// 放在 Solution 結構體或頂層，並確保所有使用的函式 (如 strdup, malloc, free) 
// 都是可用的。
