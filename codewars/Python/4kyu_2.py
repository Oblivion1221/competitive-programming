// Wrong

import math, fractions
from decimal import Decimal
def expand(x, digit):
    print(x, digit)
    dlen, n = 0, 0
    while True:
        nume = 0
        n += 1
        for i in range(n):
            deno = Decimal(math.factorial(n-1))
            nume += deno / Decimal(math.factorial(i)) * Decimal(pow(x, i))
        temp = fractions.gcd(nume, deno)
        if temp != 1:
            nume /= temp
            deno /= temp
        dlen = len(str((int)(nume)))
        print(dlen, nume, deno, n)
        if dlen >= digit:
            return [(int)(nume), (int)(deno)]

# import math
# from fractions import Fraction
# from decimal import Decimal
# def expand(x, digit):
#     print(x, digit)
#     dlen, n = 0, 0
#     while True:
#         res = 0
#         n += 1
#         for i in range(n):
#             res += Decimal(str(pow(x, i))) / Decimal(str(math.factorial(i)))
#         nume = Fraction(res).limit_denominator().numerator
#         deno = Fraction(res).limit_denominator().denominator
#         dlen = len(str(nume))
#         if dlen >= digit:
#             return [nume, deno]

print(expand(1, 2))