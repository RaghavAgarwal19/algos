# Merge Sort

arr = []
n = int(input("Enter length of array "))
for k in range(0, n):
    x = int(input("Enter element "))
    arr.append(x)

mergesort(arr, 0, n-1)
print(arr)

def mergesort(arr, l, u):
    if l<u:
        mid = (int) (l+u)/2
        mergesort(arr, l, mid)
        mergesort(arr, mid + 1, u)
        merge(arr, l, mid, u)

def merge(arr, l, mid, u):
    b =  []
    i = l
    j = mid + 1
    k = 0
    while i <= mid and j <= u:
        if arr[i] <= arr[j]:
            b[k] = arr[i]
            k = k + 1
            i = i + 1
        else:
            b[k] = arr[j]
            k = k + 1
            j = j + 1
    while i <= mid:
        b[k] = arr[i]
        k = k + 1
        i = i + 1
    while j <= u:
        b[k] = arr[j]
        k = k + 1
        j = j + 1

    i = l
    for k in range(0, u-l+1):
        arr[i] = b[k]
        i = i + 1