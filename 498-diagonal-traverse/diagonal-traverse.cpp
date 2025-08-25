class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;

        vector<pair<int, int>> rightStack{{0, 0}};
        vector<pair<int, int>> leftStack;

        while (!rightStack.empty()) {
            while (!rightStack.empty()) {
                auto [row, col] = rightStack.back();
                rightStack.pop_back();
                result.push_back(mat[row][col]);

                if (col == 0 && row + 1 < mat.size()) {
                    leftStack.emplace_back(row + 1, col); 
                }

                if (col + 1 < mat[row].size()) {
                    leftStack.emplace_back(row, col + 1); 
                }
            }

            while (!leftStack.empty()) {
                auto [row, col] = leftStack.back();
                leftStack.pop_back();
                result.push_back(mat[row][col]);

                if (row == 0 && col + 1 < mat[row].size()) {
                    rightStack.emplace_back(row, col + 1); 
                }

                if (row + 1 < mat.size()) {
                    rightStack.emplace_back(row + 1, col); 
                }
            }
        }

        return result;
    }
};