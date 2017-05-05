#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


bool ge_comp (int a, int b){

  return a>b;
}

long long max_dot_product(vector<int> a, vector<int> b) {

/*
  for (int i=0; i<a.size();i++){
    if (a[i]< 0) a[i]=abs(a[i]);

  }
  for (int i=0; i<b.size();i++){
    if (b[i]< 0) b[i]=abs(b[i]);

  }*/
  sort(a.begin(),a.end(), ge_comp);
  sort(b.begin(),b.end(),ge_comp);


  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
