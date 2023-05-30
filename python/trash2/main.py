import random


def add():
    x = int(input("请输入一个整数R:"))
    out = 0
    for i in range(x):
        out += i
    print("整数累加和为：%d" % out)


def game():
    target = random.randint(1, 1000)
    cnt = 0
    while "true":
        a = input("猜：")
        a = int(a)
        if a > target:
            cnt += 1
            print("猜大了")
        elif a < target:
            cnt += 1
            print("猜小了")
        elif a == target:
            print("猜了%d次后猜中"%cnt)
            break


if __name__ == '__main__':
    func = input("1 = 整数累加\n2 = 猜数字\n")
    if func in ['1']:
        add()
    elif func in ['2']:
        game()