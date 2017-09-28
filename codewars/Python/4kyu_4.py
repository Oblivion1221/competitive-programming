import functools

def automorphic(p):
    t = 1
    n = 5
    k = 1
    res = [1]
    for i in range(1, p + 1):
        size = 2 ** i
        n = (3 * n ** 2 - 2 * n ** 3) % (10 ** size)
        for j in range(k, size + 1):
            m5 = n % (10 ** j)
            m6 = 10 ** j + 1 - m5
            [a, b, c] = sorted([t, m5, m6])
            # print("n = " + str(n) + "\n[t, m5, m6] = " + str([t,m5,m6]) + " ")
            # print("[a, b, c] = " + str([a, b, c]))
            res.append(b)
            res.append(c)
            t = c
            # print("res = " + str(res))
    return sorted(list(set(res)))

@functools.lru_cache(maxsize=1)
def green_t():
    res = automorphic(13)
    # print(res)
    return res

def green(arg):
    return green_t()[arg - 1]

# f = open('out.txt', 'w')
# for i in range(1, 501):
#     f.write(str(green(i)) + "\n")
# f.close()
#
# 
# print(green(1))
# print(green(2))         
# print(green(3))         
# print(green(12))         
# print(green(13))         
# print(green(100))         
# print(green(110))
# print(green(1322))         
# print(green(2544))                 
# print(green(5000))
# 
# 
# 
# Trivial:
# 
# def green(n):
#     i = 0
#     while n > 0:
#         if (i * i) % (10 ** len(str(i))) == i and i:
#             n -= 1
#             print("n = " + str(n) + " i = " + str(i))
#         i += 1
#     return i - 1
# 
# print(green(100))
