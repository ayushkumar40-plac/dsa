class Solution {
public:
    const int m = 1e9 + 7;
// this constant is used for the exponential function
    long long power(long long a, long long b) {
        if (b == 0) return 1;
        long long half = power(a, b / 2);
        long long result = (half * half) % m;
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
      long long even = (n + 1) / 2;  // number of even positions
        long long odd = n / 2;         // number of odd positions
// we are writing 5 and 4 because that gives the position like we have number from 1 to 10 so from there we can choose only 2,4,6,8,0 at even position and 1,3,5,7 at odd position
        return (power(5, even) * power(4, odd)) % m;
    }
};
