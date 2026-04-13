#include<stdio.h>
#include<math.h>

#define SIZE 20

int main(){
    int N;
    int arr[SIZE];

    scanf("%d", &N);

    for(int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    for(int i = 0; i <= N; i++){
        int flag = 1;

        if(arr[i] <= 1)
            flag = 0;

        for(int j = 2; j <= sqrt(arr[i]); j++){
            if(arr[i] % j == 0){
                flag = 0;
                break;
            }
        }

        if(flag == 1)
            printf("%d ", arr[i]);
    }

    return 0;
}
