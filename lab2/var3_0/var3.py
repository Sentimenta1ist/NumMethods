import math


def function(x):
    return 0.2 * pow(x, 3) - pow(x, 4) - math.cos(x) + 1.5


def derivative_function(x):
    return math.sin(x) - 4 * (x - 0.15) * x * x


def second_derivative_function(x):
    return math.cos(x) - 12 * (x - 0.1) * x


def approximation_method(eps, a, b):
    result = []
    x0 = (a + b) / 2
    m1 = derivative_function(a)
    M1 = derivative_function(b)
    if abs(derivative_function(a)) > abs(derivative_function(b)):
        M1 = derivative_function(a)
        m1 = derivative_function(b)
    lambd = 1 / M1
    q = 1 - m1 / M1
    xn = x0 - lambd * function(x0)
    counter = 1
    error = abs(q * abs(xn - x0) / (1 - q))
    while error > eps:
        x0 = xn;
        xn = x0 - lambd * function(x0)
        error = abs(function(xn) / m1)
        counter += 1
    result.append(xn)
    result.append(counter)
    result.append(error)
    return result


def chord_method(eps, a, b):
    result = []
    c = a
    xn = b
    m1 = min(abs(derivative_function(a)), abs(derivative_function(b)))
    if function(a) * second_derivative_function(a) < 0:
        c = b
        xn = a
    counter = 1
    error = abs(function(xn) / m1)
    while error > eps:
        xn -= (function(xn) / (function(xn) - function(c))) * (xn - c)
        error = abs(function(xn) / m1)
        counter += 1
    result.append(xn)
    result.append(counter)
    result.append(error)
    return result


if __name__ == '__main__':
    list_of_eps = [1e-2, 1e-5, 1e-8, 1e-11]

    print("Approximate method:")
    print(" eps | result of meth |     error   |")
    for eps in list_of_eps:
        method = approximation_method(eps, -1, -0.5)
        print("{:5}|  {:.10f} | {:.10f}|".format(eps, method[0], method[2]))
        method = approximation_method(eps, 1, 1.5)
        print("{:5}|  {:13.10f} | {:.10f}|".format(eps, method[0], method[2]))

    print("\nChord method:")
    print(" eps | result of meth |     error   |")
    for eps in list_of_eps:
        method = chord_method(eps, -1, -0.5)
        print("{:5}|  {:.10f} | {:.10f}|".format(eps, method[0], method[2]))
        method = chord_method(eps, 1, 1.5)
        print("{:5}|  {:13.10f} | {:.10f}|".format(eps, method[0], method[2]))

    print("\nComparison:")
    print(" eps | count of approx | count of chord  |")
    for eps in list_of_eps:
        method1 = approximation_method(eps, 1, 1.5)
        method2 = chord_method(eps, 1, 1.5)
        print("{:5}|  {:14} | {:16}|".format(eps, method1[1], method2[1]))

