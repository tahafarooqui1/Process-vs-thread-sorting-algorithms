#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
int n;
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 

        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void* sort(void* arg){

int *arr=(int*) arg;
quickSort(arr,0,n-1);
}

void* input(void* arg){

int *arr=(int*) arg;
printf("enter elements: \n");
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);
}

void* output(void* arg){

int *arr=(int*) arg;
printf("elements after sorting: \n");
for(int i=0;i<n;i++)
printf("%d\n",arr[i]);
}


int main(){
pthread_t t1,t2,t3;
int v1,v2,v3;
printf("enter number of elements: ");
scanf("%d",&n);
int arr[n];
clock_t start, end;
start=clock();

v1=pthread_create(&t1,0,input,(void*)arr);
pthread_join(t1,NULL);
v2=pthread_create(&t2,0,sort,(void*)arr);
pthread_join(t2,NULL);
v3=pthread_create(&t3,0,output,(void*)arr);
pthread_join(t3,NULL);

end =clock();
double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("time consumed : %.4f ms .\n",time*1000);

}

