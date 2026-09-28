# Problem: Reverse a String (Easy)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/reverse-string/)

## Approach
Swap the characters at the two ends of the array, then move both indices inward until they meet. Each pair is exchanged once, so the string is reversed in place without an additional character array.

## Complexity

- Time: O(n)
- Space: O(1)

## Notes
A one-character string needs no swaps, and the same loop also handles an empty array. The in-place approach meets the constant-extra-space goal. Accepted screenshot will be added manually after LeetCode submission.