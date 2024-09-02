/*
    Doubling technique
        dp[i+1][j] = dp[i][dp[i][j]]
    Solution to https://atcoder.jp/contests/abc367/tasks/abc367_e
*/

#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long k;
    cin >> k;

    vector<vector<int>> dp(63, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> dp[1][i];  // after first change
        dp[0][i] = i;     // 0 change, same as idx
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i < 63; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = i;
        for (int j = 0; j <= 62; j++) {
            if (k & (1LL << j)) {
                x = dp[j + 1][x];  // e.g. bit 0 indicates 1 permute
            }
        }

        cout << a[x] << " ";
    }
}
