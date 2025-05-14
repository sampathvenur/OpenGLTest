import cv2
import numpy as np

image = cv2.imread('cat.jpg')
image = cv2.resize(image, (800, 600))

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(gray, 100, 200)

contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(image, contours, -1, (0, 255, 0), 2)

cv2.imshow('Original Image with Contours', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
