import math


class Task:
    def __init__(self, a, b, M, r):
        self.a = a
        self.b = b
        self.M = M
        self.r = r

    def def_fun(self, x):
        return math.sinh(x)

    def Fun(self, x):
        return math.cosh(x)

    def result_integral(self):
        return self.Fun(self.b) - self.Fun(self.a)

    def trapez_meth(self, n):
        res_inegral = self.def_fun(self.a) / 2
        h = (self.b - self.a) / n
        for st in range(1, n):
            res_inegral += self.def_fun(self.a + st * h)
        res_inegral += self.def_fun(self.b) / 2
        return res_inegral * h

    def task1(self, eps):
        h = math.sqrt((12 * eps) / ((self.b - self.a) * self.M))
        n = int((self.b - self.a) / h)
        res_trap = self.trapez_meth(n)
        error_of_task1 = abs(res_trap - self.result_integral())
        print("  Default h:  {:15.10} {:15.10} {:15.10}".format(eps,
                                                                (self.b - self.a) / n,
                                                                error_of_task1))
        return error_of_task1

    def tasks(self, eps):
        err = self.task1(eps)
        n = int(1 / pow(err, 1 / self.r))
        In = self.trapez_meth(n)
        n *= 2
        I2n = self.trapez_meth(n)
        while 1 / 3 * abs(In - I2n) > err:
            In = self.trapez_meth(n)
            n *= 2
            I2n = self.trapez_meth(n)
        print("Runge check:  {:15.10} {:15.10} {:15.10}".format(err,
                                                                (self.b - self.a) / n,
                                                                abs(I2n - self.result_integral())))


if __name__ == '__main__':
    task = Task(2, 9, math.sinh(9), 2)
    task.tasks(1e-2)
    task.tasks(1e-3)
    task.tasks(1e-4)
    task.tasks(1e-5)
