#include <iostream>
#include <vector>
#include <unordered_set>

bool hasDuplicate(std::vector<int>& nums) {
	std::unordered_set<int> seen;
	for (int num : nums) {
		if (seen.find(num) != seen.end()) {
			return true;
		}
		
		seen.insert(num);
	}

	return false;
}

int main() {
	std::vector<int> nums = {1,2,3,3,4,5,6,7};
	if(hasDuplicate(nums)) {
		std::cout << "Has duplicates\n";
	} else {
		std::cout << "Does not have duplicates\n";
	}

	return 0;
}
