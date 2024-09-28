import numpy as np

def cosine_dist_python(A, B):
    A_dot_B = np.dot(A, B)
    A_mag = np.sqrt(np.sum(np.square(A)))
    B_mag = np.sqrt(np.sum(np.square(B)))
    dist = 1.0 - (A_dot_B / (A_mag * B_mag))
    return dist

# Example values for A and B
A = np.array([5, 3, 4,4,0])
B = np.array([3, 1, 2,3,3])

# Calculate cosine distance
distance = cosine_dist_python(A, B)
print("Cosine Distance:", distance)
