def insertionSort(list_a):
  indexing_len = range(1, len(list_a))
  #sort values in indexing length created
  for i in indexing_len:
    valSort = list_a[i]
  # check if item on the left is greater than value to sort, and if i is greater than 0 
    while list_a[i-1] > valSort and i > 0:
      # if it meets the condition, then switch
      list_a[i], list_a[i-1] = list_a[i-1], list_a[i]
      # incrementally going down the list to sort it 
      i = i - 1

  return list_a

print(insertionSort([4,5,3,2,4,1]))