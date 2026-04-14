#include<stdio.h>
#include<limits.h>
#define SIZE 25
#include<stdlib.h>
#include<math.h>
int main(){
    int max=INT_MIN;
    int smax=INT_MIN;
    int arr[SIZE];
    int i,j,N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<N;i++){
        if(arr[i]>max){
         smax=max;
         max=arr[i];
        }
        else if(arr[i]!=max && arr[i]>smax){
            smax=arr[i];
        }
    }
    if(smax==INT_MIN) printf("-1");
    else printf("%d",smax);
    return 0;

}
