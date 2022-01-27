/* Problem Statement
You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.
Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)


Input 1 :
2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
3 3
10 2 3
3 7 2
8 1 5

Output 1 :
105
25

*/

// Recursive Solution:-

// TC - O(3^n) SC - O(n)

int findMaxPathSum(vector<vector<int>> &matrix, int i, int j, int n, int m){
    if(j<0 || j>=m) return -1e9;
    if(i==0) return matrix[0][j];
    int down = matrix[i][j] + findMaxPathSum(matrix, i-1, j, n, m);
    int leftDiag = matrix[i][j] + findMaxPathSum(matrix, i-1, j-1, n, m);
    int rightDiag = matrix[i][j] + findMaxPathSum(matrix, i-1, j+1, n, m);
    return max(down, max(leftDiag, rightDiag));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    int maxi = -1e9;
    for(int i=0; i<m; i++){
        maxi = max(maxi, findMaxPathSum(matrix, n-1, i, n, m));
    }
    return maxi;
}

// Memoized Solution

// TC - O(n*m) SC - O(n*m) + O(n)

int findMaxPathSum(vector<vector<int>> &matrix, int i, int j, int n, int m, vector<vector<int>> dp){
    if(j<0 || j>=m) return -1e8;
    if(i==0) return matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = matrix[i][j] + findMaxPathSum(matrix, i-1, j, n, m, dp);
    int leftDiag = matrix[i][j] + findMaxPathSum(matrix, i-1, j-1, n, m, dp);
    int rightDiag = matrix[i][j] + findMaxPathSum(matrix, i-1, j+1, n, m, dp);
    return dp[i][j] = max(down, max(leftDiag, rightDiag));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e8;
    for(int i=0; i<m; i++){
        maxi = max(maxi, findMaxPathSum(matrix, n-1, i, n, m, dp));
    }
    return maxi;
}

// Tabulation 

// TC - O(n*m) SC - O(n*m)

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<m; i++){
        dp[0][i] = matrix[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int up = matrix[i][j] + dp[i-1][j];
            int leftDiag = matrix[i][j];
            if(j-1 >= 0) leftDiag += dp[i-1][j-1];
            else leftDiag += -1e8;
            int rightDiag = matrix[i][j];
            if(j+1 < m) rightDiag += dp[i-1][j+1];
            else rightDiag += -1e8;
            dp[i][j] = max(up, max(leftDiag, rightDiag));
        }
    }
    int maxi = -1e8;
    for(int i=0; i<m; i++){
        maxi = max(maxi, dp[n-1][i]);
    }
    return maxi;
}