class LRUCache {
private:
    int capacity = 0;
    list<int> keys;
    unordered_map<int, pair<list<int>::iterator, int>> map;

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        keys.erase(map[key].first);
        keys.push_front(key);
        map[key].first = keys.begin();

        return map[key].second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            keys.erase(map[key].first);
        } else if (keys.size() == capacity) {
            map.erase(keys.back());
            keys.pop_back();
        }

        keys.push_front(key);
        map[key] = {keys.begin(), value};
    }
};
