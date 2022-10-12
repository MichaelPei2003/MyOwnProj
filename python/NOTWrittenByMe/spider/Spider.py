import os
import re
import time

import bs4
import requests
import xlwt

import Snapshot
from Snapshot import *


class Spider:
    reg = r'<img.*\b(src|data-original)\b="(?P<target>[^.].*?)".*>'
    findImgSrc = re.compile(reg, re.S)
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.5060.114 Safari/537.36 Edg/103.0.1264.49',
        'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
    }

    def __init__(self, url, metadata_filepath) -> None:
        self.url = url
        self.dirspath = "./img/src/" + \
            self.url.split("//")[-1].replace(".", "_")
        self.metadata_filepath = metadata_filepath
        self.total_count = 0

    def run(self) -> None:
        self.save_metaData()
        print("end!")

    def save_metaData(self) -> None:
        book = xlwt.Workbook(encoding="utf-8")
        sheet = book.add_sheet(
            sheetname=self.url.split("//")[-1].replace(".", "_"),
            cell_overwrite_ok=True,
        )
        # 写入标题行
        cols = ('编号', 'URL', '本地存储', '爬取耗时/秒', '存入时间', '快照概述')
        for k in range(len(cols)):
            sheet.write(0, k, cols[k])
        # 写入非标题行
        datalist = self.get_datalist()
        for i in range(len(datalist)):
            for j in range(len(datalist[i])):
                # i+1是因为需要跳过标题行
                sheet.write(i + 1, j, datalist[i][j])
                if j == 1:
                    sheet.write(i+1, j,
                                xlwt.Formula('HYPERLINK("{}"; "{}")'.format(
                                    datalist[i][j], datalist[i][j].split('/')[-1]))
                                )
        book.save(self.metadata_filepath)

    def __snapshot(self) -> str:
        driver = Snapshot(
            self.url, 'D:/msedgedriver.exe')
        driver.checkdirs()
        return driver.shot()

    def get_datalist(self) -> list:
        shot_info = self.__snapshot()
        datalist = []
        for item in self.ask_url().find_all('img', recursive=True):
            data = []
            raw = re.fullmatch(pattern=self.findImgSrc, string=str(item))
            if raw:
                self.total_count += 1
                data.append(self.total_count)
                data.append(self.__improve_url(url=raw.group('target')))
                start_time = time.time()
                data.append(self.__save_img(data[1]))
                data.append(time.time()-start_time)
                data.append(time.asctime(time.localtime(time.time())))
                data.append(shot_info)
                datalist.append(data)
        return datalist

    def __save_img(self, url) -> str:
        if not os.path.exists(self.dirspath):
            os.makedirs(self.dirspath)
        try:
            response = requests.get(url=url, headers=self.headers, timeout=5)
            filename = url.split('/')[-1].split('?')[0]
            with open(self.dirspath + '/' + filename, 'wb') as f:
                f.write(response.content)
            # 保存本地路径
            return self.dirspath + '/' + filename
        except Exception:
            print(url+': 可能出现假死')

    def ask_url(self) -> bs4.BeautifulSoup:
        try:
            page = requests.get(self.url, self.headers)
            page.encoding = 'gb2312'
            soup = bs4.BeautifulSoup(page.text, "html.parser")
        except requests.exceptions as e:
            print(e)
        return soup

    def __improve_url(self, url) -> str:
        if re.match('//', url):
            return 'http:' + url
        else:
            return url
