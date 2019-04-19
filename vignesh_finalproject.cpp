#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void queue1()
{
int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("------------------------------------------------------------------------------------------------------------------------");
  printf("\t\t\t\t-----------Round Robin Algorithm--------\t\t\t\n");
  printf("------------------------------------------------------------------------------------------------------------------------");
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1;
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count];
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f\n",turnaround_time*1.0/n);  
  printf("------------------------------------------------------------------------------------------------------------------------");
}
void queue2()
{
	int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
	printf("\t\t\t\t-----------Priority Scheduling--------\t\t\t\n");
	printf("------------------------------------------------------------------------------------------------------------------------");
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the Burst Time and Priority of P[%d]:",i+1);
        scanf("%d",&bt[i]);
        scanf("%d",&pr[i]);
        p[i]=i+1;           
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    printf("\nProcess\t\tPriority\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i],pr[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;    
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
    printf("------------------------------------------------------------------------------------------------------------------------");
}
void queue3()
{
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	printf("\t\t\t\t----------- First Come First Serve--------\t\t\t\n");
	printf("------------------------------------------------------------------------------------------------------------------------");
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);

}
int main()
{
	int i=0, j, a, num[30];
        for (i = 0; i < 3; ++i)
        {
            printf("Enter the priority of the queue %d\n",i+1);
            scanf("%d", &num[i]);

        }


        for (i = 0; i < 3; ++i)
        {

            for (j = i + 1; j < 3; ++j)
            {

                if (num[i] > num[j])
                {

                    a =  num[i];
                    num[i] = num[j];
                    num[j] = a;
                }

            }

        }
        printf("The Queues arranged in ascending order of priority\n");
        for (i = 0; i < 3; ++i)
            printf("%d\n", num[i]);

        int high= 0;
            high= num[0];
        if(high>=0)
        {
            queue1();
            sleep(10);
        }
        int mid= 0;
            mid = num[1];
        if(mid>0)
        {
            queue2();
            sleep(10);
        }
        int low= 0;
            low=num[2];
        if(low>0)
        {
            queue3();
            sleep(10);
        }

}
