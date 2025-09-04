
#include <ctime>
#include <iostream>
using namespace std;

class DM {
   public:
    float meters, c_meters;
    friend void add(DM&, DB&);
};

class DB {
   public:
    float inches, feet;
    friend void add(DM&, DB&);
};

int main() {
    class_v v;

    vector<float> val = v.create_v(20);

    v.scalar(10, val, [](float val) { cout << "values " << val << endl; });
    v.print(val);
}
