#include "11933.h"

const int Vector::operator[](int index) const {
    return v[index];
}

int Vector::operator*(const Vector& a) {
    int ans = 0;
    for(int i=0; i<v_size; ++i) {
        ans += v[i]*a[i];
    }
    return ans;
}