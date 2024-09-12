def bit_div(a: int, b: int) -> int:
    ans = 0
    neg = a < 0 or b < 0
    a = abs(a)
    b = abs(b)

    for i in range(31, -1, -1):
        if b << i <= a:
            a -= b << i
            ans += 1 << i

    return ans if neg == 0 else -1 * ans


if __name__ == "__main__":
    bt: int = bit_div(676762, 67687)
    print(bt)
