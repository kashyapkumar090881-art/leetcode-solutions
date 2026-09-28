# Problem: Valid Parentheses (Easy–Medium)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/valid-parentheses/)

## Approach
Push each opening bracket onto a stack. For every closing bracket, require the stack's top to be its matching opener, then finally require the stack to be empty; this enforces both correct nesting and matching pairs.

## Complexity

- Time: O(n)
- Space: O(n)

## Notes
The edge test uses mismatched nesting, which must fail even though the same bracket types appear. An empty string is valid because it contains no unmatched brackets. Accepted screenshot will be added manually after LeetCode submission.