# Problem: Longest Common Prefix (Easy–Medium)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/longest-common-prefix/)

## Approach
Use the first string as the candidate prefix and compare its characters against each remaining string, shortening the candidate at the first mismatch. This vertical scan stops as soon as no prefix remains and avoids sorting the input.

## Complexity

- Time: O(S), where S is the total number of characters inspected
- Space: O(m) for the returned prefix of length m; O(1) auxiliary space

## Notes
An empty string list returns an empty prefix, and strings with no shared first character also return empty; the latter is tested. The function returns a separately allocated prefix and leaves the input strings unchanged. Accepted screenshot will be added manually after LeetCode submission.