#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int m, n, target;

    // Input dimensions of the matrix
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Input the elements of the matrix
    cout << "Enter the elements of the matrix row by row:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Input the target element
    cout << "Enter the target element: ";
    cin >> target;

    // Call the function and display the result
    bool result = searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl;

    return 0;
} 
