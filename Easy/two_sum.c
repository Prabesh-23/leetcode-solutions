#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for result array (will contain 2 indices)
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // Brute force: check all pairs
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    // Should not reach here if valid solution exists
    *returnSize = 0;
    free(result);
    return NULL;
}

// Test function
int main() {
    // Test case 1: [2,7,11,15], target = 9
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    
    int* result1 = twoSum(nums1, 4, target1, &returnSize1);
    if (result1) {
        printf("Test 1 - Indices: [%d, %d]\n", result1[0], result1[1]);
        free(result1);
    }
    
    // Test case 2: [3,2,4], target = 6  
    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    
    int* result2 = twoSum(nums2, 3, target2, &returnSize2);
    if (result2) {
        printf("Test 2 - Indices: [%d, %d]\n", result2[0], result2[1]);
        free(result2);
    }
    
    // Test case 3: [3,3], target = 6
    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    
    int* result3 = twoSum(nums3, 2, target3, &returnSize3);
    if (result3) {
        printf("Test 3 - Indices: [%d, %d]\n", result3[0], result3[1]);
        free(result3);
    }
    
    return 0;
}