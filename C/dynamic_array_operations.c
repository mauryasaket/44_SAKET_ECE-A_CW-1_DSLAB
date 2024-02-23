#include<stdio.h>
#include<stdlib.h>

//function for searching
void search(int *arr, int n){
  
  int num;
  printf("enter the element to be searched:\n");
  scanf("%d",&num);
  for(int i=0; i<n;i++){
    if(num==arr[i]){
      printf("element found at position %d\n",i+1);
      return;
    }
  }
  printf("element not found");
}

//function for reversing the array
void reverse(int *arr, int n){
 
  printf("reversed array is:\n");
  for(int i=n-1;i>=0;i--){
    printf("%d\t",arr[i]);
  }
}

//updation function
void update(int *arr,int n){
  int i;

  for(i=0;i<n;i++){
    if(i%2==0){
      arr[i]*=2;
    }
    else{
      arr[i]+=5;
    }
  }
  printf("array after updation is:\n");

  for (i=0;i<n;i++){
    printf("arr[%d]=%d\n",i,arr[i]);
  }
}

//insert function
void insert(int *arr,int n){
  int pos,i,insert;

 
  int *new_arr = (int*)malloc((n+1) * sizeof(int));
  if(new_arr == NULL){
    printf("Memory allocation failed\n");
    return;
  }
  


  for(i=0;i<n;i++){
    new_arr[i]=arr[i];
  }
  
  printf("enter the element to be inserted and the position:(element,position):\n") ;
  scanf("%d,%d",&insert,&pos);

  if(pos>n){
    printf("element can't be inserted\n");
  }
  else{
   
    for (i = n; i >= pos; i--)  {
      new_arr[i] = new_arr[i - 1];  
    }

    new_arr[pos - 1] = insert; 
    
    printf("Array elements after insertion\n");  
    for (i = 0; i <= n; i++)  {
      printf("%d ", new_arr[i]);  
      printf("\n"); 
    }
  }
  
  free(arr);
  
  arr = new_arr;
}

//function for deleting an array
void delete(int *arr,int n){
  int del,i,pos;
       
  printf("enter the element to be deleted:");
  scanf("%d",&del);

  for(i=0;i<n;i++){
    if(del==arr[i]){
      pos=i+1;
      if(pos>=n+1){
        printf("deletion not possible\n");
      }
      else{
      
        for(i=pos-1;i<n-1;i++){
          arr[i]=arr[i+1];
        }
        //print the new array
        printf("resultant array is:\n");
        for(i=0;i<n-1;i++){
          printf("%d\n",arr[i]);
        }
        arr = (int*)realloc(arr, (n-1) * sizeof(int));
        if(arr == NULL){
          printf("Memory reallocation failed\n");
          return;
        }
      }
    }
  }
}

//swapping
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//function for sorting an array
void sort(int *arr,int n){
           
  int swapped;
  for(int i=0; i<n-1 ;i++){
    swapped=0;
    for(int j=0;j<n-i-1;j++){
      if(arr[i]>arr[i+1]){
        swap(&arr[j], &arr[j+1]);
        swapped=1;
      }
    }
    if(swapped==0)break;
  }
  printf("sorted array is:");
  for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
  }
}

int main(){
  int n,i;
  printf("enter the size of array:");
  scanf("%d",&n);


  int *arr = (int*)malloc(n * sizeof(int));
  if(arr == NULL){
    printf("Memory allocation failed\n");
    return 1;
  }

  for(int i=0; i<n;i++){
    printf("enter the element at %d position:",i+1);
    scanf("%d",&arr[i]);
  }
  printf("array is:");
  for(int i=0; i<n;i++){
    printf("%d\t",arr[i]);
  }
  printf("\n");

  int operations;

  do{
    printf("enter the operation to be performed: \n1. for linear search\n2. for reversal\n3. for updation \n4. for inserting\n5. for deleting\n6. for sorting\n7. for exiting the code:\n");
    scanf("%d",&operations);
    
    switch(operations){
      case 1: 
        search(arr,n);
        break;
      case 2:
        reverse(arr,n);
        break;
      case 3:
        update(arr,n);
        break;
      case 4:
        insert(arr,n); 
        break;
      case 5:
        delete(arr,n);
        break;
      case 6:
        sort(arr,n);
        break;
      case 7:
      default: 
        printf("thank you:\n");
    }
  } while(operations<7);

 
  free(arr);
  return 0;
}
