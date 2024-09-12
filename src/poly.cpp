#include <bitset>
#include <cstdint>
#include <iostream>

#define IRREDUCIBLE 0b10011

using uint = unsigned int;

class Poly {
protected:
    uint a, b;

private:
    int degree(unsigned int poly)
    {
        int degree = -1;
        while (poly > 0) {
            degree++;
            poly >>= 1;
        }
        return degree;
    }

public:
    Poly(uint a, uint b)
        : a(a)
        , b(b)
    {
    }

    uint add_sub_poly()
    {
        return a ^ b;
    }

    uint multiply_poly()
    {
        uint result = 0;
        uint32_t mask = 0x000f;
        while (a != 0) {
            if (a & 1)
                result ^= b;
            a >>= 1;
            b <<= 1;
            if (b & (1 << 4)) {
                b ^= IRREDUCIBLE;
            }
        }
        return result;
    }

    uint inverse(uint a)
    {
        // TODO: implement extended euclid algorithm
        // a(x) = 1 mod m(x), where m(x) is irreducible polynomial
        uint irred = 8;
        return a ^ irred;
    }

    uint another_multi()
    {
        uint res = 0;
        for (uint i = 0; i < 4; i++) {
            if (a & (1 << i))
                res ^= b;
            b <<= 1;
            if (b & 0x10)
                b ^= IRREDUCIBLE;
        }
        return res & 0x000f;
    }

    uint poly_div()
    {
        uint res = a;

        while (degree(res) >= degree(b)) {
            uint pos = degree(res) - degree(b);
            std::cout << pos << " -- pos" << '\n';
            res ^= (b << pos);
        }
        return res;
    }
};
int main(int argc, char* argv[])
{
    Poly poly(0b1101, 0b0101);

    uint res = poly.poly_div();
    std::cout << res << '\n';
    return 0;
}

// Extended euclid for mod arithmetics

int x_gcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = x_gcd(b, (a % b), x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    // std::cout << "X: " << *x << " Y: " << *y << '\n';
    return y;
}
