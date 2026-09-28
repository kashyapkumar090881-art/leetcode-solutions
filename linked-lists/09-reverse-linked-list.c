#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// LeetCode solution function
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *previous = NULL;
    struct ListNode *current = head;
    // Save the forward link before redirecting the current node backward.
    while (current != NULL)
    {
        struct ListNode *nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

// Local testing
static int matches(const struct ListNode *head, const int *expected, int size)
{
    for (int index = 0; index < size; index++)
    {
        if (head == NULL || head->val != expected[index])
        {
            return 0;
        }
        head = head->next;
    }
    return head == NULL;
}

static void printList(const struct ListNode *head)
{
    printf("[");
    while (head != NULL)
    {
        printf("%d", head->val);
        head = head->next;
        if (head != NULL)
        {
            printf(" -> ");
        }
    }
    printf("]");
}

int main(void)
{
    struct ListNode third = {3, NULL};
    struct ListNode second = {2, &third};
    struct ListNode first = {1, &second};
    const int expected[] = {3, 2, 1};
    struct ListNode *reversed = reverseList(&first);
    int passed = matches(reversed, expected, 3);
    printf("BONUS - Test Case 1\nInput: [1 -> 2 -> 3]\nExpected Output: [3 -> 2 -> 1]\nActual Output: ");
    printList(reversed);
    printf("\nResult: %s\n\n", passed ? "PASS" : "FAIL");

    struct ListNode *empty = reverseList(NULL);
    printf("BONUS - Test Case 2\nInput: [] (empty list)\nExpected Output: []\nActual Output: ");
    printList(empty);
    printf("\nResult: %s\n", empty == NULL ? "PASS" : "FAIL");
    return 0;
}