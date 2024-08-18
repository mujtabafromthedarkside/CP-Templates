/*
implementation by
https://docs.google.com/presentation/d/1IeQ9yoCCEbCM_FSwUSF8Xk-_Vddod_Mex0vx0gTt2kk/edit#slide=id.g295b3dec2a5_0_149
Daniel Sleator course SegTree slides
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

#include "debug.cpp"
using namespace std;

template <class Datatype>
class SegTree {
   public:
    int n;
    int ns;
    // TODO: This value will vary depending on merge operation
    Datatype defaultValue = 0;
    vector<Datatype> a;
    vector<bool> tag;

    static int findDepth(int n) { return ((int)log2(n - 0.001) + 1); }

    SegTree(vector<Datatype> &v) {
        n = v.size();
        ns = (1 << (findDepth(n) + 1)) - 1;
        a.resize(ns, defaultValue);
        tag.resize(ns, false);
        for (int i = 0; i < v.size(); i++) {
            update(i, v[i]);
        }
    }

    void update(int i, Datatype x) { update(i, i, x); }
    void update(int l, int r, Datatype x, int id = -1, int L = -1, int R = -1) {
        if (id == -1) id = 0;
        if (L == -1) L = 0;
        if (R == -1) R = n - 1;

        // if search space lies outside required range
        if (R < l || L > r) return;

        if (L == R) {
            a[id] = x;
        }  // if search space lies within required range
        else if (L >= l && R <= r) {
            tag[id] = true;
            // TODO: this depends on merge operation
            a[id] = x * (R - L + 1);
        } else {
            push(id);
            int mid = (L + R) / 2;
            // a[id] = merge operation performed over the range [L, R]
            update(l, r, x, id * 2 + 1, L, mid);
            update(l, r, x, id * 2 + 2, mid + 1, R);

            a[id] = merge(a[id * 2 + 1], a[id * 2 + 2]);
        }
    }

    Datatype query(int l, int r, int id = -1, int L = -1, int R = -1) {
        if (id == -1) id = 0;
        if (L == -1) L = 0;
        if (R == -1) R = n - 1;

        // the whole search space is outside required range
        if (R < l || L > r) return defaultValue;

        // the whole search space is within required range
        if (L >= l && R <= r) {
            return a[id];
        }

        push(id);
        int mid = (L + R) / 2;
        int left = query(l, r, id * 2 + 1, L, mid);
        int right = query(l, r, id * 2 + 2, mid + 1, R);
        return merge(left, right);
    }

    // TODO: aggregate function
    Datatype merge(Datatype x, Datatype y) { return x + y; }

    void push(int id) {
        if (!tag[id]) return;
        int lastLevelStart = (1 << findDepth(n)) - 1;
        if (id >= lastLevelStart) return;

        // TODO: this value depends on merge function
        Datatype pushValue = a[id] / 2;

        tag[id * 2 + 1] = true;
        a[id * 2 + 1] = pushValue;

        tag[id * 2 + 2] = true;
        a[id * 2 + 2] = pushValue;

        tag[id] = false;
    }

    void printTree() {
        for (int i = 0, lvl = 0; i < (int)a.size(); i = i * 2 + 1, lvl++) {
            cout << setw(2) << lvl << ": ";
            for (int j = i; j < min(i * 2 + 1, ns); j++) {
                cout << a[j] << " ";
            }
            cout << endl;
        }
    }

    void printTreeF(int spaceNumber = 2, int linesEnd = 1) {
        /*
                   9
               3       6
             3   0   5   1
            1 2 0 0 2 3 1 0

            - if you see above:
              - id[0] = 9 takes space 7*2+1 = 15 spaces
              - id[1] = id[2] take 7 spaces
              - id[3] to id[6] take 3 spaces
              - id[7] to end take 1 space
            - total size of tree = 2*n
            As you go up from the bottom:
            - spaceNumber = spaceNumber * 2 + 1
            - spaceBefore += spaceNumber

            - smallest power of 2 >= 2*n is the # levels
            - as you increase 1 level, you get spaceID = spaceID * 2 + 1
            - Note that, spaceID = spaceBefore*2 + 1

            - on the top:
                spaceBefore = 1 << log2(n-0.001)
                spaceBetween = spaceBefore * 2 + 1;
            - as we go down:
                spaceBefore /= 2;
                spaceBetween /= 2;
        */
        auto printSpaces = [](int n) {
            for (int i = 0; i < n; i++) cout << " ";
        };

        int lastLevelCount = 1 << findDepth(n);
        int spaceBefore = lastLevelCount - 1;
        int spaceBetween = 2 * spaceBefore + 1;  // space
        for (int i = 0; i < (int)a.size(); i = i * 2 + 1) {
            printSpaces(spaceBefore * spaceNumber);
            for (int j = i; j < min(i * 2 + 1, ns); j++) {
                push(j);
                cout << setw(spaceNumber) << a[j];
                printSpaces(spaceBetween * spaceNumber);
            }
            spaceBefore /= 2;
            spaceBetween /= 2;
            for (int j = 0; j < linesEnd; j++) cout << endl;
        }
    }
};

int main() {
    vector<float> a = {1.1, 2, 3, 4, 5, 6, 7};
    SegTree<float> s(a);

    s.printTreeF();
    cout << endl;

    s.update(4, -10);
    s.printTreeF();
    int l = 3, r = 5;
    cout << s.query(3, 5);
    cout << endl;

    s.update(2, 5, -10);
    s.printTreeF();
    cout << s.query(3, 5);
}