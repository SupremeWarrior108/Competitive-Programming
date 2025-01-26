#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define f first
#define s second
using namespace std;
struct L {
  int m, b, i;
  L(int m, int b, int i) : m(m), b(b), i(i) {};
};

pii eq(L line, pii point) {
    int x = line.b * point.s + line.m * point.f;
    int y = point.s;
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    return {x, y};
}

pii intersect(L line1, L line2) {
    int x = line1.b - line2.b, y = line2.m - line1.m;
    if (y < 0) {
        x *= -1;
        y *= -1;
    }
    return {x, y};
}

bool cmpGre (pii x, pii y) {
    return x.f * y.s >= x.s * y.f;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, p;
    cin >> n >> p;
    bool pos[n+1];
    vector<L> lines;
    for (int i = 1; i <= n; i++) {
        pos[i] = 0;
        int x, y; cin >> x >> y;
        lines.emplace_back(x-y, y, i);
    }
    sort(lines.begin(), lines.end(), [&](const L& x, const L& y) {
        if (x.m < y.m) return 1;
        if (x.m == y.m && x.b < y.b) return 1;
        return 0;
    });
    stack<pair<L, pii>> st;
    for(L line: lines) {
        while(!st.empty()) {
            L tmp = st.top().f;
            pii point = st.top().s;
            pii point1 = eq(tmp, point), point2 = eq(line, point);
            if (point1 >= point2) break;
            st.pop();
        }
        pii point = {0, 1};
        if (!st.empty()) {
            L tmp = st.top().f;
            if (tmp.m == line.m && tmp.b == line.b) point = st.top().s;
            else if (tmp.m == line.m) continue;
            else {
                point = intersect(tmp, line);
            }
        }
        if (point.f > point.s || point.f < 0) continue;
        st.push({line, point});
    }
    int s = 0;
    while(!st.empty()) {
        s++;
        pos[st.top().f.i] = 1;
        st.pop();
    }
    cout << s << endl;
    for(int i = 1; i <= n; i++)
        if(pos[i]) 
            cout << i << " ";
    cout << endl;
    return 0;
}