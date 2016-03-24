class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        
        if (target < matrix[0][0]) return false;
        
        // find last matrix[line][0] that no larger than target
        int left = 0, right = n-1;
        int line;
        while (left <= right)
        {
            if (left == right) 
            {
                line = left;
                break;
            }
            if (left == right - 1)
            {
                line = (matrix[right][0] <= target)?right:left;
                break;
            }
            int mid = (left + right)/2;
            if (matrix[mid][0] > target) right = mid;
            else left = mid;
        }
        cout << "line: " << line << endl;
        
        left = 0;
        right = matrix[line].size()-1;
        while (left <= right)
        {
            if (left == right) return (matrix[line][left] == target);
            if (left == right - 1)
                return (matrix[line][left] == target || matrix[line][right] == target);
            int mid = (left + right)/2;
            if (matrix[line][mid] == target) return true;
            if (matrix[line][mid] < target) left = mid;
            else right = mid;
        }
    }
};