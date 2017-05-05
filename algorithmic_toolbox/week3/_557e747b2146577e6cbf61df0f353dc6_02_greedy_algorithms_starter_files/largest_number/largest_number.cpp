//ALAN ADAM CSE202 19JAN17
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
//#include <cstdlib>

using std::vector;
using std::string;

bool is_Ge(string x, string y){

//std::cout << x << y << '\n';
/*
int x1 = stoi(x);
int y2 = stoi(y);
if (x1>9) x1= (x1/10)%10;
else if (y2>9) y2=(y2/10)%10;
return x1>=y2;*/
  x = x.append(y);
  y = y.append(x);
  return x >= y;

}

bool is_Ge2(int x, int y){

//std::cout << x << y;

//int x1 = stoi(x);
//int y2 = stoi(y);
if (x>9) x= (x/10)%10;
else if (y>9) y=(y/10)%10;
return x>=y;

}
string largest_number(vector<string> a) {
/*
  vector<int> aints(a.size());
  for (int i=0;i<aints.size();i++){

    aints[i]=stoi(a[i]);
    }
*/
  sort(a.begin(),a.end(),is_Ge);
  //sort(aints.begin(), aints.end(),is_Ge2);

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
    //std::cout << aints[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
