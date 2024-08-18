#include <string>
#include <vector>
#include <iostream>
using namespace std;

void split(string &str, string del, vector<string> &s) {
    unsigned int l = 0, i = 0;
    for (; i < str.size(); i++)
        for (auto &j : del)
            if (str[i] == j) {
                if (l < i) s.push_back(string(str.begin() + l, str.begin() + i));
                l = i + 1;
                break;
            }
    if (l < i) s.push_back(string(str.begin() + l, str.begin() + i));
}
template <class K, class V>
ostream &operator<<(ostream &s, const pair<K, V> &p) {
    s << '<' << p.first << ", " << p.second << '>';
    return s;
}
template <class T, class = typename T::value_type,
          class = typename enable_if<!is_same<T, string>::value>::type>
ostream &operator<<(ostream &s, const T &v) {
    s << '[';
    for (auto &x : v) {
        s << x << ", ";
    }
    if (v.size()) s << "\b\b";
    s << ']';
    return s;
}
void debug_out(vector<string> args, int idx, int LINE_NUM) {
    cerr << "\e[91m" << endl << "\e[39m" << flush;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << "\e[91m" << ", " << "\e[39m" << flush;
    else
        cerr << "\e[91m" << "Line(" << LINE_NUM << ") " << "\e[39m" << flush;
    cerr << "\e[91m" << args[idx] << " = " << H << "\e[39m" << flush;
    debug_out(args, idx + 1, LINE_NUM, T...);
}
template <typename... All>
void debug_out(string s, int idx, int LINE_NUM, All... VA_ARGS) {
    vector<string> args;
    split(s, ", ", args);
    debug_out(args, idx, LINE_NUM, VA_ARGS...);
}

#define dbb(...) debug_out(#__VA_ARGS__, 0, __LINE__, __VA_ARGS__)
#define db(n) cout << "here " << n << "\n";
#define DB(n) cout << "$|" << n << "|$\n";
