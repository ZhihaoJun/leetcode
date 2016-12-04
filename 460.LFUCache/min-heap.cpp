#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
public:
  MinHeap() {}

  int min() const {
    return values.front();
  }

  int extractMin() {
    int m = values.front();
    swap(0, values.size()-1);
    values.pop_back();
    filterDown(0);
    outputVector();
    return m;
  }

  int insert(int v) {
    values.push_back(v);
    int finalPos = filterUp(values.size()-1);
    outputVector();
    return finalPos;
  }

private:
  int filterUp(int pos) {
    if (pos == 0) {
      return 0;
    }

    int ppos = parentPos(pos);
    int value = values.at(pos);
    int pvalue = values.at(ppos);
    while (pvalue > value) {
      swap(ppos, pos);
      pos = ppos;
      if (pos == 0) {
        break;
      }
      ppos = parentPos(pos);
      pvalue = values.at(ppos);
    }
    return pos;
  }

  int filterDown(int pos) {
    int lpos = leftChildPos(pos);
    int rpos = rightChildPos(pos);
    int lvalue = values.at(lpos);
    int rvalue = values.at(rpos);
    bool isLeftBig = lvalue > rvalue;
    int maxvalue = isLeftBig ? lvalue : rvalue;
    int value = values.at(pos);

    if (value > maxvalue) {
      if (isLeftBig) {
        swap(pos, rpos);
        return filterDown(rpos);
      } else {
        swap(pos, lpos);
        return filterDown(lpos);
      }
    }
    return pos;
  }

  int leftChildPos(int pos) {
    return pos*2+1;
  }

  int rightChildPos(int pos) {
    return pos*2+2;
  }

  int parentPos(int pos) {
    return (pos-1)/2;
  }

  void swap(int aPos, int bPos) {
    int tmp = values[aPos];
    values[aPos] = values[bPos];
    values[bPos] = tmp;
  }

  void outputVector() {
    for (auto i : values) {
      cout << i << " ";
    }
    cout << endl;
  }

  vector<int> values;
};

int main() {
  MinHeap *mh = new MinHeap();
  // mh->insert(0);
  mh->insert(10);
  mh->insert(5);
  mh->insert(8);
  mh->insert(1);
  mh->insert(9);
  mh->insert(3);

  cout << mh->extractMin() << endl;
}
