
#include <cmath>
#include <iostream>

using namespace std;
class rectangular;
class polar {
   public:
    float r;
    float a;

    polar(float x = 0, float y = 0) {
        r = x;
        a = y;
    }
    polar(const rectangular& rect);
};

class rectangular {
   public:
    float x, y;

    rectangular() {
        x = 0;
        y = 0;
    }
    rectangular(float x, float y) {
        this->x = x;
        this->y = y;
    }

    rectangular(polar p) {
        x = p.r * cos(p.a);
        y = p.r * sin(p.a);
    }

    rectangular operator+(rectangular);
};

rectangular rectangular::operator+(rectangular r) { return rectangular(x + r.x, y + r.y); }
polar::polar(const rectangular& rect) {
    this->r = sqrt(rect.x * rect.x + rect.y * rect.y);
    this->a = atan2(rect.y, rect.x);
}
int main() {
    polar p1(10, 20), p2(30, 40);

    rectangular r1, r2, r3;
    r1 = p1;
    r2 = p2;

    r3 = r2 + r1;

    polar p3(r3);  // works (rectangular → polar via constructor)

    cout << "polar r = " << p3.r << " polar a = " << p3.a << endl;
}
