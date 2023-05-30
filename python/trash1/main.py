import time


def temp_cvt():
    while True:
        temp = input("请输入带符号的温度值：")
        if temp[-1] in ['C', 'c']:
            F = 1.8 * eval(temp[0:-1]) + 32
            print("转换后的温度是{0:.2f}C".format(F))
        elif temp[-1] in ['F', 'f']:
            C = (eval(temp[0:-1]) - 32) / 1.8
            print("转换后的温度是{0:.2f}F".format(C))
        else:
            print("输入格式错误")


def Load():
    print("----执行开始----")
    for i in range(11):
        a = '**' * i
        b = '..' * (10 - i)
        c = (i / 10) * 100
        print("{:3.0f}%[{}->{}]".format(c, a, b))
        time.sleep(0.1)
    print("----执行结束----")


if __name__ == '__main__':
    func = input("温度转换按1，文本进度条按2：")
    if func in ['1']:
        temp_cvt()
    elif func in ['2']:
        Load()
    else:
        print("无效输入")
