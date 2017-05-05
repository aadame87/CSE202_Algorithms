//ALAN ADAME CSE202 15JAN17

#include <iostream>
#include <math.h>
#include <cmath>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(long long n) {
    if (n <= 1)
        return n;

    //int previous = 0;
    //int current  = 1;
    int numbers[3];
    numbers[0]=0;
    numbers[1]=1;
    for (long long i = 0; i < n - 1; ++i) {
        numbers[2]=numbers[0] % 10 + numbers[1] % 10;
        numbers[0]=numbers[1];
        numbers[1]=numbers[2];
    }

    return numbers[2]%10;
}

long long get_pisano_period(long long m) {
    long long numbers[3];
    numbers[0]=0;
    numbers[1]=1;
    long long i=0;

    while(true){
        numbers[2]=(numbers[0]+numbers[1]) % m;
        numbers[0]=numbers[1];
        numbers[1]=numbers[2];
        if (numbers[0]==0 && numbers[1]==1)
          return i+1;
        i++;
    }
    //return 0;
}

long long get_fibonacci_huge_fast(long long n, long long m){

        if(n<=1) return n;
        long long numbers[3];
        numbers[0]=0;
        numbers[1]=1;
        numbers[2]= numbers[0]+numbers[1];
        if (n<100000){
        for(int i=2;i<=n;i++){
          numbers[2]=(numbers[0]+numbers[1]) % m;
          numbers[0]= numbers[1];
          numbers[1]= numbers[2];
        }
        return numbers[2];
      }

        long long modP = n % get_pisano_period(m);
                  //std::cout << modP << '\n';
        numbers[2]=modP;
        for (long long i = 1; i < modP; i++) {
            numbers[2]=(numbers[0]+numbers[1]) % m;
            numbers[0]= numbers[1];
            numbers[1]= numbers[2];
        }
        if (numbers[2]==0) return 10;
        return numbers[2] % m;
  }

long long get_fibonacci_sum_fast(long long n){

    if(n<=1)
        return n;
    long long result;
    double sqfive_pos=1.+sqrt(5.);
    double sqfive_neg=1.-sqrt(5.);
    double sqfive = sqrt(5.);
    //for(long long i=1;i<n;i++){
         result+=(pow(sqfive_pos/2.,n) - pow(sqfive_neg/2.,n)) / sqfive;
         result=result%10;
    //}
    return result;
    /*long long numbers[3];
    numbers[0]=0;
    numbers[1]=1;

    for (long long i=0; i<n-1; i++) {
        numbers[2]= numbers[0] % m + numbers[1] % m;
        numbers[0]=numbers[1];
        numbers[1]=numbers[2];
      }
      return numbers[2] % m;
      */
/*
      long long numbers[2][2] = {{1,0},{0,1}};
      int numbers2[2][2] = {{1,1},{1,0}};
      for (long long i = 1; i<n;i++){
          numbers = numbers * numbers2;
      }
      return numbers[0][0];
*/
  }



int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << get_fibonacci_huge_fast(n+2,10)-1<< '\n';
}
