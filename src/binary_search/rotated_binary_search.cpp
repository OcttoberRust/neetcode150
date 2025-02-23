 
 #include <vector>
 #include <iostream>

 int search(std::vector<int>& nums, int target) {
     int left = 0, right = nums.size() - 1;

     while (left <= right) {
         int mid = left + (right - left) / 2;

         if (nums[mid] == target) return mid;

         if (nums[left] <= nums[mid]) {
             if (nums[left] <= target && target < nums[mid]) {
                 right = mid - 1;
             } else {
                 left = mid + 1;
             }
         }
         else {
             if (nums[mid] < target && target <= nums[right]) {
                 left = mid + 1;
             } else {
                 right = mid - 1;
             }
         }
     }

     return -1;  // Target not found
 }

 int main() {
     std::vector<int> nums = {3, 4, 5, 6, 1, 2};
     int target = 1;
     int index = search(nums, target);
     std::cout << "Index of " << target << " is: " << index << std::endl;
     return 0;
 }
