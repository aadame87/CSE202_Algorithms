#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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
        //if (numbers[2]<0) return (numbers[2]* (-1)) % m ;
        return numbers[2] % m;
  }

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
int toint =(get_fibonacci_huge_fast(to+2,10) -1);
int fromint =(get_fibonacci_huge_fast(from+1,10)-1);
if (fromint==10) fromint=0;
int ans = toint - fromint;
if (ans>0) return ans;
else return (ans + 10) % 10 ;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
