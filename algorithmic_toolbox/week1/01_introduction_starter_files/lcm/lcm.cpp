//ALAN ADAME CSE202 13JAN17 WEEK1
#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int x, int y){
  //int current_gcd=1;
  if (y == 0)
    return x;
  else
    return gcd_fast(y, x%y);


}

long long lcm_fast(int a, int b) {
  /*if (a==1)
    return b;
  if (b==1)
    return a;
*/
/*
  long max;
  long min;
  if (a>b)
    {max=a;
    min=b;}
  else
    {max=b;
    min=a;}

  if(max-min==1)
    return (long long) max*min;

  for (long l = max; l <= (long long) a * b; l+=max)
    if (l % min == 0)
      return l;

  return (long long) a * b;
*/
return (long long) a*b/gcd_fast(a,b);

}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
