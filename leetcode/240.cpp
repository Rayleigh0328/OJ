class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;
        if (matrix[0].empty()) return false;
        
        int min_row = 0, max_row = matrix.size()-1, min_col = 0, max_col = matrix[0].size()-1;
        while (true)
        {
            // delete col
            while (matrix[max_row][min_col]<target) ++min_col;
            if (min_col > max_col) return false;
            if (matrix[max_row][min_col]==target) return true;
            
            while (matrix[min_row][max_col]>target) --max_col;
            if (min_col > max_col) return false;
            if (matrix[min_row][max_col]==target) return true;
            
            // delete row
            while (matrix[min_row][max_col]<target) ++min_row;
            if (min_row > max_row) return false;
            if (matrix[min_row][max_col]==target) return true;
            
            while (matrix[max_row][min_col]>target) --max_row;
            if (min_row > max_row) return false;
            if (matrix[max_row][min_col]==target) return true;
        }
        return false;
    }
};