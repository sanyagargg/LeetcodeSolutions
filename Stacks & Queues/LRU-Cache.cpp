class LRUCache {
    int capacity;
    std::list<std::pair<int, int>> cache; // {key, value}
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        // Move the accessed item to the front of the list
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Update the value and move to front
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
        } else {
            if (cache.size() == capacity) {
                // Remove the least recently used item
                int lru_key = cache.back().first;
                cache.pop_back();
                map.erase(lru_key);
            }
            // Insert the new item at the front
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};