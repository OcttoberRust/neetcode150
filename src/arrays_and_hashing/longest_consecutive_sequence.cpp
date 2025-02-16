 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <unordered_set>
 #include <unordered_map>
 using namespace std;

 int longestConsecutiveSorting(vector<int>& nums) {
     if (nums.empty()) return 0;
     sort(nums.begin(), nums.end());
     int longest = 1;
     int current = 1;
     for (size_t i = 1; i < nums.size(); i++) {
         if (nums[i] == nums[i - 1] + 1) {
             current++;
         } else if (nums[i] == nums[i - 1]) {
             continue;
         } else {
             current = 1;
         }
         longest = max(longest, current);
     }
     return longest;
 }

 int longestConsecutiveHashSet(vector<int>& nums) {
     unordered_set<int> numSet(nums.begin(), nums.end());
     int longest = 0;
     for (int num : numSet) {
         if (numSet.find(num - 1) == numSet.end()) {
             int current = num;
             int length = 1;
             while (numSet.find(current + 1) != numSet.end()) {
                 current++;
                 length++;
             }
             longest = max(longest, length);
         }
     }
     return longest;
 }

 int main() {
     vector<int> nums = {100, 4, 200, 1, 3, 2};

     cout << "Sorting Approach: " << longestConsecutiveSorting(nums) << endl;
     cout << "Hash Set Approach: " << longestConsecutiveHashSet(nums) << endl;

     return 0;
 }
