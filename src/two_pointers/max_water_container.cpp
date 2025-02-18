 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 class Solution {
 public:
     int maxArea(vector<int>& height) {
         int left = 0, right = height.size() - 1;
         int maxWater = 0;
         while (left < right) {
             int currentWater = min(height[left], height[right]) * (right - left);
             maxWater = max(maxWater, currentWater);
             if (height[left] < height[right])
                 left++;
             else
                 right--;
         }
         return maxWater;
     }
 };

 int main() {
     vector<int> heights = {1, 7, 2, 5, 4, 7, 3, 6};

     Solution solution;

     int result = solution.maxArea(heights);

     cout << "Maximum amount of water the container can store: " << result << endl;

     return 0;
 }
