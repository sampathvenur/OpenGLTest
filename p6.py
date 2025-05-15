import cv2

img = cv2.imread('cat.jpg')
img = cv2.resize(img, (500, 500))
h, w = img.shape[:2]
a, b = h//2, w//2

parts = [
    ('Up-Left', img[:a, :b]),
    ('Up-Right', img[:a, b:]),
    ('Down-Left', img[a:, :b]),
    ('Down-Right', img[a:, b:])
]

cv2.imshow('Original', img)

for name, part in parts:
    cv2.imshow(name, part)

cv2.waitKey(0)
cv2.destroyAllWindows()