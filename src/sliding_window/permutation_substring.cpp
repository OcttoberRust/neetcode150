 #include <iostream>
 #include <string>
 #include <vector>
 using namespace std;

 class Solution {
 public:
     bool checkInclusion(string s1, string s2) {
         int n1 = s1.size(), n2 = s2.size();
         if(n1 > n2) return false;

         vector<int> count1(26, 0), count2(26, 0);

         for (int i = 0; i < n1; i++) {
             count1[s1[i] - 'a']++;
             count2[s2[i] - 'a']++;
         }

         if(count1 == count2)
             return true;

         for (int i = n1; i < n2; i++) {
             count2[s2[i] - 'a']++;
             count2[s2[i - n1] - 'a']--;

             if(count1 == count2)
                 return true;
         }

         return false;
     }
 };

 int main() {
     Solution solution;
     string s1, s2;

     cout << "Enter the first string (s1): ";
     cin >> s1;
     cout << "Enter the second string (s2): ";
     cin >> s2;

     bool exists = solution.checkInclusion(s1, s2);
     cout << "Does s2 contain a permutation of s1? "
     << (exists ? "True" : "False") << endl;

     return 0;
 }
