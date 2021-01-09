import math

a = -1
b = 10
M = 12 * math.exp(12)
r = 2


def f(x):
    return math.exp(x) * x


def F(x):
    return math.exp(x) * (x - 1)


def Leibnits():
    return F(b) - F(a)


def Trapezoidal(n):
    integral = f(a) / 2
    h = (b - a) / n
    for i in range(1, n):
        integral += f(a + h * i)
    integral += f(b) / 2
    return integral * h


def Table1(eps, flag):
    h = math.sqrt((12 * eps) / ((b - a) * M))
    n = int((b - a) / h)
    integral = Trapezoidal(n)
    if flag:
        print("1: {:10.5} {:15.10} {:15.10}".format(eps, (b - a) / n, abs(integral - Leibnits())))
    return abs(integral - Leibnits())


def Table2(eps):
    eps = Table1(eps, 0)
    n = int(1 / pow(eps, 1 / r))
    In = Trapezoidal(n)
    n *= 2
    I2n = Trapezoidal(n)
    Rn = 1 / 3 * abs(In - I2n)
    while Rn > eps:
        In = Trapezoidal(n)
        n *= 2
        I2n = Trapezoidal(n)
        Rn = 1 / 3 * abs(In - I2n)
    print("2: {:10.5} {:15.10} {:15.10}\n".format(eps, (b - a) / n, abs(I2n - Leibnits())))


if __name__ == '__main__':
    print("        error            step      real error")
    epses = [1e-2, 1e-3, 1e-4, 1e-5]
    for eps in epses:
        Table1(eps, 1)
        Table2(eps)