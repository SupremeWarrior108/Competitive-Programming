/*
Assume there is some hypothetical state definition

Transition:
    dp[i] = arr[i] + min(dp[i - 1], dp[i - 2] , .... , dp[i - k])

Base Case:
    dp[0] = some hypothetical value
Final Subproblem:
    Find all dp[0]... dp[n]

Solution:->
1.  using segment tree

2.  using sliding window

dp[i] = arr[i] + min(dp[i-1] , dp[i-2] , .... , dp[i-k])

idea
use multiset, find min for first three elements 
and then slide window to next. Time Complexity for this is O(n.logk)
*/