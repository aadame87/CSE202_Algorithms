#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_fast(int W, const vector<int> &w) {
  vector<int> c(W+1);
  for (size_t i = 0; i < w.size(); ++i) {
	  for(int j = W; j - w[i] >= 0; --j) {
			c[j] = std::max(c[j], c[j - w[i]] + w[i]);
	  }
  }
  return c[W];
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_fast(W, w) << '\n';
}
