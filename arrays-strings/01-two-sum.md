# Problem: Two Sum (Easy)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/two-sum/)

## Approach
Check each pair of distinct array elements and return their indices when their sum equals the target. This direct search is easy to follow and works for all input sizes, though a hash table can reduce the running time for larger arrays.

## Complexity

- Time: O(n^2)
- Space: O(1) auxiliary space, excluding the returned pair

## Notes
The implementation returns no indices when no pair exists, which the local edge test covers; LeetCode's stated constraints guarantee one answer. The pair search is beginner-friendly, while a hash table is a possible O(n)-time improvement. Accepted screenshot will be added manually after LeetCode submission.