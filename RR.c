#include<stdio.h>
int main()
{
    int tat[30],wt[30],rem_bt[30],bt[30],temp,qt,n,i,count=0,sq=0;
    float awt=0,atat=0;
    printf("Enter the number of process :");
    scanf("%d",&n);
    printf("\nEnter the Burst time for the process :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("\nEnter the Time Quantum :");
    scanf("%d",&qt);
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
           
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
                rem_bt[i]=rem_bt[i]-qt;
            else if(rem_bt[i]>0)
            {
                temp=rem_bt[i];
                rem_bt[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;
            
        }
        if(n==count)
            break;
    }
    printf("\nProcess \tBurst time \tWaiting Time \tTurn around Time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t\t %d \t\t %d\t\t %d\n",i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Average waiting time = %f :",awt);
    printf("\nAverage Turn around  time = %f :",atat);
    return 0;
}