import copy


def div_one_row(number, row):
    new_row = []
    for i in row:
        new_row.append(i / number)
    return new_row


def jordan_gauss(slar1):
    slar = copy.deepcopy(slar1)
    for i in range(0, len(slar)):
        for j in range(0, len(slar)):
            element = slar[j][i]
            if j != i:
                for k in range(0, len(slar[i])):
                    slar[j][k] -= element * slar[i][k] / slar[i][i]
            slar[i] = div_one_row(slar[i][i], slar[i])
    res = []
    for i in range(0, len(slar)):
        res.append(slar[i][4])
    return res


def seidel(eps, slar):
    tmp_matrix = []
    res = [0, 0, 0, 0]
    q = 0
    qmax = 0
    for i in range(0, len(slar)):
        q = 0
        row = []
        for j in range(0, len(slar)):
            if i == j:
                element = slar[i][len(slar)] / slar[i][i]
                row.append(element)
                res[i] = element
            else:
                element = slar[i][j] / slar[i][i]
                row.append(-element)
                q += abs(element)
        tmp_matrix.append(row)
        if q > qmax:
            qmax = q
    prev = 0
    while abs(prev - res[3]) > (1 - qmax) / qmax * eps:
        prev = res[3]
        for i in range(0, len(slar)):
            sum_of_row = 0
            for j in range(0, len(slar)):
                if i == j:
                    continue
                sum_of_row += res[j] * tmp_matrix[i][j]
            res[i] = tmp_matrix[i][i] + sum_of_row
    return res


if __name__ == '__main__':
    slar = [
        [25, 2, 12, 9, 164],
        [-4, 42, 3, -2, 128],
        [20, 19, 50, 10, 437],
        [6, 0, -11, 32, 74]
    ]
    print("Variant 4")
    print("REWORKED SLAR:")

    print("(1) * 10 + (4) * 2 - (3) - (2) - (1) * 2 : ", slar[0])
    print("                                (2) - (4): ", slar[1])
    print("                                      (3): ", slar[2])
    print("                      (2) + (4) - (1) * 8: ", slar[3])

    print("\nJORDAN GAUSS METHOD :")
    print(jordan_gauss(slar))

    print("\n SEIDEL METHOD (input epsilon) :")
    eps = input()
    print(seidel(float(eps), slar))
