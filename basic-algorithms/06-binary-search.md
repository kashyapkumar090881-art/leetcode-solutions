# Problem: Binary Search (Easy–Medium)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/binary-search/)

## Approach
Maintain an inclusive search interval in the sorted array and inspect its midpoint. Each comparison discards half of the remaining interval, so the target is found efficiently or the interval becomes empty.

## Complexity

- Time: O(log n)
- Space: O(1)

## Notes
The function returns -1 when the target is absent and also handles an empty array. The input must be sorted in ascending order for binary search to be valid. Accepted screenshot will be added manually after LeetCode submission.