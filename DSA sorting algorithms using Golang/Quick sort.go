  
   if len(items) > 1 {  
	pivot\_index := len(items) / 2  
	var smaller\_items = []int{}  
	var larger\_items = []int{}  

	for i := range items {  
	   val := items[i]  
	   if i != pivot\_index {  
		  if val < items[pivot\_index] {  
			 smaller\_items = append(smaller\_items, val)  
		  } else {  
			 larger\_items = append(larger\_items, val)  
		  }  
	   }  
	}  

	QuickSort(smaller\_items)  
	QuickSort(larger\_items)  

	var merged []int = append(append(append([]int{}, smaller\_items...), []int{items[pivot\_index]}...), larger\_items...)  
	//merged := MergeLists(smaller\_items, items[pivot\_index], larger\_items)  

	for j := 0; j < len(items); j++ {  
	   items[j] = merged[j]  
	}  

 }  

 


