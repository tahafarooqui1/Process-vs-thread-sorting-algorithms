#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<time.h>


void selection_sort(int arr[],int n){

int i, j,temp;
   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
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
selection_sort(arr,n);

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
