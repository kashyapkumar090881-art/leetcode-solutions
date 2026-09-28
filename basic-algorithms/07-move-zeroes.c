#include <stdio.h>

// LeetCode solution function
void moveZeroes(int *nums, int numsSize)
{
    // Keep the next destination for a nonzero and preserve encounter order.
    int nextNonzero = 0;
    for (int index = 0; index < numsSize; index++)
    {
        if (nums[index] != 0)
        {
            int temporary = nums[nextNonzero];
            nums[nextNonzero] = nums[index];
            nums[index] = temporary;
            nextNonzero++;
        }
    }
}

// Local testing
static void printArray(const int *values, int size)
{
    printf("[");
    for (int index = 0; index < size; index++)
    {
        printf("%s%d", index == 0 ? "" : ", ", values[index]);
    }
    printf("]");
}

static void runTest(const char *label, const int *inputValues, int size,
                    const int *expected, const char *input)
{
    int actual[16];
    for (int index = 0; index < size; index++)
    {
        actual[index] = inputValues[index];
    }
    moveZeroes(actual, size);
    int passed = 1;
    for (int index = 0; index < size; index++)
    {
        passed = passed && actual[index] == expected[index];
    }
    printf("%s\nInput: %s\nExpected Output: ", label, input);
    printArray(expected, size);
    printf("\nActual Output: ");
    printArray(actual, size);
    printf("\nResult: %s\n\n", passed ? "PASS" : "FAIL");
}

int main(void)
{
    int typical[] = {0, 1, 0, 3, 12};
    int typicalExpected[] = {1, 3, 12, 0, 0};
    int zeroes[] = {0, 0, 0};
    int zeroesExpected[] = {0, 0, 0};
    runTest("Test Case 1", typical, 5, typicalExpected, "nums=[0,1,0,3,12]");
    runTest("Test Case 2", zeroes, 3, zeroesExpected, "nums=[0,0,0] (all zeroes)");
    return 0;
}