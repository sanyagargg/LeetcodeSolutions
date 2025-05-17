class LFUCache {
    int capacity, minFreq;
    std::unordered_map<int, std::pair<int, int>> keyToValFreq; // key -> {value, freq}
    std::unordered_map<int, std::list<int>> freqToKeys; // freq -> list of keys
    std::unordered_map<int, std::list<int>::iterator> keyToIter; // key -> iterator in freqToKeys

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end())
            return -1;
        // Update frequency
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }
        freq++;
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();
        keyToValFreq[key].second = freq;
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // Update frequency
            return;
        }
        if (keyToValFreq.size() == capacity) {
            // Evict the least frequently used key
            int evictKey = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty())
                freqToKeys.erase(minFreq);
            keyToValFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }
        // Insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};