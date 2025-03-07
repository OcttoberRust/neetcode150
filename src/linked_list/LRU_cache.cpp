#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()){
            return -1;
        }
        usage.splice(usage.begin(), usage, it->second.second);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
=            it->second.first = value;
=            usage.splice(usage.begin(), usage, it->second.second);
        } else {
            if (cache.size() == capacity) {
                int lruKey = usage.back();
                usage.pop_back();
                cache.erase(lruKey);
            }
            usage.push_front(key);
            cache[key] = {value, usage.begin()};
        }
    }

private:
    int capacity;
    std::list<int> usage;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
};

int main() {
    LRUCache cache(2);

    std::cout << "Put (1, 1)" << std::endl;
    cache.put(1, 1);

    std::cout << "Put (2, 2)" << std::endl;
    cache.put(2, 2);

    std::cout << "Get (1): " << cache.get(1) << std::endl;

    std::cout << "Put (3, 3)" << std::endl;
    cache.put(3, 3);

    std::cout << "Get (2): " << cache.get(2) << std::endl;

    std::cout << "Put (4, 4)" << std::endl;
    cache.put(4, 4);

    std::cout << "Get (1): " << cache.get(1) << std::endl;
    std::cout << "Get (3): " << cache.get(3) << std::endl;
    std::cout << "Get (4): " << cache.get(4) << std::endl;

    return 0;
}

