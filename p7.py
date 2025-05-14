import cv2
import numpy as np

img = cv2.imread('cat.jpg')
img = cv2.resize(img, (500, 500))
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

edge = cv2.Canny(gray, 100, 200)
kernel = np.ones((5, 5), np.float32) / 25
texture = cv2.filter2D(gray, -1, kernel)

cv2.imshow('Original', img)
cv2.imshow('Edge', edge)
cv2.imshow('Texture', cv2.convertScaleAbs(texture))

cv2.waitKey(0)
cv2.destroyAllWindows()