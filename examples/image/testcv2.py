import numpy as np
import cv2  
cap = cv2.VideoCapture(0)
while(cap.isOpened()):   # true when camera is open
    while True:
        ret, img_array = cap.read()
        cv2.imshow('img', img_array)
        if cv2.waitKey(1) & 0xff == ord('q'):
            break
    cap.release()
    cv2.destroyAllWindows()
else:
    print("Camera is disconnected")
