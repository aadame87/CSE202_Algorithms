//ALAN ADAME CSE202 28JAN17
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_fast(int n) {
  vector<int> sequence;
	vector<int>  path(n+1);
	for(int i =1; i< path.size(); i++){
		path[i] = path[i-1] + 1;
		if (i%2 == 0)
			path[i] = std::min(1 + path[i/2], path[i]);
		if (i%3 == 0)
			path[i] = std::min(1 + path[i/3], path[i]);
	}
	int i = n;
	while (i>1) {
		sequence.push_back(i);
		if (path[i-1] == path[i]-1)
			i = i-1;
		else if (i%2 == 0 && (path[i/2] == path[i]-1))
			i = i/2;
		else if (i%3 == 0 && (path[i/3] == path[i]-1))
			i = i/3;
	}
	sequence.push_back(1);
	reverse(sequence.begin(), sequence.end());
	return sequence;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_fast(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
