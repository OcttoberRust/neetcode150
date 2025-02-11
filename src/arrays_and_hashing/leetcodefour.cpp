#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

//O(n x mlogm) solution
vector<vector<string>> groupAnagramsSort(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }

    vector<vector<string>> result;
    for (auto& entry : anagramGroups) {
        result.push_back(move(entry.second));
    }

    return result;
}

//O(n x m) solution
vector<vector<string>> groupAnagramsCount(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;

    for (const string& s : strs) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        string key;
        for (int i = 0; i < 26; i++) {
            key += "#" + to_string(count[i]);
        }
        groups[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& entry : groups) {
        result.push_back(move(entry.second));
    }

    return result;
}

void printAnagrams(const vector<vector<string>>& groups) {
    for (const auto& group : groups) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    cout << "Sorting-based solution:" << endl;
    vector<vector<string>> resultSort = groupAnagramsSort(input);
    printAnagrams(resultSort);
    cout << endl;

    cout << "Frequency count solution:" << endl;
    vector<vector<string>> resultCount = groupAnagramsCount(input);
    printAnagrams(resultCount);

    return 0;
}
