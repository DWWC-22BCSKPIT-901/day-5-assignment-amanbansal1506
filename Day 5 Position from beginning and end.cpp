#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search for the first or last occurrence
int binarySearch(const vector<int>& nums, int target, bool findFirst) {
    int left = 0, right = nums.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid; // Record the index
            if (findFirst) {
                right = mid - 1; // Search in the left half for the first occurrence
            } else {
                left = mid + 1; // Search in the right half for the last occurrence
            }
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

// Main function to find the starting and ending positions
vector<int> searchRange(const vector<int>& nums, int target) {
    int start = binarySearch(nums, target, true);  // Find the starting position
    if (start == -1) {
        return {-1, -1};  // If target is not found, return [-1, -1]
    }
    int end = binarySearch(nums, target, false); // Find the ending position
    return {start, end};
}

int main() {
    int n, target;

    // Input size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input the elements of the array
    vector<int> nums(n);
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Input the target element
    cout << "Enter the target element: ";
    cin >> target;

    // Call the function and display the result
    vector<int> result = searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
