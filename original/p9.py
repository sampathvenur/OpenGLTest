import cv2 
import numpy as np 

# Read the image 
image = cv2.imread('images.jpeg') 

# Convert the image to grayscale 
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) 

# Apply Canny edge detection 
edges = cv2.Canny(gray, 100, 200) 

# Find contours in the edged image 
contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, 
cv2.CHAIN_APPROX_SIMPLE) 

# Create a mask with the same dimensions as the image 
mask = np.zeros_like(gray) 

# Draw contours on the mask 
cv2.drawContours(mask, contours, -1, (255), thickness=cv2.FILLED) 

# Apply the mask to the original image 
segmented_image = cv2.bitwise_and(image, image, mask=mask) 

# Display the original image and the segmented image 
cv2.imshow('Original Image', image) 
cv2.imshow('Segmented Image', segmented_image) 
cv2.waitKey(0) 
cv2.destroyAllWindows()