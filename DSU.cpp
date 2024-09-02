/*
https://cp-algorithms.com/data_structures/disjoint_set_union.html
- not using make_set(int)
*/
#include <vector>
#include <numeric>
using namespace std;
class DSU {
   public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);

        size.resize(n + 1, 1);
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void merge(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};