 
 #include <iostream>
 #include <unordered_map>
 #include <algorithm>

 bool isAnagram(std::string s, std::string t) {
     if (s.length() != t.length()) return false;

     std::unordered_map<char, int> letter_frequency;

     for (char c : s) {
         letter_frequency[c]++;
     }

     for (char c : t) {
         if (letter_frequency[c] == 0) {
             return false;
         }
         letter_frequency[c]--;
     }

     return true;
 }

 int main() {
     std::string s = "racecar";
     std::string t = "carrace";

     if (isAnagram(s, t)) {
         std::cout << "The strings are anagrams.\n";
     } else {
         std::cout << "The strings are NOT anagrams.\n";
     }

     return 0;
 }
