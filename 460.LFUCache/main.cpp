#include <iostream>
#include <vector>

class Info {
public:
  Info(int key, int freq, int time):
    key(key), freq(freq), time(time) {}

  int getKey() const {
    return key;
  }

  int getFreq() const {
    return freq;
  }

  int getTime() const {
    return time;
  }

  bool operator < (const Info &b) const {
    if (freq < b.getFreq()) {
      return true;
    } else if (freq == b.getFreq() && time < b.getTime()) {
      return true;
    }
    return false;
  }

private:
  int key;
  int freq;
  int time;
}

class MinHash {
public:
  void set(int key, const Info &value) {
    int pos;
    if (key2pos.find(key) != key2pos.cend()) {
      // found
      remove(key2pos[key]);
    }
    pos = insert(key, value);
    key2pos[key] = pos; 
  }

  int extractMin() {
    Info i = vector.front();
    remove(0);
    return i.getKey();
  }
private:
  int filterUp(int pos) {

  }

  void filterDown(int pos) {

  }

  int insert(int key, const Info &value) {
    values.push_back(value);
  }

  void remove(int pos) {

  }

  map<int, int> key2pos;
  vector<Info> values;
}

class LFUCache {
public:
  LFUCache(int capacity) {
      
  }
  
  int get(int key) {
      
  }
  
  void set(int key, int value) {
      
  }
};

int main() {

}
