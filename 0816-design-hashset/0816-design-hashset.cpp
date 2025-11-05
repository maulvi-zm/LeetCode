class MyHashSet {
private:
  vector<int> sets;

public:
  MyHashSet() {}

  void add(int key) {
    for (auto element : sets) {
      if (element == key)
        return;
    }

    sets.push_back(key);
  }

  void remove(int key) {
    for (auto it = sets.begin(); it != sets.end(); it++) {
      if (*it == key) {
        sets.erase(it);
        return;
      }
    }
  }

  bool contains(int key) {
    for (auto it = sets.begin(); it != sets.end(); it++) {
      if (*it == key) {
        return true;
      }
    }

    return false;
  }
};
