arr1 = list(map(int,input().split())) #enter the array elements in row seperated by space
arr1.reverse()
print(*arr1,sep=' ') #print in reverse order
rem_dup = list(set(arr1))
print(*rem_dup,sep=' ') #remove duplicate elemets
rem_dup.sort(reverse=True)
print(rem_dup[1]) #second max element from array
arr2 = list(map(int,input().split())) #enter the second array
flag = True
for i in arr1:
    for j in arr2:
        if i == j:
            flag = False

if flag:
    print('disjoint')
else:
    print('not disjoint')
