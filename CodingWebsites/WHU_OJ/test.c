#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int findk(int *arr,int front,int rear,int kth){
    int i=front,j=rear;
    arr[0]=arr[front];
    while(i!=j){
        while(j>i&&arr[j]>=arr[0])
            j--;
        arr[i]=arr[j];
        while(j>i&&arr[i]<=arr[0])
            i++;
        arr[j]=arr[i];
    }
    arr[i]=arr[0];
    if (i==kth) return arr[i];
    else if(i>kth)
        return findk(arr,front,i-1,kth);
    else
        return findk(arr,i+1,rear,kth);  
}

int A[]={0,9,2,8,7,4,6,5,4,3,7,5,2,1};
int main(){
    int n = sizeof(A)/sizeof(A[0]) - 1;
    printf("n = %d\n",n);
    for(int i = 1 ; i <= n ; ++i) printf("%d ",findk(A,1,n,i));
    printf("\n");
    return 0;
}

//9!163e54%8C354E
