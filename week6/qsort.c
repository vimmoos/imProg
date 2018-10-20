void merge(int arr[],int freq[], int l, int m, int r){ 
    int i, j, index; 
    int lenA = m - l + 1; 
    int lenB =  r - m; 
    int L[lenA], R[lenB]; 
    for (i = 0; i < lenA; i++){
        L[i] = arr[l + i]; 
    }
    for (j = 0; j < lenB; j++){
        R[j] = arr[m + 1+ j]; 
    } 
    i = j = 0; 
    index = l; 
    while (i < lenA && j < lenB) { 
        if (L[i] <= R[j]){ 
            arr[index] = L[i];
            freq[index] = L[i]; 
            i++; 
        }else{ 
            arr[index] = R[j]; 
            freq[index] = R[j]; 
            j++; 
        } 
        index++; 
    } 
    while (i < lenA){ 
        arr[index] = L[i]; 
        freq[index] = L[i]; 
        i++; 
        index++; 
    } 
    while (j < lenB){ 
        arr[index] = R[j]; 
        freq[index] = R[j]; 
        j++; 
        index++; 
    } 
} 

void mergeSort(int arr[],int freq[], int l, int r){ 
    if (l < r){ 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr,freq, l, m); 
        mergeSort(arr,freq, m+1, r); 
  
        merge(arr,freq, l, m, r); 
    } 
} 
  
int main() {   
    mergeSort(arr, 0, arr_size - 1); 
    return 0; 
} 