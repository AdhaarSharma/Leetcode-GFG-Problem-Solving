class Solution {
public:
    int numsLess(int num, const int &n, const vector<vector<int>>& matrix){
        int row = n-1;
        int col = 0;
        int count = 0;
        while(row >= 0 && col < n){
            if(matrix[row][col] <= num){
                count += row + 1;
                col++;
            }
            else {
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(numsLess(mid, n, matrix) < k){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};