import cv2 
import numpy as np 

# Callback function for trackbars 
def on_change(value): 
    img = cv2.rectangle(image, (0,0), (550,550), (0,0,0), -1) 
    cv2.imshow("Shape", img) 
    pass 

# Create a window 
cv2.namedWindow("Shape Properties") 
image = np.zeros((550,550,3), np.uint8) 
# Initial values 
initial_width = 200 
initial_height = 100 
initial_color = (0, 255, 0)  # Green 
choice=1 
# Create trackbars 
cv2.createTrackbar("Width", "Shape Properties", initial_width, 500, on_change) 
cv2.createTrackbar("Height", "Shape Properties", initial_height, 500, on_change) 
cv2.createTrackbar("Red", "Shape Properties", initial_color[0], 255, on_change) 
cv2.createTrackbar("Green", "Shape Properties", initial_color[1], 255, on_change) 
cv2.createTrackbar("Blue", "Shape Properties", initial_color[2], 255, on_change) 

while True: 
    # Get current trackbar values 
    width = cv2.getTrackbarPos("Width", "Shape Properties") 
    height = cv2.getTrackbarPos("Height", "Shape Properties") 
    red = cv2.getTrackbarPos("Red", "Shape Properties") 
    green = cv2.getTrackbarPos("Green", "Shape Properties") 
    blue = cv2.getTrackbarPos("Blue", "Shape Properties") 

    # Draw the rectangle with dynamically adjusted properties 
    shape = (width, height) 
    color = (blue, green, red)  # OpenCV uses BGR format 

    img = cv2.rectangle(image, (10,10), shape, color, -1) 
    # Display the image                                                                                     
    cv2.imshow("Shape", img) 
    # Check for key press 
    key = cv2.waitKey(1) & 0xFF 
    if key == ord("q"): 
        break 
cv2.destroyAllWindows() 