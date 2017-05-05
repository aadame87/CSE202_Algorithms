//ALAN ADAME CSE202 15JAN17

#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
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
        return numbers[2] % m;
  }

int main() {
    long long n, m;
    std::cin >> n >> m;
    //n=99999999999999999;
    //m=2;
    //for(int i=0;i<1000;i++){

    std::cout << get_fibonacci_huge_fast(n, m) << '\n';//}
}
