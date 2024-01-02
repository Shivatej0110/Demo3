import numpy as np 
arr=np.array([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27])
arr1=arr.reshape(3,3,3)
print(arr1)
arr2=arr1[-1:-4:-1,-1:-3:-1,-2:-4:-1]
print(arr2)

