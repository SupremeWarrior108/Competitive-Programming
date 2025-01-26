// https://codeforces.com/contest/2025/problem/E

#include <bits/stdc++.h>
using namespace std;

namespace atcoder {
    template <int m>
    struct static_modint {
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }

        static_modint() : _v(0) {}
        template <class T>
        static_modint(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }

        unsigned int val() const { return _v; }
        
        static_modint operator+(const static_modint& rhs) const {
            return static_modint(_v + rhs._v >= umod() ? _v + rhs._v - umod() : _v + rhs._v);
        }

        static_modint operator-(const static_modint& rhs) const {
            return static_modint(_v >= rhs._v ? _v - rhs._v : _v + umod() - rhs._v);
        }

        static_modint operator*(const static_modint& rhs) const {
            return static_modint((unsigned long long)_v * rhs._v % umod());
        }

        static_modint& operator+=(const static_modint& rhs) {
            return *this = *this + rhs;
        }

        static_modint& operator-=(const static_modint& rhs) {
            return *this = *this - rhs;
        }

        static_modint& operator*=(const static_modint& rhs) {
            return *this = *this * rhs;
        }
    };

    using mint = static_modint<998244353>;
    using vm = vector<mint>;

    vm distribute(const long long M, const long long mn) {
        const long long L = mn + M + 2;
        vm dp(L);
        dp[mn] = 1;
        for (long long k = M; k >= 1; k--) {
            vm ndp(L);
            for (long long pd = -mn; pd <= M; pd++) {
                const long long idx = pd + mn;
                if (idx + 1 < L)
                    ndp[idx + 1] += dp[idx];
                if (idx > 0)
                    ndp[idx - 1] += dp[idx];
            }
            dp = ndp;
        }
        return dp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long T = 1;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        auto dp = atcoder::distribute(m, 0);
        atcoder::vm rest(m + 1);
        for (long long df = 0; df <= m; df++) {
            const auto pr = atcoder::distribute(m, df);
            rest[df] = pr[0];
        }
        for (long long jt = 1; jt < n; jt++) {
            atcoder::vm ndp(m + 1);
            for (long long pk = 0; pk <= m; pk++)
                for (long long k = 0; k <= pk; k++)
                    ndp[pk - k] += dp[pk] * rest[k];
            dp = ndp;
        }
        cout << dp[0].val() << endl;
    }
    return 0;
}
