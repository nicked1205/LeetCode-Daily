class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        for (int i = n - 1; i > n - 1 - k; i--) {
            for (int j = i - k; j >= 0; j -= k) {
                energy[j] += energy[j + k];
            }
        }

        auto it = max_element(energy.begin(), energy.end());
        return *it;
    }
};