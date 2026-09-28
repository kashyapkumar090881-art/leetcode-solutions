#include <stdio.h>
#include <string.h>

// LeetCode solution function
int isValid(char *s)
{
    size_t length = strlen(s);
    char stack[length == 0 ? 1 : length];
    size_t stackSize = 0;

    // Openers wait on the stack until their matching closer is seen.
    for (size_t index = 0; index < length; index++)
    {
        char character = s[index];
        if (character == '(' || character == '[' || character == '{')
        {
            stack[stackSize++] = character;
        }
        else
        {
            if (stackSize == 0)
            {
                return 0;
            }
            char opening = stack[--stackSize];
            if ((character == ')' && opening != '(') ||
                (character == ']' && opening != '[') ||
                (character == '}' && opening != '{'))
            {
                return 0;
            }
        }
    }
    return stackSize == 0;
}

// Local testing
static void runTest(const char *label, char *input, int expected)
{
    int actual = isValid(input);
    printf("%s\nInput: \"%s\"\nExpected Output: %s\nActual Output: %s\nResult: %s\n\n",
           label, input, expected ? "true" : "false", actual ? "true" : "false",
           actual == expected ? "PASS" : "FAIL");
}

int main(void)
{
    char typical[] = "{[]}";
    char mismatched[] = "([)]";
    runTest("Test Case 1", typical, 1);
    runTest("Test Case 2", mismatched, 0);
    return 0;
}