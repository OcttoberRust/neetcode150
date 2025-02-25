 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 class Solution {
 public:
     int minEatingSpeed(vector<int>& piles, int h) {
         int lo = 1;
         int hi = *max_element(piles.begin(), piles.end());

         while (lo < hi) {
             int mid = lo + (hi - lo) / 2;
             long long hours = 0;

             for (int pile : piles) {
                 hours += (pile + mid - 1) / mid;
             }

             if (hours <= h)
                 hi = mid;
             else
                 lo = mid + 1;
         }

         return lo;
     }
 };

 int main() {
     vector<int> piles = {3, 6, 7, 11};
     int h = 8;

     Solution sol;
     int minSpeed = sol.minEatingSpeed(piles, h);

     cout << "Minimum eating speed to finish all bananas in " << h << " hours is: " << minSpeed << endl;
     return 0;
 }
