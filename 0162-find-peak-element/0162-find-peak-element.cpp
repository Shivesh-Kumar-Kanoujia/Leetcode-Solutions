class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak must exist on the right side
                low = mid + 1;
            } else {
                // Peak is at mid or on the left side
                high = mid;
            }
        }

        return low;
    }
};