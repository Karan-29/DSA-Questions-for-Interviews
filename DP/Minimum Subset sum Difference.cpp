/*
Problem Statement
You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.
Note:
1. Each element of the array should belong to exactly one of the subset.

2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset.

Sample Input 1:
1
4
1 2 3 4
Sample Output 1:
0
Explanation For Sample Input 1:
We can partition the given array into {2,3} and {1,4}, as this will give us the minimum possible absolute difference i.e (5-5=0) in this case.
Sample Input 2:
1
3
8 6 5
Sample Output 2:
3
Explanation For Sample Input 2:
We can partition the given array into {8} and {6,5}, as this will give us the minimum possible absolute difference i.e (11-8=3) in this case
*/

// TC - O(n*target) + O(n) SC - O(n*target)

int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Write your code here.
    int totSum = 0;
    for(int i=0; i<n; i++) totSum+=arr[i];
    int k = totSum;
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int idx=0; idx<n; idx++) dp[idx][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int idx=1; idx<n; idx++){
        for(int target = 1; target<=k; target++){
            bool notTake = dp[idx-1][target];
            bool take = false;
            if(target >= arr[idx])
                take = dp[idx-1][target-arr[idx]];
            dp[idx][target] = notTake || take;
        }
    }
    int mini = 1e8;
    for(int i=0; i<=totSum/2; i++){
        if(dp[n-1][i] == true){
            mini = min(mini, abs((totSum - i) - i));
        }
    }
    return mini;
}


