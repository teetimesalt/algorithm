#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG

template <typename T>
void print(string &&msg, T&& value) {
#ifdef DEBUG
  cout << msg << " " << value << endl;
#endif
}

template <typename T>
void print(string &&msg, vector<T> &vec) {
#ifdef DEBUG
  cout << msg << " ";
  typename vector<T>::iterator it;

  for(it = vec.begin() ; it != vec.end() ; it++) {
    cout << *it << " ";
  }
  cout << endl;
#endif
}

void print(string &&msg, vector<vector<int>> &points) {
#ifdef DEBUG
  cout << msg << " ";
  vector<vector<int>>::iterator it;

  for(it = points.begin() ; it != points.end() ; it++) {
    print("", *it);
  }
  cout << endl;
#endif
}