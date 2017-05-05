//ALAN ADAME CSE202 WEEK1 12JAN17
#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    //int previous = 0;
    //int current  = 1;
    int numbers[3];
    numbers[0]=0;
    numbers[1]=1;
    for (int i = 0; i < n - 1; ++i) {
        numbers[2]=numbers[0] % 10 + numbers[1] % 10;
        numbers[0]=numbers[1];
        numbers[1]=numbers[2];
    }

    return numbers[2]%10;
}


int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
