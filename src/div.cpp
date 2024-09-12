#include <cmath>
#include <iostream>

int bit_div(long a, long b)
{
    int ans = 0, n = 31;

    while (n >= 0) {
        if ((b << n) <= a) {
            a -= (b << n);
            ans += 1 << n;
        }
        n--;
    }

    std::cout << "Rem: " << a << '\n';
    return ans;
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 9; i++) {
        i += i;
        std::cout << i << '\n';
    }
    std::cout << "---> division: " << bit_div(676762, 67687) << '\n';
    // long tmp = 0;
    // std::cout << (31 << tmp) << '\n';
    return 0;
}
