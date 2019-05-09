#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<time.h>


void shellSort(int arr[],int n) 
{  
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 

            arr[j] = temp; 
        } 
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
shellSort(arr,n);

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
printf("enter elements to sort:\n");
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);

write(fd1[1],&arr,sizeof(arr));
close(fd1[1]);
e2=clock();
time2=(double)(e2-s2);

}

 return 0;
}
