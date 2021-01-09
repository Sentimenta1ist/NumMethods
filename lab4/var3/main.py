import math

inter = {'a': 1, 'b': 15}


def primitive_f(x):
    return (x * x * x * x - 1) / (2 * x * x) - 2 * math.log(x)


leib_res = primitive_f(inter['b']) - primitive_f(inter['a'])


def default_f(x):
    return (x * x - 1) * (x * x - 1) / (x * x * x)


def simpson_meth(quon):
    dx = (inter['b'] - inter['a']) / quon
    result_integr = 0
    for step in range(0, quon):
        x1 = inter['a'] + step * dx
        x2 = inter['a'] + (step + 1) * dx
        result_integr += (x2 - x1) / 6.0 * \
                         (default_f(x1) + 4.0 * default_f(0.5 * (x1 + x2)) + default_f(x2))
    return result_integr


def print_tables(ep):
    h = pow(180 * ep / ((inter['b'] - inter['a']) * 312), 0.25)
    quon1 = int((inter['b'] - inter['a']) / h)
    err_default = abs(simpson_meth(quon1) - leib_res)
    quon = int(1 / math.sqrt(err_default))
    I_n = simpson_meth(quon)
    quon *= 2
    I_2n = simpson_meth(quon)
    while 1 / (pow(2, 4) - 1) * abs(I_n - I_2n) > err_default:
        I_n = simpson_meth(quon)
        quon *= 2
        I_2n = simpson_meth(quon)
    print("  Analytics :  {:15.11}  {:15.11}  {:15.11}".format(ep,
                                                               (inter['b'] - inter['a']) / quon1,
                                                               err_default))

    print(" Runge meth : {:15.11}  {:15.11}  {:15.11}".format(err_default,
                                                              (inter['b'] - inter['a']) / quon,
                                                              abs(I_2n - leib_res)))


if __name__ == '__main__':
    eps_lst = [1e-2, 1e-3, 1e-4, 1e-5]
    print("                  wanted err        gotten h        gotten error")
    print("                 -----------------------------------------------")
    for i in eps_lst:
        print_tables(i)
