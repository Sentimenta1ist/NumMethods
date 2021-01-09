import copy


class Calculation:
    def __init__(self, x1, x2, x3, x4):
        self.x1 = x1
        self.x2 = x2
        self.x3 = x3
        self.x4 = x4

    def jord_gaus(self, matr):
        a = copy.copy(matr)
        for k in range(0, len(a)):
            for i in range(0, len(a)):
                element_row = a[i][k]
                if k != i:
                    for j in range(0, len(a[k])):
                        a[i][j] -= element_row * a[k][j] / a[k][k]
                new_a_k = []
                for elem in a[k]:
                    new_a_k.append(elem / a[k][k])
                a[k] = new_a_k
        self.x1 = a[0][4]
        self.x2 = a[1][4]
        self.x3 = a[2][4]
        self.x4 = a[3][4]

    def seidel(self, matr, eps):
        a = [
            [0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0]
        ]
        for i in range(0, len(matr)):
            for j in range(0, len(matr)):
                if j == i:
                    a[i][j] = matr[i][4] / matr[i][i]
                else:
                    a[i][j] = matr[i][j] / matr[i][i]
        q = 0
        for i in range(0, len(matr)):
            q_tmp = 0
            for j in range(0, len(matr)):
                if j == i:
                    continue
                q_tmp += abs(a[i][j])
            if q_tmp > q:
                q = q_tmp
        prev_x1 = 1
        while abs(self.x1 - prev_x1) > (1 - q) / q * eps:
            prev_x1 = self.x1
            self.x1 = a[0][0] - a[0][1] * self.x2 - a[0][2] * self.x3 - a[0][3] * self.x4
            self.x2 = a[1][1] - a[1][0] * self.x1 - a[1][2] * self.x3 - a[1][3] * self.x4
            self.x3 = a[2][2] - a[2][0] * self.x1 - a[2][1] * self.x2 - a[2][3] * self.x4
            self.x4 = a[3][3] - a[3][0] * self.x1 - a[3][1] * self.x2 - a[3][2] * self.x3


if __name__ == '__main__':
    task_jordan = Calculation(0, 0, 0, 0)
    matr_default = [
        [13, 14, 17, 14, 146],
        [9, 26, 7, 9, 135],
        [8, 4, 24, 11, 119],
        [15, 11, 5, 16, 109]
    ]
    print("DEFAULT MATRIX:")
    for k in matr_default:
        print(k)
    task_jordan.jord_gaus(matr_default)
    print(
        "Results of jordan-gauss-method: x1 - {:.10};  x2 - {:.10};  x3 - {:.10};  x4 - {:.10};".format(task_jordan.x1,
                                                                                                        task_jordan.x2,
                                                                                                        task_jordan.x3,
                                                                                                        task_jordan.x4))

    task_seidel = Calculation(0, 0, 0, 0)
    matr_iter = [
        [-411, 1, -33, -340, -1669],
        [9, 26, 7, 9, 135],
        [8, 4, 24, 11, 119],
        [127, -2, 1, 136, 514]
    ]
    print("\n\nREWORKED MATRIX:")
    print("|new(1): ((2) * 44 + (3) * 56)) - (1) * 100) + (4) * 3 |= {}".format(matr_iter[0]))
    print("|                                                 (2)  |= {}".format(matr_iter[1]))
    print("|                                                 (3)  |= {}".format(matr_iter[2]))
    print("|     ((1) * 100 - (2) * 181 - (3) * 225) + new(1) * 4 |= {}".format(matr_iter[3]))
    task_seidel.seidel(matr_iter, 1e-10)
    print(
        "Results of seidel-method: x1 - {:.10};  x2 - {:.10};  x3 - {:.10};  x4 - {:.10};".format(task_seidel.x1,
                                                                                                  task_seidel.x2,
                                                                                                  task_seidel.x3,
                                                                                                  task_seidel.x4))