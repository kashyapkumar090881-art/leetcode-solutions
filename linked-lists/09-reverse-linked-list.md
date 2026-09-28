# Problem: Reverse Linked List (Easy, BONUS)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/reverse-linked-list/)

## Approach
Walk the list once while keeping pointers to the current node, its original next node, and the already-reversed prefix. Redirect each next pointer toward the prefix, then return the former tail as the new head.

## Complexity

- Time: O(n)
- Space: O(1)

## Notes
The tests cover a three-node list and an empty list. Saving the next pointer before changing a link prevents losing the rest of the original list. This is a bonus and is not included in the required eight-problem progress counts. Accepted screenshot will be added manually after LeetCode submission.