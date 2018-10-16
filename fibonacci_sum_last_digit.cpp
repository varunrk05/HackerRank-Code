//Problem Statement-The goal in this problem is to find the last digit of a sum of the first 𝑛 Fibonacci numbers.


#include <iostream>

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

int get_fibonacci_last_digit_fast(int n) {
    // write your code here
    int64_t arr[n];

    for(int i=0;i<=n;i++)
        arr[i]=0;
    arr[0]=0;
    arr[1]=1;
    for(int j=2;j<=n;j++)
    {

        arr[j]=(arr[j-1]+arr[j-2])%10;
    }


    return arr[n];
}
int get_fibonacci_last_digit_fast(long long n) {

    if (n <= 1)

        return n;



    int previous = 0;

    int current = 1;



    for (int i = 0; i < n - 1; ++i) {

        int tmp_previous = previous % 10;

        previous = current % 10;

        current = tmp_previous + current % 10;

    }

    return current % 10;

}



int fibonacci_sum_fast(long long n) {

    int new_n = (n + 2) % 60;

    int new_last = get_fibonacci_last_digit_fast(new_n);

    if (new_last == 0) {

        return 9;

    } else {

        return new_last - 1;

    }

}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
