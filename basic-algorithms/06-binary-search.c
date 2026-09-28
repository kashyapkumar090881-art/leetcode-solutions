#include <stdio.h>

// LeetCode solution function
int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    // Each comparison removes the half that cannot contain the target.
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}

// Local testing
static void runTest(const char *label, const int *nums, int size, int target,
                    int expected, const char *input)
{
    int actual = search((int *)nums, size, target);
    printf("%s\nInput: %s\nExpected Output: %d\nActual Output: %d\nResult: %s\n\n",
           label, input, expected, actual, actual == expected ? "PASS" : "FAIL");
}

int main(void)
{
    int sorted[] = {-1, 0, 3, 5, 9, 12};
    int single[] = {5};
    runTest("Test Case 1", sorted, 6, 9, 4, "nums=[-1,0,3,5,9,12], target=9");
    runTest("Test Case 2", single, 1, 2, -1, "nums=[5], target=2 (not found)");
    return 0;
}