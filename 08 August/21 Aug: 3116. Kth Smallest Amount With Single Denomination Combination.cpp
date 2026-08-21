class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        
        if (coins[0] == 1) return k;
        
        int n = coins.size(), r = 0, c, j;
        
        // Remove redundant coins
        for (int i = 0; i < n - r - 1; i++) {
            c = coins[i];
            j = i + 1;
            
            while (j < n - r) {
                if (coins[j] % c == 0) {
                    coins.erase(coins.begin() + j);
                    r++;
                } else {
                    j++;
                }
            }
        }
        
        if (n - r == 1) {
            return (long long)coins[0] * k;
        }
        
        int a = n - r;
        
        long long low = coins[0];
        long long high = (long long)coins[0] * k;
        long long result = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = countNums(coins, mid, a);
            
            if (count >= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
    
private:
    long long gcd(long long a, long long b) {
        while (b > 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    
    long long countNums(vector<int>& c, long long m, int a) {
        long long sum = 0;
        int totalMasks = 1 << a;
        
        for (int mask = 1; mask < totalMasks; mask++) {
            long long common = 1;
            int bits = 0;
            
            for (int i = 0; i < a; i++) {
                if ((mask & (1 << i)) != 0) {
                    common = lcm(common, (long long)c[i]);
                    bits++;
                }
            }
            
            if ((bits & 1) == 1) {
                sum += m / common;
            } else {
                sum -= m / common;
            }
        }
        
        return sum;
    }
};
