class Solution {
    const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < sz; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) return r - l + 1;

        int k = r - l + 1;
        int sz = 2 * k;

        Matrix M(sz, vector<long long>(sz, 0));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < i; j++) {
                M[i][k + j] = 1;
            }

            for (int j = i + 1; j < k; j++) {
                M[k + i][j] = 1;
            }
        }

        Matrix res(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            res[i][i] = 1;
        }

        long long p = n - 1;

        while (p > 0) {
            if (p % 2 == 1) {
                res = multiply(res, M);
            }

            M = multiply(M, M);
            p /= 2;
        }

        long long ans = 0;

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                ans = (ans + res[i][j]) % MOD;
            }
        }

        return (int)ans;
    }
};
