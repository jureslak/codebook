#include "rectangle_union_area.h"

typedef complex<int> P;

struct vert {  // vertical sweep line element
    int x, s, e;
    bool start;
    vert(int a, int b, int c, bool d) : x(a), s(b), e(c), start(d) {}
    bool operator<(const vert& o) const {
        return x < o.x;
    }
};

vector<int> points;  // y-coordinates of rect sides (can be double)

struct Node {  // segment tree
    int s, e, m, c, a;  // start, end, middle, count, area
    Node *left, *right;
    Node(int s_, int e_) : s(s_), e(e_), m((s+e)/2), c(0), a(0), left(nullptr), right(nullptr) {
        if (e-s == 1) return;
        left = new Node(s, m);
        right = new Node(m, e);
    }
    int add(int f, int t) {  // returns area
        if (f <= s && e <= t) {
            c++;
            return a = points[e] - points[s];
        }
        if (f < m) left->add(f, t);
        if (t > m) right->add(f, t);
        if (c == 0) a = left->a + right->a;  // če nimam lastnega intervala, izračunaj
        return a;
    }
    int remove(int f, int t) {  // returns area
        if (f <= s && e <= t) {
            c--;
            if (c == 0) {  // če nima lastnega intervala
                if (left == nullptr) a = 0;  // če je list je area 0
                else a = left->a + right->a;  // če ne je vsota otrok
            }
            return a;
        }
        if (f < m) left->remove(f, t);
        if (t > m) right->remove(f, t);
        if (c == 0) a = left->a + right->a;
        return a;
    }
};

int rectangle_union_area(const vector<pair<P, P>>& rects) {
    int n = rects.size();

    vector<vert> verts; verts.reserve(2*n);
    points.resize(2*n);  // vse točke čez katere napenjamo intervale (stranice)

    P levo_spodaj, desno_zgoraj;  // pravokotniki so dani tako, ce v nalogi niso, zamenjaj x1 <-> x2
    for (int i = 0; i < n; ++i) {
        tie(levo_spodaj, desno_zgoraj) = rects[i];
        int a = levo_spodaj.real();   //         +----------+ (c, d)
        int c = desno_zgoraj.real();  //         |          |
        int b = levo_spodaj.imag();   //         |          |
        int d = desno_zgoraj.imag();  //  (a, b) +----------+
        verts.push_back(vert(a, b, d, true));
        verts.push_back(vert(c, b, d, false));
        points[2*i] = b;
        points[2*i+1] = d;
    }

    sort(verts.begin(), verts.end());
    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end())-points.begin());  // zbrišemo enake

    Node * sl = new Node(0, points.size());  // sweepline segment tree

    int area = 0, height = 0;  // area = total area. height = trenutno pokrita višina
    int px = -(1 << 30);  // value smaller than smallest x coordinate
    for (int i = 0; i < 2*n; ++i) {
        area += (verts[i].x-px)*height;  // trenutno pometena area

        int s = lower_bound(points.begin(), points.end(), verts[i].s) - points.begin();
        int e = lower_bound(points.begin(), points.end(), verts[i].e) - points.begin();
        if (verts[i].start) height = sl->add(s, e);  // segment tree sprejme indexe, ne koordinat
        else height = sl->remove(s, e);
        px = verts[i].x;
    }

    return area;
}
