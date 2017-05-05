//Alan adame cse202 28jan17
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <climits>
#include <cmath>
using std::numeric_limits;
using std::vector;
using std::string;
using std::max;
using std::min;
using std::stoll;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int n = (length + 1) / 2;
  long long minArray[n][n];
  long long maxArray[n][n];
  memset(minArray,0,sizeof(minArray));
  memset(maxArray,0,sizeof(maxArray));
  for (int i = 0; i < n; i++)
  {
	  minArray[i][i] = stoll(exp.substr(2*i,1));
	  maxArray[i][i] = stoll(exp.substr(2*i,1));
  }
  long long a,b,c,d;
  long long minVal = LLONG_MAX;
  long long maxVal = LLONG_MIN;
  for (int s = 0; s < n - 1; s++)
  {
	  for (int i = 0; i < n - s - 1; i++)
	  {
		  int j = i + s + 1;
		  minVal = LLONG_MAX;
	    maxVal = LLONG_MIN;
		  for (int k = i; k < j; k++ )
	      {
			  a = eval(minArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  b = eval(minArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  c = eval(maxArray[i][k],minArray[k + 1][j],exp[2 * k + 1]);
			  d = eval(maxArray[i][k],maxArray[k + 1][j],exp[2 * k + 1]);
			  minVal = min(minVal,min(a,min(b,min(c,d))));
			  maxVal = max(maxVal,max(a,max(b,max(c,d))));
	      }
		  minArray[i][j] = minVal;
		  maxArray[i][j] = maxVal;
	  }
  }
  return maxArray[0][n - 1];
}
int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
