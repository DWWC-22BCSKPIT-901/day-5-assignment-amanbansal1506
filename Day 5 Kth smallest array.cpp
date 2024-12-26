#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct Node {
    int sum;
    vector<int> indices;
    
    // Constructor
    Node(int sum, vector<int>& indices) : sum(sum), indices(indices) {}
};

// Comparator to compare Node by their sum
struct Compare {
    bool operator()(Node& n1, Node& n2) {
        return n1.sum > n2.sum;
    }
};

int kthSmallestSum(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    
    // Min-Heap to store the current smallest sums
    priority_queue<Node, vector<Node>, Compare> pq;
    
    // Initialize the heap with the smallest sum of each row (first element of each row)
    vector<int> initialIndices(m, 0);
    int initialSum = 0;
    for (int i = 0; i < m; i++) {
        initialSum += mat[i][0];
    }
    
    pq.push(Node(initialSum, initialIndices));
    
    // Extract k smallest sums
    int count = 0;
    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();
        
        count++;
        if (count == k) {
            return currentNode.sum;
        }
        
        // Try to move to the next element in each row, if possible
        for (int i = 0; i < m; i++) {
            if (currentNode.indices[i] + 1 < n) {
                vector<int> newIndices = currentNode.indices;
                newIndices[i]++;
                
                int newSum = currentNode.sum - mat[i][currentNode.indices[i]] + mat[i][newIndices[i]];
                pq.push(Node(newSum, newIndices));
            }
        }
    }
    
    return -1; // If k is out of bounds
}

int main() {
    int m, n, k;
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the matrix values:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cout << "Enter k: ";
    cin >> k;
    
    int result = kthSmallestSum(mat, k);
    cout << "The " << k << "th smallest sum is: " << result << endl;

    return 0; }
