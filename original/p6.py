import cv2 
img = cv2.imread('images.jpeg') 

# cv2.imread() -> takes an image as an input 
h, w, channels = img.shape 

half1 = w//2 
half2 = h//2 

up_left = img[:half2, :half1] 
up_right = img[:half2, half1:]   
down_left = img[half2:, :half1] 
down_right = img[half2:, half1:] 

cv2.imshow('Original image', img) 
cv2.imshow('Up-Left part', up_left) 
cv2.imshow('Up-Right part', up_right) 
cv2.imshow('Down-Left part', down_left) 
cv2.imshow('Down-Right part', down_right) 

# saving all the images 
# cv2.imwrite() function will save the image into your pc 
cv2.imwrite('up_left.jpg', up_left) 
cv2.imwrite('up_right.jpg', up_right) 
cv2.imwrite('down_left.jpg', down_left) 
cv2.imwrite('down_right.jpg', down_right) 

cv2.waitKey(0) 
cv2.destroyAllWindows()