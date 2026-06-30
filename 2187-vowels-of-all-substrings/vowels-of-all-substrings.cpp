class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                ans += 1LL * (i + 1) * (n - i);
            }
        }

        return ans;
    }
};