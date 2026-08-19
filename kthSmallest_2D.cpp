class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {        
        
        vector<int> all;
        int n = matrix.size();
        int m = matrix[0].size();

     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                all.push_back(matrix[i][j]);
            }
        }

        sort(all.begin(), all.end());

        return all[k - 1];
    }
};
