#include<stdio.h>
int main(){
    int n,i;
    printf("enter the size of array:");
    scanf("%d",&n);

    int arr[n];
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

  printf("enter the operation to be performed: \n1 for linear search,\n2 for reversal,\n3 for updation, \n4 for inserting,\n5 for deleting,\n6 for sorting\n");
  scanf("%d",&operations);
    
    n=sizeof(arr)/sizeof(arr[0]);
    int num;
    
    int update;
     int insert;   
      int pos; 
      
     switch(operations){
        case 1: 
        
        printf("enter the element to be searched:\n");
        scanf("%d",&num);
       for(i=0; i<n;i++){
        if(num==arr[i]){
             printf("element found at position %d\n",i+1);
            
         }
         else{
            printf("element not found\n ");
            
         }
        }

        case 2:
        
        printf("reversed array is:\n");
        for(i=n-1;i>=0;i--){
        
            printf("%d\t",arr[i]);
        }
     
        
         case 3:
        printf("enter the updated element and the position :(element,position):\n");
        scanf("%d,%d",update,pos);
        arr[pos-1]=update;
        printf("array after updation is:\n");

        for (i=0;i<n;i++){
            printf("arr[%d]=%d\n",i,arr[i]);

        }


        case 4:
        
             
        printf("enter the element to be inserted and the position:(element,position):\n") ;
        scanf("%d,%d",insert,pos);

          if(pos>=n){
            printf("element can't be inserted");
          }
         
          for (i = n-1; i >= pos; i--)  {
        arr[i] = arr[i - 1];  
           arr[pos - 1] = insert; 
         }
          printf("Array elements after insertion\n");  
         for (i = 0; i < n; i++)  {
        printf("%d ", arr[i]);  
           printf("\n"); 
         }
     


        
     




         

     



   
     }
    return 0;
}