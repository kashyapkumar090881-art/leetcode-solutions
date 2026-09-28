#include <stdio.h>
#include <string.h>

// LeetCode solution function
void reverseString(char *s, int sSize)
{
    // Swap inward from both ends so the array is reversed in place.
    for (int left = 0, right = sSize - 1; left < right; left++, right--)
    {
        char temporary = s[left];
        s[left] = s[right];
        s[right] = temporary;
    }
}

// Local testing
static void runTest(const char *label, const char *input, const char *expected)
{
    char actual[32];
    strcpy(actual, input);
    reverseString(actual, (int)strlen(actual));
    int passed = strcmp(actual, expected) == 0;
    printf("%s\nInput: \"%s\"\nExpected Output: \"%s\"\nActual Output: \"%s\"\nResult: %s\n\n",
           label, input, expected, actual, passed ? "PASS" : "FAIL");
}

int main(void)
{
    runTest("Test Case 1", "hello", "olleh");
    runTest("Test Case 2", "a", "a");
    return 0;
}