#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LeetCode solution function
char *longestCommonPrefix(char **strs, int strsSize)
{
    size_t prefixLength = strsSize == 0 ? 0 : strlen(strs[0]);
    // Shrink the candidate prefix wherever another string differs.
    for (int word = 1; word < strsSize && prefixLength > 0; word++)
    {
        size_t index = 0;
        while (index < prefixLength && strs[word][index] != '\0' &&
               strs[0][index] == strs[word][index])
        {
            index++;
        }
        prefixLength = index;
    }

    char *prefix = malloc(prefixLength + 1);
    if (prefix == NULL)
    {
        return NULL;
    }
    if (strsSize > 0)
    {
        memcpy(prefix, strs[0], prefixLength);
    }
    prefix[prefixLength] = '\0';
    return prefix;
}

// Local testing
static void runTest(const char *label, char **words, int size, const char *expected,
                    const char *input)
{
    char *actual = longestCommonPrefix(words, size);
    if (actual == NULL)
    {
        printf("%s\nAllocation failed\nResult: FAIL\n\n", label);
        return;
    }
    int passed = strcmp(actual, expected) == 0;
    printf("%s\nInput: %s\nExpected Output: \"%s\"\nActual Output: \"%s\"\nResult: %s\n\n",
           label, input, expected, actual, passed ? "PASS" : "FAIL");
    free(actual);
}

int main(void)
{
    char *typical[] = {"flower", "flow", "flight"};
    char first[] = "dog";
    char second[] = "racecar";
    char third[] = "car";
    char *noPrefix[] = {first, second, third};
    runTest("Test Case 1", typical, 3, "fl", "strs=[flower,flow,flight]");
    runTest("Test Case 2", noPrefix, 3, "", "strs=[dog,racecar,car] (no common prefix)");
    return 0;
}