#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

int edit_distance(const string &str1, const string &str2) {
  int s1 = str1.size();
  int s2 = str2.size();
  vector<vector<int> > dist_M(s1 + 1, vector<int>(s2 + 1, 0));
  for(int i = 0; i <= s1; ++i) {dist_M[i][0] = i;}
  for(int i = 0; i <= s2; ++i) {dist_M[0][i] = i;}
  int cost = 0;
  for(int i = 1; i <= s1; ++i) {
    for(int j = 1; j <= s2; ++j) {
      if(str1[i-1] == str2[j-1]) cost = 0;
        else cost = 1;
      dist_M[i][j] = std::min(std::min(dist_M[i-1][j],dist_M[i][j-1]) + 1, dist_M[i-1][j-1] + cost);
      }
    }
    return dist_M[s1][s2];
  //return 0;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
