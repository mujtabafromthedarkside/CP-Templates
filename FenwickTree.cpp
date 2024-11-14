/*
    Implementation taken from the CP Handbook
    The tree follows 1-based indexing
*/

#include <vector>
using namespace std;

struct FenwickTree {
    vector<int> tree;
    int n;

    FenwickTree(int n, vector<int> &v) {
        tree.resize(n + 1);
        this->n = n;
        for (int i = 1; i <= n; i++)
            add(i, v[i]);
    }

    FenwickTree(int n) {
        tree.resize(n + 1);
    }

    int sum(int k) {
        if (k == 0) return 0;
        int s = 0;
        while (k >= 1) {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }

    // 1-based indexing
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int k, int x) {
        while (k <= n) {
            tree[k] += x;
            k += k & -k;
        }
    }
};