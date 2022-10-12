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

    def run(self) -> str:
        driver = webdriver.Edge(
            executable_path=self.executable_path, capabilities=self.options)
        driver.get(self.url)


if __name__ == '__main__':
    driver = Snapshot("http://news.youth.cn/",
                      "D:/Anaconda/webdriver/edgedriver_win64/msedgedriver.exe", [])
    driver.run()
