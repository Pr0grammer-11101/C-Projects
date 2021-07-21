#include<stdio.h>

int partition(int[], int, int, int, int);

int main(void)
{
    int a[30], size, i;
    
    printf("enter the size of the array.......");
    scanf("%d", &size);
    
    printf("enter the elements into the array......\n\n");
    
    i=0;
    
    while(i<size)
    {
        scanf("%d", a+i);
        i++;
    }
    
    int pivot=a[size-1]; // considering the last element to be the pivot....
    partition(a, size, -1, 0, pivot);
    
    printf("\nThe array after partitioning it is......\n\n");
    
    i=0;
    
    while(i<size)
    {
        printf("%d ", *(a+i));
        i++;
    }
    
    return 0;
    
}



int partition(int a[], int s, int i, int j, int pivot)
{
    int temp, index;
    if(j==s-1)
    {
        i=0;
        
        while(i<s-1)
        {
            if(pivot>=a[i] && pivot<=a[i+1])
            {
                index=i+1;
                break;
            }
            
            i++;
        }
        
        temp=a[index];
        a[index]=a[s-1];
        a[s-1]=temp;
        
        return 0;
    }
    
    if(a[j]<=pivot)
    {
        i++;
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
    }
    
    j++;
    partition(a, s, i, j, pivot);
    
    return 0;
}