def bubble(list_a):
  index_len = len(list_a) - 1
  sorted = False

  while not sorted:
    sorted = True
    for i in range (0, index_len):
      #if item on the left is larger than right, then swap
      if list_a[i] > list_a[i+1]:
        sorted = False
        list_a[i], list_a[i+1] = list_a[i+1], list_a[i]
  return list_a

print(bubble([4,5,3,2,4,1]))