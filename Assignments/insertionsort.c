#include<stdio.h>
int main() 
{
    int n,i,j,key;
    int count=0;
    printf("Enter number of students: ");
    scanf("%d",&n);
    int marks[n];
    printf("Enter the marks:\n");
    for(i=0;i<n;i++) 
    {
        scanf("%d",&marks[i]);
    }
    for(i=1;i<n;i++) 
    {
        key=marks[i];
        j=i-1;
        while(j>=0 && key<marks[j]) 
        {
            marks[j+1]=marks[j];
            count++;
            j--;
        }

        marks[j+1]=key;
        printf("After pass %d: ", i);
        for(int k=0;k<n;k++)
        {
            printf("%d ",marks[k]);
        }
        printf("\n");
    }

    printf("\nsorted list: ");
    for (i=0;i<n;i++)
    {
        printf("%d ",marks[i]);
    }

    printf("\nTotal number of element shifts = %d\n", count);

    return 0;
}