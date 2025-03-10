class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int upper_row = 0, lower_row = m - 1;
        int lidx, ridx, midx;
        bool found = false;

        while (upper_row <= lower_row) {
            if (target <= matrix[upper_row][n-1]) { // target in upper_row
                lidx = 0;
                ridx = n-1;
                while (lidx <= ridx) {
                    midx = (lidx + ridx) / 2;
                    if (target == matrix[upper_row][midx]) { found = true; break; }
                    if (target > matrix[upper_row][midx]) { lidx = midx + 1; }
                    else { ridx = midx - 1; }
                }
                break;
            } else if (target >= matrix[lower_row][0]) { // target in lower_row
                lidx = 0;
                ridx = n-1;
                while(lidx <= ridx) {
                    midx = (lidx + ridx) / 2;
                    if (target == matrix[lower_row][midx]) { found = true; break; }
                    if (target > matrix[lower_row][midx]) { lidx = midx + 1; }
                    else { ridx = midx - 1; }
                }
                break;
            } else {
                upper_row++;
                lower_row--;
            }
        }

        return found;
    }
};