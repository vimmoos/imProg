#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// void merge(int lenA, int a[], int lenB, int b[], int arr[]) {
//     int idx, l, r;
//     idx = l = r = 0;
//     while ((l != lenA) && (r != lenB)) {
//         if (a[l] <= b[r]) {
//             arr[idx] = a[l];
//             l++;
//         }else {
//             arr[idx] = b[r];
//             r++;
//         }
//         idx++;
//     }
//     /* process trailing elements: either l==lenA or r==lenB */
//     while (l != lenA) {
//         arr[idx] = a[l];
//         idx++;
//         l++;
//     }
//     while (r != lenB) {
//         arr[idx] = b[r];
//         idx++;
//         r++;
//     }
// }



void merge(int i , int m ,int l, int *arr,int *tmp) {
    int idx=0,j = m;

    while((i != m) && (j != l)){
        if(arr[i] <= arr[j]){
            tmp[idx] = arr[i];
            i++; 
        }else{
            tmp[idx] = arr[j];
            j++;
        }
        idx++;
    }
    while(i != m ){
        tmp[idx] = arr[i];  
        idx++;
        i++;
    }
    while(j != l ){
        tmp[idx] = arr[j];  
        idx++;
        j++;
    }
    
}

void recWhamsort(int p, int q, int a[], int tmp[]){
    /* pre p <= q; this function sorts a[p,..,q) */
    int r = p+1;
    while (r < q && a[r-1] <= a[r]) {
        r++;
    }
    /* a[p,r) is maximal ascending prefix of a[] */
    while (r < q) { /* note: 2*(r-p)+p==2*r-p */
        int s = (q < 2*r - p ? q : 2*r - p);
        recWhamsort(r, s, a, tmp);
        merge(p, r, s, a, tmp);
        r = s;
    }
}

void whamsort(int len, int a[]){
    int *tmp = malloc(len*sizeof(int));
    recWhamsort(0, len, a, tmp);
    free(tmp);
}



int main(int argc, char *argv[]) {
    int *numbers, n, cnt=0;
    int sz=1 ;
    numbers = malloc(sz*sizeof(int));

    for (int i=0; i<=cnt; i++){
        if (cnt >= sz) {
            sz *= 2 ;
            numbers = realloc(numbers, sz*sizeof(int));
        }
        scanf("%d", &n);
        if (n == 0) break;
        numbers[i] = n; 
        cnt++;
    }
    whamsort(cnt,numbers);
    printf("numbers in the array are: "); 
    for (int i=0; i<cnt; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);

  return 0; 
}