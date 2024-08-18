#ifndef LOCAL
#define NDEBUG
#endif

/*#pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wsign-compare"
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define nl cout << "\n"
#define ve vector
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define ll long long
#define pq priority_queue
#define gi greater<int>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define tcs      \
    int tttt;    \
    cin >> tttt; \
    for (int TTTT = 1; TTTT <= tttt; TTTT++)
#define sp << " " <<
#define rep(l, r, i) for (int i = l; i < r; ++i)
#define per(l, r, i) for (int i = r; i >= l; --i)
#define repp(l, r, i) for (int i = l; i <= r; ++i)
#define all(a) begin(a), end(a)
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define MOD 1000000007
#define int long long

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
int sz(T a) {
    return a.size();
}
int norm(int n) { return (n % MOD + MOD) % MOD; }

#ifdef LOCAL
#include "templates/debug.cpp"
#else
#define dbb(...) 11
#define db(n) 22
#define DB(n) 33
#endif

void solve() {}

/*

*/

int32_t main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w+", stdout);
#endif

    // fastio;
    // tcs{
    //  cout<<"Case #"<<TTTT<<": ";
    solve();
    nl;
    //}
    return 0;
}

/*

*/