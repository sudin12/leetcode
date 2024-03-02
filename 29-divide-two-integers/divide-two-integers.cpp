class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN)
                return INT_MAX;
            return -dividend;
        }

        long long quotient = 0;
        long long m = abs((long long)dividend);
        long long n = abs((long long)divisor);

        while (m >= n) {
            long long temp = n, multiple = 1;
            while (m >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            m -= temp;
            quotient += multiple;
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};