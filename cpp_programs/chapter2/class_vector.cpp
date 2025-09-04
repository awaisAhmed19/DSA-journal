#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class class_v {
   public:
    vector<float> create_v(size_t size) {
        srand(time(0));
        vector<float> v(size);
        for (int i = 0; i < size; i++) {
            v[i] = static_cast<float>(rand()) / RAND_MAX;
        }
        return v;
    }

    void scalar(float multi, vector<float>& v, void (*func)(float));

    void print(vector<float> v) {
        cout << "(";
        for (auto val : v) {
            cout << val << ", ";
        }

        cout << ")";
    }
};

void class_v ::scalar(float multi, vector<float>& v, void (*func)(float)) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] * multi;
        func(v[i]);
    }
}

int main() {
    class_v v;

    vector<float> val = v.create_v(20);

    v.scalar(10, val, [](float val) { cout << "values " << val << endl; });
    v.print(val);
}
