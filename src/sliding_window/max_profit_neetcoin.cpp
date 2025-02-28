 
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <limits>

 using namespace std;

 int maxProfit(const vector<int>& prices) {
     int minPrice = numeric_limits<int>::max();
     int maxProfit = 0;
     for (int price : prices) {
         minPrice = min(minPrice, price);
         maxProfit = max(maxProfit, price - minPrice);
     }
     return maxProfit;
 }

 int main() {
     vector<int> prices = {7, 1, 5, 3, 6, 4};
     cout << "Maximum profit: " << maxProfit(prices) << endl;
     return 0;
 }
