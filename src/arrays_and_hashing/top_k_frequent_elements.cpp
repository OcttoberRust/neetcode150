 
 #include <iostream>
 #include <vector>
 #include <unordered_map>
 #include <queue>

 using namespace std;

 class Solution {
 public:
     vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> freqMap;
         for (int num : nums) {
             freqMap[num]++;
         }

         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
         for (const auto& entry : freqMap) {
             minHeap.push({entry.second, entry.first});
             if (minHeap.size() > k) {
                 minHeap.pop();
             }
         }

         vector<int> result;
         while (!minHeap.empty()) {
             result.push_back(minHeap.top().second);
             minHeap.pop();
         }

         return result;
     }
 };

 int main() {
     vector<int> nums = {1, 1, 1, 2, 2, 3};
     int k = 2;

     Solution solution;
     vector<int> result = solution.topKFrequent(nums, k);

     cout << "The " << k << " most frequent elements are: ";
     for (int num : result) {
         cout << num << " ";
     }
     cout << endl;

     return 0;
 }
