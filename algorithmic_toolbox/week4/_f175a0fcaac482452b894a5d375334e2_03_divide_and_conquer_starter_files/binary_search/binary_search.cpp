//ALAN ADAME CSE202 23JAN17

#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>       /* floor */

using std::vector;

int binary_search(const vector<int> &a,int left, int right, int x) {
  //left = 0;
  //right = (int)a.size();
  if (left > right) return  -1;
  int mid = floor(left + (right - left)/2);
  if (x==a[mid]) return mid;
  else if (x<a[mid]) return binary_search(a, left,mid-1,x);
  else return binary_search(a,mid+1, right,x);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, 0, a.size(), b[i]) << ' ';
  }
}
