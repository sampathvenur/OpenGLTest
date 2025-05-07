import cv2
import numpy as np

cv2.namedWindow("Shape")
img = np.zeros((550, 550, 3), np.uint8)

for t, v in [("W",200), ("H",100), ("R",0), ("G",255), ("B",0)]:
    cv2.createTrackbar(t, "Shape", v, 255 if t in "RGB" else 500, lambda x:None)

while True:
    i = img.copy()
    w = cv2.getTrackbarPos("W", "Shape")
    h = cv2.getTrackbarPos("H", "Shape")
    r = cv2.getTrackbarPos("R", "Shape")
    g = cv2.getTrackbarPos("G", "Shape")
    b = cv2.getTrackbarPos("B", "Shape")
    cv2.rectangle(i, (10, 10), (10 + w, 10 + h), (b, g, r), -1)
    cv2.imshow("Shape", i)
    if cv2.waitKey(1) & 0xFF == ord('q'): break
cv2.destroyAllWindows()
