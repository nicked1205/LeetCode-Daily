class Solution {
public:
    int numberOfWays(string c) {
        const long long MOD = 1000000007;
        int chairs = 0;
        int totalChairs = 0;
        int n = c.size();

        if (n == 1) return 0;

        long long res = 1;
        int i = 0;
        bool valid = false;
        while (i < n) {
            if (c[i] == 'S') {
                chairs++;
                totalChairs++;
            }

            // cout << "i = " << i << ", chairs = " << chairs << endl;

            if (chairs == 2) {
                int plants = 0;
                while (i + 1 < n && c[i + 1] == 'P') {
                    plants++;
                    // cout << "i = " << i + 1 << ", plants = " << plants << endl;
                    i++;
                }
                valid = true;
                if (i + 1 < n) res = (res * (plants + 1)) % MOD;
                chairs = 0;
            }
            i++;
        }
        if (!valid || totalChairs % 2 == 1) return 0;
        return (int)res;
    }
};