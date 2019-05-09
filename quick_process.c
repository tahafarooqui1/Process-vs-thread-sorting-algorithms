#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<time.h>


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




int main()
{
int fd1[2];
pipe(fd1);
double time1,time2;
int n;
printf("enter number of elements: ");
scanf("%d",&n);
int arr[n];

int a=fork();



if(a>0){
clock_t s1,e1;
s1=clock();
wait(NULL);

read(fd1[0],&arr,sizeof(arr));
quickSort(arr,0, n-1);

close(fd1[0]);

e1=clock();

time1=(double)(e1-s1);
time1+=time2;
time1=(double)(time1/CLOCKS_PER_SEC);
time1=(double)(time1*1000);


printf("elements after sorting: \n");
for(int i=0;i<n;i++)
printf("%d\n",arr[i]);
printf("time consumed: %.4f ms.\n",time1);
}

if(a==0){
clock_t s2,e2;
s2=clock();

for(int i=0;i<n;i++)
arr[i]=rand()%n+1;

printf("elements before sorting: \n");
for(int i=0;i<n;i++)
printf("%d   ",arr[i]);

printf("\n\n");

write(fd1[1],&arr,sizeof(arr));
close(fd1[1]);
e2=clock();
time2=(double)(e2-s2);

}

 return 0;
}
