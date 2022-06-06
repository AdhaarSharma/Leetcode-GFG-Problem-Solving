class Solution {
private:
    int n_;
    int num_small(vector<vector<int>> &matrix, int up_bound) {
        int num = 0;
        int row = n_ - 1;
        int col = 0;
        while (row >= 0 && col < n_) {
            if (matrix[row][col] <= up_bound) {
                num += row + 1;
                col++;
            }
            else {
                row--;
            }
        }
        return num;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n_ = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n_ - 1][n_ - 1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (num_small(matrix, mid) >= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};