def quickSort(seq):
  length = len(seq)
  if length <= 1:
    return seq
  else:    
    pivot = seq.pop()

  itemGreater = []
  itemLower = []

  for item in seq:
    if item > pivot:
      itemGreater.append(item)
    else:
      itemLower.append(item)

  return quickSort(itemLower) + [pivot] + quickSort(itemGreater)

print(quickSort([4,5,3,2,4,1]))
