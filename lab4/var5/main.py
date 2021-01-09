import math

max_4_der = 8505 / 8192
interval = [0, 15]
r = 4


def func(x):
    return 1 / math.sqrt(3 * x + 4)


def antder(x):
    return 2 / 3 * math.sqrt(3 * x + 4)


def res():
    return antder(interval[1]) - antder(interval[0])


def simpson(n):
    h = (interval[1] - interval[0]) / n
    simps_res = 0
    for i in range(0, n):
        a = interval[0] + i * h
        b = interval[0] + (i + 1) * h
        simps_res += (b - a) / 6 * (func(a) + 4 * func(0.5 * (a + b)) + func(b))
    return simps_res


def task(epsilon):
    # table 1
    h = pow(180 * epsilon / ((interval[1] - interval[0]) * max_4_der), 0.25)
    n = int((interval[1] - interval[0]) / h)
    err = abs(simpson(n) - res())
    print(" First - {:10.5}  {:10.5}  {:10.5}".format(epsilon, (interval[1] - interval[0]) / n, err))

    # table 2
    n = int(1 / math.sqrt(err))
    In = simpson(n)
    n *= 2
    I2n = simpson(n)
    while 1 / (pow(2, r) - 1) * abs(In - I2n) > err:
        In = simpson(n)
        n *= 2
        I2n = simpson(n)
    print(" Runge - {:10.5}  {:10.5}  {:10.5}".format(err, (interval[1] - interval[0]) / n, abs(I2n - res())))


if __name__ == '__main__':
    task(1e-2)
    task(1e-3)
    task(1e-4)
    task(1e-5)
