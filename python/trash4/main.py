import numpy as np

if __name__ == '__main__':
    # x = np.array([np.arange(1, 11)] * 10)
    # y = np.dot(x, x.T)
    # print("矩阵乘积为")
    # print(y)
    # a, _ = np.linalg.eig(y)
    # b = np.max(a)
    # print("最大特征值为")
    # print(b)
    x = np.array([np.arange(1, 101)]).T
    x = x * x.T
    y = np.diag(x)[88 - 1]
    print(y)
