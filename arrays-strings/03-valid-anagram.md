# Problem: Valid Anagram (Easy)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/valid-anagram/)

## Approach
Reject strings of different lengths, then count each byte from the first string and subtract the corresponding byte from the second. The strings are anagrams exactly when every frequency returns to zero, avoiding a sort while handling arbitrary byte values.

## Complexity

- Time: O(n + 256), which is O(n) for the fixed byte alphabet
- Space: O(1), using a fixed-size frequency table

## Notes
Two empty strings are anagrams, and that case is tested. The table uses unsigned-byte indexing so signed `char` values cannot produce a negative index. Accepted screenshot will be added manually after LeetCode submission.