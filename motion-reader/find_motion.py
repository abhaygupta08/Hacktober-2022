import cv2
import numpy as np

def findMotion():
  previous_frame = None

  vid = cv2.VideoCapture(0)
  play = True
  color=(255, 0, 0)
  while True:

    # 1. Load image; convert to RGB
    ret, frame = vid.read()
    frame  = cv2.flip(frame,1)

    img_brg = np.array(frame)
    s = img_brg.shape
    
    # blank *= 200
    img_rgb = cv2.cvtColor(src=img_brg, code=cv2.COLOR_BGR2RGB)

    prepared_frame = cv2.cvtColor(img_rgb, cv2.COLOR_BGR2GRAY)

    if (previous_frame is None):
      blank = np.ones(shape=s, dtype=np.uint8)
      previous_frame = prepared_frame
      continue

    diff_frame = cv2.absdiff(src1=previous_frame, src2=prepared_frame)
    previous_frame = prepared_frame

    kernel = np.ones((1, 1))
    diff_frame = cv2.dilate(diff_frame, kernel, 1)

    thresh_frame = cv2.threshold(src=diff_frame, thresh=100, maxval=255, type=cv2.THRESH_BINARY)[1]
    contours, hierarchy = cv2.findContours(thresh_frame, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    if play:
      cv2.drawContours(image=blank, contours=contours, contourIdx=-1, color=color, thickness=1, lineType=cv2.LINE_AA)
    
    cv2.imshow('Motion detector', blank)
    x = cv2.waitKey(3)

    # Some simple keyboard controls to play/pause, change color, save and quit
    if x == ord('1'):
      color=(0, 0, 255)
    elif x == ord('2'):
      color=(0, 127, 255)
    elif x == ord('3'):
      color=(0, 255, 255)
    elif x == ord('4'):
      color=(0, 255, 0)
    elif x == ord('5'):
      color=(255, 255, 0)
    elif x == ord('6'):
      color=(255, 0, 0)
    elif x == ord('7'):
      color=(255, 0, 127)
    elif x == ord('8'):
      color=(255, 255, 255)
    elif x == ord('s'):
      cv2.imwrite('output.jpg',blank)
    elif x == ord('r'):
      cv2.imwrite('output.jpg',blank)
    elif x == ord('c'):
      blank = np.ones(shape=s, dtype=np.uint8)
    elif x == ord('p'):
      play = False
    elif x == ord('o'):
      play = True
    elif x == ord('q'):
        break

findMotion()