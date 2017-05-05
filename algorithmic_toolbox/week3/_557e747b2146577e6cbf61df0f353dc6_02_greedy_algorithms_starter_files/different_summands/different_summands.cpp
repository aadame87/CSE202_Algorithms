//ALAN ADAME CSE202 19JAN17
#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int total=0;
  int i=1;
  while(total+i<=n){
    total+=i;
    summands.push_back(i);
    i++;
  }
  summands[summands.size()-1]+=n-total;
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
