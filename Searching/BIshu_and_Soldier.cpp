//https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/?utm_source=header&utm_medium=search&utm_campaign=he-search
// optimised version - O(NlogN) - used binary search per iteration and then used sorted array's property.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N) || N <= 0) return 0;

    vector<int> powers(N);
    for (int i = 0; i < N; i++) {
        cin >> powers[i];
    }

    sort(powers.begin(), powers.end());

    vector<int> powcum(N);
    powcum[0] = powers[0];
    for (int i = 1; i < N; i++) {
        powcum[i] = powcum[i - 1] + powers[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int bishu_power;
        cin >> bishu_power;

        int count = 0;
        int l = 0, h = N - 1;

        
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (powers[m] <= bishu_power) {
                count = m + 1; 
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        int sum = (count > 0) ? powcum[count - 1] : 0;
        cout << count << " " << sum << "\n";
    }

    return 0;
}
