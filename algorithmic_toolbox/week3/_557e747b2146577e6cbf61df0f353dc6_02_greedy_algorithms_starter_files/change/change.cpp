//ALAN ADAME CSE202 17JAN17
#include <iostream>

int get_change(int m) {
  int total = m;
  int dime = 10;
  int nickel = 5;
  int penny = 1;
  int n = 0;
  while (total >0) {
      if (total >= dime) {total-= dime;n++;}
      else if (total >= nickel) {total -=nickel;n++;}
      else {total-=penny;n++;}


  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
