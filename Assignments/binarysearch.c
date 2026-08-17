#include<stdio.h>
int main()
 {
    int n,i,key;
    int low,high,mid;
    int count=0;
    int found=0;
    printf("Enter Number Of Employees:");
    scanf("%d",&n);
    int ar[n];
    printf("Enter Employee IDs in Ascending Order:\n");
    for (i=0;i<n;i++)
    {
       scanf("%d",&ar[i]);
    }
    printf("Enter Employee ID to Search: ");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high) 
    {
        mid=(low+high)/2;
        count++;
        if (ar[mid]==key) 
        {
            found=1;
            break;
        }
        else if (key<ar[mid]) {
            high=mid-1;
        }
        else 
        {
            low=mid+1;
        }
    }

    if (found) 
    { 
       printf("Employee ID %d found at position %d.\n", key, mid + 1);
    }
    else
    {
        printf("Employee ID %d is not present.\n", key);
    }

    printf("Number of comparisons = %d\n", count);

    return 0;
}