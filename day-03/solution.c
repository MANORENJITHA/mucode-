//MOVE ZEROES TO THE END 
// TWO POINTER TECHNIQUE 
#include<stdio.h>
#define SIZE 35
int main(){
int N,arr[SIZE],temp;
scanf("%d",&N);
int j=0;
for(int i=0;i<N;i++)
    scanf("%d",&arr[i]);
  
for(int i=0;i<N;i++){
   if(arr[i]!=0){
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    j++;
   }
}
for(int i=0;i<N;i++)
printf("%d ",arr[i]);
 return 0;
}
