def stableSelectionSort(list_a):
    # Assume last value is the max
    indexing_len = range(0, len(list_a)-1)
    # each time code iterates, first element will be default min
    for i in indexing_len:
      min = i
      # iterate through elements to right of indexing len and replace when something smaller is found
      for j in range(i+1, len(list_a)):
        if list_a[j] < list_a[min]:
            min = j
          
      # if item lesser than default, then switch
      key = list_a[min]
      while min > i:
        list_a[min] = list_a[min - 1]
        min -= 1
      list_a[i] = key  
      
    return list_a

print(stableSelectionSort([4,5,3,2,4,1]))