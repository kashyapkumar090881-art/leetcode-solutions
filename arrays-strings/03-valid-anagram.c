#include <stdio.h>
#include <string.h>

// LeetCode solution function
int isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
    {
        return 0;
    }

    // Matching byte counts cancel to zero when both strings are anagrams.
    int counts[256] = {0};
    for (size_t index = 0; s[index] != '\0'; index++)
    {
        counts[(unsigned char)s[index]]++;
        counts[(unsigned char)t[index]]--;
    }
    for (int character = 0; character < 256; character++)
    {
        if (counts[character] != 0)
        {
            return 0;
        }
    }
    return 1;
}

// Local testing
static void runTest(const char *label, char *first, char *second, int expected,
                    const char *input)
{
    int actual = isAnagram(first, second);
    printf("%s\nInput: %s\nExpected Output: %s\nActual Output: %s\nResult: %s\n\n",
           label, input, expected ? "true" : "false", actual ? "true" : "false",
           actual == expected ? "PASS" : "FAIL");
}

int main(void)
{
    char first[] = "anagram";
    char second[] = "nagaram";
    char emptyFirst[] = "";
    char emptySecond[] = "";
    runTest("Test Case 1", first, second, 1, "s=\"anagram\", t=\"nagaram\"");
    runTest("Test Case 2", emptyFirst, emptySecond, 1, "s=\"\", t=\"\"");
    return 0;
}