 
 #include <string>
 #include <vector>
 #include <iostream>
 using namespace std;

 class Codec {
 public:
     string encode(const vector<string>& strs) {
         string encoded;
         for (const auto& s : strs) {
             encoded += to_string(s.size()) + "#" + s;
         }
         return encoded;
     }

     vector<string> decode(const string& s) {
         vector<string> result;
         size_t i = 0;
         while (i < s.size()) {
             size_t pos = s.find('#', i);
             int len = stoi(s.substr(i, pos - i));
             string str = s.substr(pos + 1, len);
             result.push_back(str);
             i = pos + 1 + len;
         }
         return result;
     }
 };

 int main() {
     Codec codec;
     vector<string> original = {"hello", "world", "#special#", ""};
     string encoded = codec.encode(original);
     cout << "Encoded: " << encoded << "\n";

     vector<string> decoded = codec.decode(encoded);
     cout << "Decoded strings:\n";
     for (const auto& str : decoded) {
         cout << "\"" << str << "\"\n";
     }
     return 0;
 }
