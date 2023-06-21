#include <bits/stdc++.h>
using namespace std;
/***************SET MATRIX ZERO**************************************************/
// BRUTE FORCE APPROACH: The Idea is basically to create a duplicate matrix based 
//on the given matrix and perform changes on the duplicate matrix. Whenever a zero 
//value is encountered in the duplicate matrix, the corresponding row and column in 
//the duplicate matrix are set to zero as well.
// Time Complexity:  O(n * m * (n + m)) 
// where n is the number of rows in the matrix and m is the number of columns.
// Space Complexity: O(n*n)
// for creating a duplicate matrix
void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
}
// BETTER APPROACH:The approach is to avoid creating a new matrix and instead use
//two arrays—one for rows and the other for columns. Then, traverses the original
// matrix and whenever it encounters a zero value, it marks the corresponding row element 
//as 1 in the row array and does the same for the column array. Then, it traverses the matrix again,
// and if any element in a row is marked as 1, it marks the complete column in the matrix as zero.
// The same process is applied for columns. 
// TC: O(2*(rows*cols))
// SC: O(rows+cols)
void zeroMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> rowcheck(rows, 0);
    vector<int> colcheck(cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rowcheck[i] = 1;
                colcheck[j] = 1;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowcheck[i] == 1 || colcheck[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
/**********************************************************************************/
/****************PASCAL TRIANGLE*******************************************************************/
//FIRST SOLUTION: The idea is to create a 2D matrix in a triangular shape. The process involves
// assigning values to the matrix by traversing each row. In the first row, there is only one element,
// which is assigned the value 1. For the second row and subsequent rows, the values are assigned 
//based on a specific pattern: the value at any position (excluding the first and last columns) 
//is the sum of the element directly above it and the element diagonally above it in left side.
// The first and last columns of each row are always assigned the value 1. 
// TC: O(n*n)
// SC: O(n*n)
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>>ans;
    for(int i=0;i<n;i++){
      vector<long long int>v;
      for(int j=0;j<=i;j++){
          v.push_back(j);
      }
      ans.push_back(v);
    }
    for(int i=0;i<n;i++){
         if(i==0){
           ans[i][0]=1;
         }
         else if(i==1){
           ans[i][0]=1;
           ans[i][1]=1;
         }
         else{
            ans[i][0]=1;
           for(int j=1;j<i;j++){
               ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
           }
            ans[i][i]=1;
         }
    }
    return ans;
}
// SECOND SOLUTION: we can do using binomial coefficient
// TC: O(n*n)
long long int binomialCoefficient(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }
    long long int res = 1;

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
vector<vector<long long int>> generatePascalTriangle(int num) {
    vector<vector<long long int>> pascalTriangle(num);

    for (int i = 0; i < num; ++i) {
        pascalTriangle[i].resize(i + 1);

        for (int j = 0; j <= i; ++j) {
            pascalTriangle[i][j] = binomialCoefficient(i, j);
        }
    }

    return pascalTriangle;
}
/******************************************************************************/
/*****************NEXT PERMUTATION*******************************************************************/
// SOLUTION 1: using inbuilt function
// TC: O(n)
vector<int> nextPermutation(vector<int> &A, int n)
{
   next_permutation(A.begin(),A.end());

    return A;
}
// SOLUTION 2:
vector<int> nextGreaterPermutation(vector<int> &arr) {
    int n = arr.size(); 
    int pivotind = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivotind = i;
            break;
        }
    }
    if (pivotind == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    int greaterind=-1;
    for (int i = n - 1; i > pivotind; i--) {
        if (arr[i] > arr[pivotind]) {
            greaterind=i;
            break;
        }
    }
     swap(arr[greaterind], arr[pivotind]);
    reverse(arr.begin() + pivotind + 1, arr.end());

    return arr;
}
/**********************************************************************************************/
/**********************MAX SUBARRAY SUM -> KADANE'S ALGORITHM******************************************/
// BRUTE FORCE: simply idea is to initialize a variable named maxi and 
// essentially use a nested loop to iterate through all possible subarrays of the given array
// and keeps track of the maximum sum encountered.
// TC: O(n^2)
// SC: O(1)
long long maxSubarraySum(int nums[], int n)
{
      long long  maxi=0;
         for(int i=0;i<n;i++){
             long long  sum=0;
             for(int j=i;j<n;j++){
                 sum+=nums[j];
                 maxi=max(sum,maxi);
             }
         }
         return maxi;
}
// OPTIMAL APPROACH:
//TC: O(n)
//SC: O(1)
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = INT_MIN; // Initialize the maximum sum to a very small value
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        // Add the current element to the sum
        sum += arr[i];
        // Update the maximum sum if the current sum is greater
        if (sum > maxi) {
            maxi = sum;
        }
        // If the current sum becomes negative, reset it to 0
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
/*********************************** Sort an array of 0s, 1s and 2s************************************/
// BRUTE FORCE APPROACH: sort an array using inbuilt method
// TC:  O(N*logN)
// SC:  O(1)
void sort012_method1(int *arr, int n)
{
   sort(arr,arr+n);
}
// BETTER APPROACH: The  idea is to count the number of 0s and 1s in the given array.
// Since there are only three elements in the array, the count of 2s can be determined
// by subtracting the counts of 0s and 1s from the total number of elements.
// After obtaining the counts, the respective values are placed accordingly in the array.
void sort012_method2(int *arr, int n)
{
    int cnt_0=0,cnt_1=0;
    for(int i=0;i<n;i++){
       if(arr[i]==0){
          cnt_0++;
       }
       if(arr[i]==1){
          cnt_1++;
       }
    }
    for(int i=0;i<cnt_0;i++){
       arr[i]=0;
    }
    for(int i=cnt_0;i<cnt_0+cnt_1;i++){
       arr[i]=1;
    }
    for(int i=cnt_0+cnt_1;i<n;i++){
       arr[i]=2;
    }
}
/***************************STOCK BUY AND SELL*********************************************************/
// TC: O(Size)
// SC: O(1)
int maximumProfit(vector<int> &prices){
   int mini=INT_MAX;
          int maxi=0;
          for(int i=0;i<prices.size();i++){
              mini=min(prices[i],mini);
              maxi=max(maxi,prices[i]-mini);
          }
          return maxi;
}

/*******************************************************************************************************/