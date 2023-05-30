import pandas as pd
import matplotlib.pyplot as plt

if __name__ == '__main__':
    data = pd.read_csv("D:/QQFile/1983220166/FileRecv/Coca_data.csv")
    data['日期'] = pd.to_datetime(data['日期'])
    data_month = data.groupby([pd.Grouper(freq='M', key='日期')]).agg({'收盘': 'mean'})
    data_week = data.groupby([pd.Grouper(freq='W', key='日期')]).agg({'收盘': 'mean'})
    clone_mean_month = data_month['收盘']
    clone_mean_week = data_week['收盘']
    x = clone_mean_month.index
    y = clone_mean_month.values
    a = clone_mean_week.index
    b = clone_mean_week.values
    plt.plot(x, y)
    plt.show()
    plt.plot(x, y, 'o')
    plt.show()
    plt.bar(x, y)
    plt.show()
    plt.plot(a, b)
    plt.show()
    plt.plot(a, b, 'o')
    plt.show()
    plt.bar(a, b)
    plt.show()
