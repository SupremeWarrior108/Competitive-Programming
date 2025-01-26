/*
    Assume that there is an hypothetical DP state

    Transition:
        dp[i] = dp[i-k] + dp[i-2k] + dp[i-3k] + .... 

    Base Case:
        dp[0 .... k-1]  = some hypothetical values

    Final Subproblem:
        find all dp[0] .... dp[n]
    
    assume 0<n<1e9


    solution-->
    dp[i] = dp[i-k] + dp[i-2k] + ....
    dp[i-1] = dp[i-2k] + dp[i-3k] + ....
    
    so, 
    dp[i] = 2 * dp[i-k]

*/