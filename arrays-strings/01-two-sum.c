#include <stdio.h>
#include <stdlib.h>

// LeetCode solution function
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 0;
    // Try each distinct pair; return the first pair that reaches the target.
    for (int first = 0; first < numsSize; first++)
    {
        for (int second = first + 1; second < numsSize; second++)
        {
            if (nums[first] + nums[second] == target)
            {
                int *answer = malloc(2 * sizeof(*answer));
                if (answer == NULL)
                {
                    return NULL;
                }
                answer[0] = first;
                answer[1] = second;
                *returnSize = 2;
                return answer;
            }
        }
    }
    return NULL;
}

// Local testing
static void runTest(const char *label, const int *nums, int size, int target,
                    const int *expected, int expectedSize, const char *input)
{
    int returnSize = 0;
    int *actual = twoSum((int *)nums, size, target, &returnSize);
    int passed = returnSize == expectedSize;
    for (int index = 0; passed && index < expectedSize; index++)
    {
        passed = actual[index] == expected[index];
    }

    printf("%s\nInput: %s\nExpected Output: [", label, input);
    for (int index = 0; index < expectedSize; index++)
    {
        printf("%s%d", index == 0 ? "" : ", ", expected[index]);
    }
    printf("]\nActual Output: [");
    for (int index = 0; index < returnSize; index++)
    {
        printf("%s%d", index == 0 ? "" : ", ", actual[index]);
    }
    printf("]\nResult: %s\n\n", passed ? "PASS" : "FAIL");
    free(actual);
}

int main(void)
{
    int typical[] = {2, 7, 11, 15};
    const int typicalAnswer[] = {0, 1};
    int noAnswer[] = {1, 2, 3};
    runTest("Test Case 1", typical, 4, 9, typicalAnswer, 2, "nums=[2,7,11,15], target=9");
    runTest("Test Case 2", noAnswer, 3, 7, NULL, 0, "nums=[1,2,3], target=7 (no pair)");
    return 0;
}