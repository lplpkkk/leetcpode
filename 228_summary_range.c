/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory for the result
    char **result = (char **)malloc(numsSize * sizeof(char *));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int count = 0; // Count of ranges
    for (int i = 0; i < numsSize; i++) {
        int start = nums[i];
        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1) {
            i++;
        }
        int end = nums[i];
        if (start == end) {
            result[count] = (char *)malloc(12 * sizeof(char)); // Maximum length of "x" is 11
            snprintf(result[count], 12,"%d", start);
        } else {
            result[count] = (char *)malloc(25 * sizeof(char)); // Maximum length of "x->y" is 23
            snprintf(result[count], 25,"%d->%d", start, end);
        }
        count++;
    }

    *returnSize = count;
    return result;
}
