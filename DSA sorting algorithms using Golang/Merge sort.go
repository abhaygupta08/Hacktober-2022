  
const NADA int = -1  
  
func DeepCopy(vals []int) []int {  
   tmp := make([]int, len(vals))  
   copy(tmp, vals)  
   return tmp  
}  
  
func MergeSort(items []int) {  
  
   if len(items) > 1 {  
      mid := len(items) / 2  
      left := DeepCopy(items[0:mid])  
      right := DeepCopy(items[mid:])  
  
      MergeSort(left)  
      MergeSort(right)  
  
      l := 0  
      r := 0  
  
      for i := 0; i < len(items); i++ {  
  
         lval := NADA  
         rval := NADA  
  
         if l < len(left) {  
            lval = left[l]  
         }  
  
         if r < len(right) {  
            rval = right[r]  
         }  
  
         if (lval != NADA && rval != NADA && lval < rval) || rval == NADA {  
            items[i] = lval  
            l += 1  
         } else if (lval != NADA && rval != NADA && lval >= rval) || lval == NADA {  
            items[i] = rval  
            r += 1  
         }  
  
      }  
   }  
  
}  



