#include <iostream>

int power(int a, int p)
{
    if (p == 0)
        return 1;

    int temp = power(a, p / 2);
    int res = temp * temp;
    if (p % 2 == 1)
        res *= a;
    return res;
}

// binary exponation
int non_rec_pow(int a, int b)
{
    int res = 1;
    if (b == 0)
        return 1;
    while (b > 0) {
        if (b % 2 == 0) {
            int tmp = a * a;
            res = tmp * tmp;
        } else {
            res *= a;
            a *= a;
        }
        b = b >> 1;
    }
    return res;
}


void expo(int n)
{
    int a = 3;
    int result = power(a, n);

    std::cout << "result: " << result << '\n';
}


int main(int argc, char* argv[])
{

    int n_n = non_rec_pow(3, 4);
    std::cout << "From non recursive: " << n_n << '\n';
    return 0;
}
