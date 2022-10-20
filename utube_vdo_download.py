# from pytube import YouTube
# SAVE_PATH = "F:/Courses/"
# link="https://www.youtube.com/watch?v=M576WGiDBdQ"
# try:
# 	yt = YouTube(link)
# except:
# 	print("Connection Error") 
# mp4files = yt.streams.filter(progressive=True, file_extension='mp4')
# # yt.streams.set_filename('Blockchain_python')
# d_video = yt.(mp4files[-1].extension,mp4files[-1].resolution)
# try:
# 	d_video.download(SAVE_PATH)
# except:
# 	print("Some Error!")
# print('Task Completed!')




from pytube import YouTube
import os

def downloadYouTube(videourl, path):

    yt = YouTube(videourl)
    yt = yt.streams.filter(progressive=True, file_extension='mp4').order_by('resolution').desc().first()
    if not os.path.exists(path):
        os.makedirs(path)
    yt.download(path)

downloadYouTube('https://www.youtube.com/watch?v=V2zaeqFSSTE', 'E:/DjangoAPI')

#https://www.youtube.com/watch?v=g1ruWGga_AM&list=PLLz6Bi1mIXhG7SJHsZjI42aKOLkLysjeZ&index=2