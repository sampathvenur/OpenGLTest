import cv2

img = cv2.imread('cat.jpg')
img = cv2.resize(img, (500, 500))

avg = cv2.blur(img, (5, 5))
gauss = cv2.GaussianBlur(img, (5, 5), 0)
median = cv2.medianBlur(img, 5)
bilateral = cv2.bilateralFilter(img, 9, 75, 75)

cv2.imshow('Original', img)
cv2.imshow('Average Blur', avg)
cv2.imshow('Gaussian Blur', gauss)
cv2.imshow('Median Blur', median)
cv2.imshow('Bilateral Filter', bilateral)

cv2.waitKey(0)
cv2.destroyAllWindows()