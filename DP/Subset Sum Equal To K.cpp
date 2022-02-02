/*
Problem Statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’
. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to 
‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. 
Otherwise, return false.

Sample Input 1:
2
4 5
4 3 2 1
5 4
2 5 1 6 7
Sample Output 1:
true
false
Explanation For Sample Input 1:
In example 1, ‘ARR’ is {4,3,2,1} and ‘K’ = 5. There exist 2 subsets with sum = 5. These are {4,1} and {3,2}. Hence, return true.
In example 2, ‘ARR’ is {2,5,1,6,7} and ‘K’ = 4. There are no subsets with sum = 4. Hence, return false.
Sample Input 2:
2
4 4
6 1 2 1
5 6
1 7 2 9 10
Sample Output 2:
true
false
Explanation For Sample Input 2:
In example 1, ‘ARR’ is {6,1,2,1} and ‘K’ = 4. There exist 1 subset with sum = 4. That is {1,2,1}. Hence, return true.
In example 2, ‘ARR’ is {1,7,2,9,10} and ‘K’ = 6. There are no subsets with sum = 6. Hence, return false.

*/

// Recursive:-

// TC - O(2^n) SC - O(n)

bool solve(int idx, int k, vector<int> &arr,){
    if(k == 0) return true;
    if(idx == 0) return (arr[0] == k);
    bool notTake = solve(idx-1, k, arr);
    bool take = false;
    if(k >= arr[idx])
        take = solve(idx-1, k-arr[idx], arr);
    return (notTake || take);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return solve(n-1, k, arr);
}

// Memoized

// TC - O(n*k) SC - O(n*k) + O(n)

bool solve(int idx, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0) return true;
    if(idx == 0) return (arr[0] == k);
    if(dp[idx][k] != -1) return dp[idx][k];
    bool notTake = solve(idx-1, k, arr, dp);
    bool take = false;
    if(k >= arr[idx])
        take = solve(idx-1, k-arr[idx], arr, dp);
    return dp[idx][k] = (notTake || take);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}

// TC - O(n*k) SC - O(n*k)

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    //return solve(n-1, k, arr, dp);
    for(int idx=0; idx<n; idx++) dp[idx][0] = true;
    dp[0][arr[0]] = true;
    for(int idx=1; idx<n; idx++){
        for(int target = 1; target<=k; target++){
            bool notTake = dp[idx-1][target];
            bool take = false;
            if(target >= arr[idx])
                take = dp[idx-1][target-arr[idx]];
            dp[idx][target] = notTake || take;
        }
    }
    return dp[n-1][k];
}
