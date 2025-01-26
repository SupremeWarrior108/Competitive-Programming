#include <bits/stdc++.h>
using namespace std;

// Macros
#define add_back     push_back
#define add_front    push_front
#define first_elem   first
#define second_elem  second
#define entire(v)    v.begin(), v.end()
#define reverse_all(v) v.rbegin(), v.rend()
#define upper(v)     upper_bound(v)
#define lower(v)     lower_bound(v)

// #define iterate(i, x, n)   for(int i = x; i < n; ++i)
// #define reverse_iterate(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read_array(arr, n) for(long long idx = 0; idx < n; ++idx) cin >> arr[idx];
#define print_array(arr, n) for(long long idx = 0; idx < n; ++idx){ cout << arr[idx] << " ";} cout << "\n";
#define newline "\n"
#define space " "

// Typedefs
typedef long long int64;
typedef long double decimal;
typedef long long int long_int;
typedef pair<long long, long long> pair_ll;
typedef pair<long_int, long_int> pair_lli;
typedef pair<int, int> pair_int;
typedef vector<long_int> vector_li;
using int_vector = vector<int>;

// Constants
const long long max_size = 1e6 + 5;
const long long modulus = 1e9 + 7;

// Solve

void solve() {
    int t;  cin >> t;
    while(t--) {
        cout << "? aa" << endl;
        cout.flush();
        int digits[10], base;
        cin >> base;
        base--;
        cout << "? zzzzzzzzzz" << endl;
        cout.flush();
        int hash_value, hash_value1;
        long long total = 0, multiplier = 1;
        cin >> hash_value;
        hash_value1 = hash_value;
        hash_value++;
        for(int idx = 0; idx < 10; idx++) {
            total += 26 * multiplier;
            multiplier *= base;
            digits[idx] = 26 - (hash_value % base);
            hash_value /= base;
        }
        string result;
        multiplier = 1;
        long long char_count = 0;
        for (int idx = 0; idx < 10; idx++) {
            if (digits[idx] < 1) {
                digits[idx] = 26;
                digits[idx + 1]--;
            }
            char_count += multiplier * digits[idx];
            multiplier *= base;
            result += 'a' + (digits[idx] - 1);
        }
        cout << "? " << result << endl;
        int final_answer;
        cin >> final_answer;
        cout << "! " << base << ' ' << final_answer + total - char_count - hash_value1 << endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    solve();
    return 0;
}
