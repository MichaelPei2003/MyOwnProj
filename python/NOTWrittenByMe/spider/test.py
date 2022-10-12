import Spider
from Spider import *

if __name__ == '__main__':
    zhongqing_top = Spider('https://www.youth.cn', './img/metadata.xls')
    zhongqing_top.run()
