#include <iostream>

using namespace std;

// 扩展欧几里得算法，求 ax + by = gcd(a, b) 的一组解
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long gcd = exgcd(b, a % b, x, y);
    long long temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}

// 中国剩余定理
long long CRT(long long a1, long long m1, long long a2, long long m2, long long a3, long long m3) {
    long long M1 = m2 * m3;
    long long M2 = m1 * m3;
    long long M3 = m1 * m2;
    long long x1, y1, x2, y2, x3, y3;
    exgcd(M1, m1, x1, y1);
    exgcd(M2, m2, x2, y2);
    exgcd(M3, m3, x3, y3);
    long long x = (a1 * M1 * x1 + a2 * M2 * x2 + a3 * M3 * x3) % (m1 * m2 * m3);
    if (x > 0) {
        return x;
    }
    return x + m1 * m2 * m3;
}

int main() {
    long long a1, m1, a2, m2, a3, m3;
    cin >> m1 >> a1 >> m2 >> a2 >> m3 >> a3;

    // 使用中国剩余定理求解
    long long x = CRT(a1, m1, a2, m2, a3, m3);

    cout << x << endl;

    return 0;
}
