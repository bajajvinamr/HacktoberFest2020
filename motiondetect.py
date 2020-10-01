import cv2 as cv
import numpy as np

first_frame = None

video = cv.VideoCapture(0)

while True:
    check,frame = video.read()
    gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    gray = cv.GaussianBlur(gray,(21,21),0)
    
    if first_frame is None:
        first_frame = gray
        continue
    
    delta_frame = cv.absdiff(first_frame,gray)
    
    thresh_delta = cv.threshold(delta_frame,30,255,cv.THRESH_BINARY)[1]
    
    thresh_delta = cv.dilate(thresh_delta, None, iterations=0)
    
    contours, hierarchy = cv.findContours(thresh_delta, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
    for contour in contours:
        if cv.contourArea(contour)<1000:
         continue
        (x,y,w,h) = cv.boundingRect(contour)
        cv.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),3)
        
    cv.imshow('frame',frame)
    cv.imshow('Capturing',gray)
    cv.imshow('delta',delta_frame)
    cv.imshow('thresh',thresh_delta)
    print(cv.contourArea)
    key = cv.waitKey(1)

    if key == ord('q'):
              break
video.release()
cv.destroyAllWindows

              
