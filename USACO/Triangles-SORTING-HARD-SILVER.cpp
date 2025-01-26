#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
const int MAX_C = 1e4;
int x[MAX_N], y[MAX_N];
long long heightsum[MAX_N], basesum[MAX_N];
vector<pair<int, int>> xcoords[2 * MAX_C + 1], ycoords[2 * MAX_C + 1];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        xcoords[x[i] + MAX_C].push_back({y[i], i});
        ycoords[y[i] + MAX_C].push_back({x[i], i});
    }
    for (int i = 0; i <= 2 * MAX_C; i++) {
        if (!xcoords[i].empty()) {
            long long curr = 0;
            sort(xcoords[i].begin(), xcoords[i].end());
            for (int j = 1; j < xcoords[i].size(); j++) {
                curr += xcoords[i][j].first - xcoords[i][0].first;
            }
            heightsum[xcoords[i][0].second] = curr;
            for (int j = 1; j < xcoords[i].size(); j++) {
                curr += (2 * j - xcoords[i].size()) * (xcoords[i][j].first - xcoords[i][j - 1].first);
                heightsum[xcoords[i][j].second] = curr;
            }
        }
    }
    for (int i = 0; i <= 2 * MAX_C; i++) {
        if (!ycoords[i].empty()) {
            long long curr = 0;
            sort(ycoords[i].begin(), ycoords[i].end());
            for (int j = 1; j < ycoords[i].size(); j++) {
                curr += ycoords[i][j].first - ycoords[i][0].first;
            }
            basesum[ycoords[i][0].second] = curr;
            for (int j = 1; j < ycoords[i].size(); j++) {
                curr += (2 * j - ycoords[i].size()) * (ycoords[i][j].first - ycoords[i][j - 1].first);
                basesum[ycoords[i][j].second] = curr;
            }
        }
    }
    long long total_area = 0;
    for (int i = 0; i < n; i++) {
        total_area += (heightsum[i] * basesum[i]) % MOD;
        total_area %= MOD;
    }
    cout << total_area << endl;
    return 0;
}
