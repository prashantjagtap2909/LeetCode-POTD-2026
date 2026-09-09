class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        long long commas = 1;
        long long answer = 0;
        while (start <= n) {
            long long end = (start > n / 1000)
                ? n
                : start * 1000 - 1;
            long long count = end - start + 1;
            answer += count * commas;
            start *= 1000;
            ++commas;
        }
        return answer;
    }
};
