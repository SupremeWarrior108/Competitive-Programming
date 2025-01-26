/*
Assume there is some hypothetical state definition

Transition
    dp[i] = arr[i] + min(dp[i - 1], dp[i - 2].... dp[i - arr[i]])

Base Case
    dp[0] = some hypothetical value

Final Subproblem
    Find all dp[0]... dp[n]

Solution:
Use segment tree
*/