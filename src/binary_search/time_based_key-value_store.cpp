 
 #include <iostream>
 #include <unordered_map>
 #include <vector>
 #include <string>
 using namespace std;

 class TimeMap {
 public:
     unordered_map<string, vector<pair<int, string>>> store;

     TimeMap() { }

     void set(string key, string value, int timestamp) {
         store[key].push_back({timestamp, value});
     }

     string get(string key, int timestamp) {
         if (store.find(key) == store.end())
             return "";

         const auto &vec = store[key];
         int left = 0, right = vec.size() - 1;
         string result = "";

         while (left <= right) {
             int mid = left + (right - left) / 2;
             if (vec[mid].first <= timestamp) {
                 result = vec[mid].second;
                 left = mid + 1;
             } else {
                 right = mid - 1;
             }
         }
         return result;
     }
 };

 // Example usage:
 int main() {
     TimeMap tm;
     tm.set("foo", "bar", 1);
     cout << tm.get("foo", 1) << endl;
     cout << tm.get("foo", 3) << endl;
     tm.set("foo", "bar2", 4);
     cout << tm.get("foo", 4) << endl;
     cout << tm.get("foo", 5) << endl;
     return 0;
 }
