class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        bool a = false , b = false;
        int n = matrix.size();
        int m = matrix[0].size();

        // below loops are for traversing matrix
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){

                // find minimum element in matrix
                int at = *min_element(matrix[i].begin(),matrix[i].end());

                if(matrix[i][j] == at)a = true;

                int kt = INT_MIN;
                for(int k = 0;k<n;k++){
                    if(matrix[k][j]>kt)kt = matrix[k][j];
                }
                if(kt == matrix[i][j])b = true;

                if(a && b)ans.push_back(matrix[i][j]);
                a = false , b = false;
            }
        }
        return ans;
    }
};