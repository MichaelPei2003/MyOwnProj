import os

def video2image(ffmpegPath, videoPath, frameNumber, imgPath, imgFormat):
    """
    视频转图片(请使用绝对路径)
    :param ffmpegPath: ffmpeg.exe路径
    :param videoPath: 视频路径，可以是mp4或avi等
    :param frameNumber: 每秒提取的图片数，即帧数
    :param imgPath: 输出图片存放的文件夹
    :param imgFormat: 输出图片格式，可以是jpg、png或jepg等
    :return: 多张图片
    """
    if not os.path.exists(imgPath):  # 如果图片文件夹不存在
        os.mkdir(imgPath)  # 创建图片文件夹路径
    command1 = "{} -i {} -r {} {}\%d .{} -y".format(ffmpegPath, videoPath, frameNumber, imgPath, imgFormat)
    os.system(command1)


if __name__ == '__main__':
    ffmpegPath = r""
    imgPath = r"C:\Users\xiahuadong\Desktop\xiahuadongCode\number_humen_web\number_humen_web\img2"  # 图片文件夹路径
    videoPath = r"C:\Users\xiahuadong\Desktop\xiahuadongCode\number_humen_web\number_humen_web\video\1.mp4"
    frameNumber = 30
    imgFormat = "png"
    video2image(ffmpegPath, videoPath, frameNumber, imgPath, imgFormat)
