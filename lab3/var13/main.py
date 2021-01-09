matrix = [
    [30, 12, 7, 9, 82],
    [15, 41, 16, 9, 76],
    [0, 3, 20, 16, 100],
    [0, 2, 9, 27, 144]
]


def Gauss_Jordan_method():
    tmp_matrix = matrix
    for i in range(0, len(tmp_matrix)):
        diag = tmp_matrix[i][i]
        for k in range(0, i):
            one_row = tmp_matrix[k][i]
            for j in range(0, len(tmp_matrix[i])):
                tmp_matrix[k][j] -= one_row * tmp_matrix[i][j] / diag
        for k in range(i + 1, len(tmp_matrix)):
            one_row = tmp_matrix[k][i]
            for j in range(0, len(tmp_matrix[i])):
                tmp_matrix[k][j] -= one_row * tmp_matrix[i][j] / diag
        for j in range(0, len(tmp_matrix[i])):
            tmp_matrix[i][j] = tmp_matrix[i][j] / diag

    return [tmp_matrix[0][4], tmp_matrix[1][4], tmp_matrix[2][4], tmp_matrix[3][4]]


def Direct_iter_method(eps):
    ans = [0, 0, 0, 0]
    tmp_matrix = []
    q = 0
    qm = 0
    for i in range(0, len(matrix)):
        tmp = []
        q = 0
        for j in range(0, len(matrix)):
            if i == j:
                diag = matrix[i][len(matrix)] / matrix[i][i]
                tmp.append(diag)
                ans[i] = diag
            else:
                another = matrix[i][j] / matrix[i][i]
                q += abs(another)
                tmp.append(another)
        tmp_matrix.append(tmp)
        if q > qm:
            qm = q
    q = qm
    previous = 0
    while abs(ans[0] - previous) > (1 - q) / q * eps:
        tmp = []
        previous = ans[0]
        for i in range(0, len(tmp_matrix)):
            sum_anothers = 0
            for j in range(0, len(tmp_matrix[i])):
                if i != j:
                    sum_anothers += ans[j] * tmp_matrix[i][j]
            tmp.append(tmp_matrix[i][i] - sum_anothers)
        ans = tmp
    return ans


if __name__ == '__main__':
    print("NEW MATRIX:")
    print("(4)+(1)-(3): ", matrix[0])
    print("        (2): ", matrix[1])
    print("        (3): ", matrix[2])
    print("(4)+(3)-(1): ", matrix[3])
    print("Gauss Jordan answers:     ", Gauss_Jordan_method())
    print("Direct Iteration answers: ", Direct_iter_method(1e-8))
