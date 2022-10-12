import os
import time

from selenium import webdriver


class Snapshot:
    def __init__(self, url, executable_path, args=["--headless", "--disable-gpu"]) -> None:
        self.url = url
        self.executable_path = executable_path
        self.dirspath = "./img/snapshot/" + \
            self.url.split("//")[-1].replace(".", "_")
        self.options = {
            "browserName": "MicrosoftEdge",
            "version": "",
            "platform": "WINDOWS",
            "ms:edgeOptions": {
                "extensions": [],
                "args": args,
            }
        }

    def checkdirs(self) -> None:
        if not os.path.exists(self.dirspath):
            os.makedirs(self.dirspath)

    def shot(self) -> str:
        driver = webdriver.Edge(
            executable_path=self.executable_path, capabilities=self.options)
        driver.get(self.url)
        # 用js获取页面的宽高
        scroll_width = driver.execute_script(
            "return document.body.parentNode.scrollWidth")
        scroll_height = driver.execute_script(
            "return document.body.parentNode.scrollHeight")
        # 将浏览器的宽高设置成刚刚获取的宽高
        driver.set_window_size(width=scroll_width, height=scroll_height)
        time.sleep(0.5)
        current_time = self.time_format()
        driver.get_screenshot_as_file(
            self.dirspath + '/' + current_time + ".png")
        time.sleep(0.5)
        return "{}: Process {} get pic !".format(current_time, os.getpid())

    # 时间格式进行格式化
    def time_format(self) -> str:
        current_time = time.strftime(
            '%Y%m%d%H%M%S', time.localtime(time.time()))
        return current_time
