#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
int n;
void* selection_sort(void* arg){

int *arr=(int*) arg;

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
v2=pthread_create(&t2,0,selection_sort,(void*)arr);
pthread_join(t2,NULL);
v3=pthread_create(&t3,0,output,(void*)arr);
pthread_join(t3,NULL);

end =clock();
double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("time consumed : %.4f ms .\n",time*1000);

}

