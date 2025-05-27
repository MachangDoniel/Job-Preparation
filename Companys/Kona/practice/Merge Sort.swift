import Foundation

func merge(_ arr: inout [Int],_ left: Int,_ mid: Int,_ right: Int){
    let n1 = mid - left + 1
    let n2 = right - mid
    var L = [Int](repeating: 0, count : n1)
    var R = [Int](repeating: 0, count : n2)
    for i in 0..<n1{
        L[i] = arr[left+i]
    }
    for i in 0..<n2{
        R[i] = arr[mid+1+i];
    }
    var i=0,j=0,k=left
    while i < n1 && j < n2{
        if(L[i] < R[j]){
            arr[k] = L[i]
            i += 1
        } 
        else {
            arr[k] = R[j]
            j += 1
        }
        k += 1
    }
    while i < n1{
        arr[k] = L[i]
        i += 1
        k += 1
    }
    while j < n2{
        arr[k] = R[j]
        j += 1
        k += 1
    }
}

func mergeSort(_ arr: inout [Int],_ left: Int,_ right: Int){
    if(left < right) {
        let mid = (left + right) / 2
        mergeSort(&arr,left,mid)
        mergeSort(&arr,mid+1,right)
        merge(&arr,left,mid,right)
    }
}

var arr = [23,34,12,56,23,12]
print("Unsorted: " ,arr)
mergeSort(&arr,0,arr.count-1)
print("Sorted: " ,arr)