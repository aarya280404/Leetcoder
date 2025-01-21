class Solution {
    #define MOD 1000000007

public:
    // Function to calculate (base^exp) % MOD using iterative modular exponentiation
    long long modPower(long long base, long long exp) {
        long long result = 1;
        base %= MOD; // Ensure base is within modulo range
        while (exp > 0) {
            if (exp % 2 == 1) {       // If exp is odd
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD; // Square the base
            exp /= 2;                   // Halve the exponent
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        // Calculate number of even and odd places
        long long even = (n / 2) + (n % 2); // Even places include the extra for odd-length sequences
        long long odd = n / 2;

        // Calculate the result as (5^odd * 4^even) % MOD
        long long result = (modPower(5, even) * modPower(4, odd)) % MOD;
        return (int)result;
    }
};
