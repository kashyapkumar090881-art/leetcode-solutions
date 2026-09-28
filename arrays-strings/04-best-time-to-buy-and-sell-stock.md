# Problem: Best Time to Buy and Sell Stock (Easy–Medium)
**Link:** [Official LeetCode Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Approach
Scan prices once while tracking the lowest price seen so far and the best profit from selling on the current day. This preserves the required buy-before-sell order and needs only constant extra storage.

## Complexity

- Time: O(n)
- Space: O(1)

## Notes
If prices only decrease, no profitable transaction exists and the result is zero; this is covered by the edge test. Arrays with fewer than two prices also return zero. Accepted screenshot will be added manually after LeetCode submission.