/*
Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, return the area of the largest rectangle 
in the histogram.

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

// TC - O(n) SC -  O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n  = heights.size();
    stack<int> index;
    int largestArea = 0;
    for (int i = 0; i < n; i++) {
        while (!index.empty() && heights[index.top()] > heights[i]) {
            int prevIndx = index.top();
            index.pop();
            if (index.empty()) {
                int currentArea = i * heights[prevIndx];
                largestArea = max(largestArea, currentArea);
            } else {
                int currentArea = (i - 1 - index.top()) * heights[prevIndx];
                largestArea = max(largestArea, currentArea);
            }
        }
        index.push(i);
    }
    while(!index.empty()) {
        int prevIndx = index.top();
        index.pop();
        if (index.empty()) {
            int currentArea = n * heights[prevIndx];
            largestArea = max(largestArea, currentArea);
        } else {
            int currentArea = (n - 1 - index.top()) * heights[prevIndx];
            largestArea = max(largestArea, currentArea);
        }
    }
    return largestArea;
    }
};

// Different Solution

stack<int> st1, st2;
    int n = heights.size(), ans = 0;
    int leftMin[n], rightMin[n];
    for(int i=n-1; i>=0; i--){
        while(!st1.empty() && heights[st1.top()] >= heights[i])
            st1.pop();
        rightMin[i] = st1.empty() ? n : st1.top();
        st1.push(i);
    }
    for(int i=0; i<n; i++){
        while(!st2.empty() && heights[st2.top()] >= heights[i])
            st2.pop();
        leftMin[i] = st2.empty() ? -1 : st2.top();
        st2.push(i);
    }
    for(int i=0; i<n; i++){
        int width = ((rightMin[i]-1) - (leftMin[i]+1) + 1);
        int height = width * heights[i];
        ans = max(ans, height);
    }
    return ans;