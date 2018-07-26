
# Insertion Sort

arr = []
n = int(input("Enter length of array "))
for k in range(0, n):
    x = int(input("Enter element "))
    arr.append(x)

for i in range(1, n):
    key = arr[i]
    j=i
    while arr[j-1]>key and j>0:
        arr[j] = arr[j-1]
        j -= 1
    arr[j] = key

print(arr)