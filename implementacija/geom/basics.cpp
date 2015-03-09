#include "basics.h"

const double pi = M_PI;
const double eps = 1e-7;
const double inf = numeric_limits<double>::infinity();

enum ITYPE : char { OK, NO, EQ };
typedef complex<double> P;

double dot(const P& p, const P& q) {
    return p.real() * q.real() + p.imag() * q.imag();
}
double cross(const P& p, const P& q) {
    return p.real() * q.imag() - p.imag() * q.real();
}
double cross(const P& p, const P& q, const P& r) {
    return cross(q - p, r - q);  // > 0 levo, < 0 desno, = 0 naravnost
}
// true is p->q->r is a left turn, straight line is not, if so, change to -eps
bool left_turn(const P& p, const P& q, const P& r) {
    return cross(q-p, r-q) > eps;
}
P perp(const P& p) {  // get left perpendicular vector
    return P(-p.imag(), p.real());
}
int sign(double x) {
    if (x < -eps) return -1;
    if (x > eps) return 1;
    return 0;
}
double polar_angle(const P& p) {  // phi in [0, 2pi) or -1 for (0,0)
    if (p == P(0, 0)) return -1;
    double a = arg(p);
    if (a < 0) a += 2*pi;
    return a;
}
double area(const P& a, const P& b, const P& c) {  // signed
    return 0.5 * cross(a, b, c);
}
double area(const vector<P>& poly) {  // signed
    double A = 0;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        int j = (i+1) % n;
        A += cross(poly[i], poly[j]);
    }
    return A/2;
}
// struct L {  // premica, dana z enačbo ax + by = c ali z dvema točkama
//     double a, b, c;  // lahko tudi int
L::L() : a(0), b(0), c(0) {}
L::L(int A, int B, int C) {
    if (A < 0 || (A == 0 && B < 0)) a = -A, b = -B, c = -C;
    else a = A, b = B, c = C;
    int d = gcd(gcd(abs(a), abs(b)), abs(c));  // same sign as A, if nonzero, else B, else C
    if (d == 0) d = 1;                    // in case of 0 0 0 input
    a /= d;
    b /= d;
    c /= d;
}
L::L(double A, double B, double C) {
    if (A < 0 || (A == 0 && B < 0)) a = -A, b = -B, c = -C;
    else a = A, b = B, c = C;
}
L::L(const P& p, const P& q) : L(imag(q-p), real(p-q), cross(p, q)) {}
P L::normal() const { return {a, b}; }
double L::value(const P& p) const { return dot(normal(), p) - c; }
bool L::operator<(const L& line) const {
    if (a == line.a) {
        if (b == line.b) return c < line.c;
        return b < line.b;
    }
    return a < line.a;
}
bool L::operator==(const L& line) const {
    return cross(normal(), line.normal()) < eps && c*line.b == b*line.c;
}
//  };  // end struct L
ostream& operator<<(ostream& os, const L& line) {
    os << line.a << "x + " << line.b << "y == " << line.c; return os;
}

double dist_to_line(const P& p, const L& line) {
    return abs(line.value(p)) / abs(line.normal());
}
double dist_to_line(const P& t, const P& p1, const P& p2) {  // t do premice p1p2
    return abs(cross(p2-p1, t-p1)) / abs(p2-p1);
}
double dist_to_segment(const P& t, const P& p1, const P& p2) {  // t do daljice p1p2
    P s = p2 - p1;
    P w = t - p1;
    double c1 = dot(s, w);
    if (c1 <= 0) return abs(w);
    double c2 = norm(s);
    if (c2 <= c1) return abs(t-p2);
    return dist_to_line(t, p1, p2);
}
double great_circle_dist(const P& a, const P& b) {  // pairs of (latitude, longitude) in radians
    double R = 6371.0;                              // compute great circle distance
    double u[3] = { cos(a.real()) * sin(a.imag()), cos(a.real()) * cos(a.imag()), sin(a.real()) };
    double v[3] = { cos(b.real()) * sin(b.imag()), cos(b.real()) * cos(b.imag()), sin(b.real()) };
    double dot = u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
    bool flip = false;
    if (dot < 0.0) {
        flip = true;
        for (int i = 0; i < 3; i++) v[i] = -v[i];
    }
    double cr[3] = { u[1]*v[2] - u[2]*v[1], u[2]*v[0] - u[0]*v[2], u[0]*v[1] - u[1]*v[0] };
    double theta = asin(sqrt(cr[0]*cr[0] + cr[1]*cr[1] + cr[2]*cr[2]));
    double len = theta * R;
    if (flip) len = pi * R - len;
    return len;
}
bool point_in_rect(const P& t, const P& p1, const P& p2) {  // ali je t v pravokotniku p1p2
    return min(p1.real(), p2.real()) <= t.real() && t.real() <= max(p1.real(), p2.real()) &&
           min(p1.imag(), p2.imag()) <= t.imag() && t.imag() <= max(p1.imag(), p2.imag());
}
bool point_in_triangle(const P& t, const P& a, const P& b, const P& c) {  // orientation independant
    return abs(abs(area(a, b, t)) + abs(area(a, c, t)) + abs(area(b, c, t))  // edge inclusive
               - abs(area(a, b, c))) < eps;
}
pair<ITYPE, P> line_line_intersection(const L& p, const L& q) {
    double det = cross(p.normal(), q.normal());  // če imata odvisni normali (ali smerna vektorja)
    if (abs(det) < eps) {  // paralel
        if (abs(p.b*q.c - p.c*q.b) < eps && abs(p.a*q.c - p.c*q.a) < eps) {
            return {EQ, P()};  // razmerja koeficientov se ujemajo
        } else {
            return {NO, P()};
        }
    } else {
        return {OK, P(q.b*p.c - p.b*q.c, p.a*q.c - q.a*p.c) / det};
    }
}
pair<ITYPE, P> line_segment_intersection(const L& p, const P& u, const P& v) {
    double u_on = p.value(u);
    double v_on = p.value(v);
    if (abs(u_on) < eps && abs(v_on) < eps) return {EQ, u};
    if (abs(u_on) < eps) return {OK, u};
    if (abs(v_on) < eps) return {OK, v};
    if ((u_on > eps && v_on < -eps) || (u_on < -eps && v_on > eps)) {
        return line_line_intersection(p, L(u, v));
    }
    return {NO, P()};
}
pair<ITYPE, P> segment_segment_intersection(const P& p1, const P& p2, const P& q1, const P& q2) {
    int o1 = sign(cross(p1, p2, q1));  // daljico p1p1 sekamo z q1q2
    int o2 = sign(cross(p1, p2, q2));
    int o3 = sign(cross(q1, q2, p1));
    int o4 = sign(cross(q1, q2, p2));

    // za pravo presecisce morajo biti o1, o2, o3, o4 != 0
    // vemo da presečišče obstaja, tudi ce veljata samo prva dva pogoja
    if (o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0)
        return line_line_intersection(L(p1, p2), L(q1, q2));

    // EQ = se dotika samo z ogliscem ali sta vzporedni
    if (o1 == 0 && point_in_rect(q1, p1, p2)) return {EQ, q1};  // q1 lezi na p
    if (o2 == 0 && point_in_rect(q2, p1, p2)) return {EQ, q2};  // q2 lezi na p
    if (o3 == 0 && point_in_rect(p1, q1, q2)) return {EQ, p1};  // p1 lezi na q
    if (o4 == 0 && point_in_rect(p2, q1, q2)) return {EQ, p2};  // p2 lezi na q

    return {NO, P()};
}
ITYPE point_in_poly(const P& t, const vector<P>& poly) {
    int n = poly.size();
    int cnt = 0;
    double x2 = rand() % 100;
    double y2 = rand() % 100;
    P dalec(x2, y2);
    for (int i = 0; i < n; ++i) {
        int j = (i+1) % n;
        if (dist_to_segment(t, poly[i], poly[j]) < eps) return EQ;  // boundary
        ITYPE tip = segment_segment_intersection(poly[i], poly[j], t, dalec).first;
        if (tip != NO) cnt++;  // ne testiramo, ali smo zadeli oglisce, upamo da nismo
    }
    if (cnt % 2 == 0) return NO;
    else return OK;
}
pair<P, double> get_circle(const P& p, const P& q, const P& r) {  // circle through 3 points
    P v = q-p;
    P w = q-r;
    if (abs(cross(v, w)) < eps) return {P(), 0};
    P x = (p+q)/2.0, y = (q+r)/2.0;
    ITYPE tip;
    P intersection;
    tie(tip, intersection) = line_line_intersection(L(x, x+perp(v)), L(y, y+perp(w)));
    return {intersection, abs(intersection-p)};
}
// circle through 2 points with given r, to the left of pq
P get_circle(const P& p, const P& q, double r) {
    double d = norm(p-q);
    double h = r*r / d - 0.25;
    if (h < 0) return P(inf, inf);
    h = sqrt(h);
    return (p+q) / 2.0 + h * perp(q-p);
}
