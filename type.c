#include<stdio.h>
#define MP 10
#define wt WaitingTime
#define bt BurstTime
#define aT ArrivalTime
#define TaT TurnaroundTime
#define pn processes
#define pId processId
#define rt RemainingTime
#define ct CurrentTime
#define cp currentProcess

typedef struct{
    int pId;
    int aT;
    int bt;
    int wt;
    int TaT;
}Process;
void cal_wt(Process pn[],int n){
    int rt[MP];
    int completed=0,ct=0,shortestJob=0;
    int min_bt=9999,totTime=0;
    for(int i=0;i<n;i++){
        rt[i]=pn[i].bt;
        totTime+=pn[i].bt;
    }
    while(completed!=n){
        for(int i=0;i<n;i++){
            if(pn[i].aT<=ct&&rt[i]<min_bt&&rt[i]>0){
                min_bt=rt[i];
                shortestJob=i;
            }
        }
        rt[shortestJob]--;
        if(rt[shortestJob]==0){
            completed++;
            min_bt=9999;
            int cp=shortestJob;
            pn[cp].wt=ct-pn[cp].aT-pn[cp].bt;
            pn[cp].TaT=ct-pn[cp].aT;
            if(completed==n)
            break;
        }
        ct++;
    }
}
void calAvgTimes(Process pn[],int n){
    int totwt=0,totTaT=0;
    cal_wt(pn,n);
    printf("Process\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++){
        totwt+=pn[i].wt;
        totTaT+=pn[i].TaT;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pn[i].pId,pn[i].aT,pn[i].bt,pn[i].wt,pn[i].TaT);
    }
    double Avgwt=(double)totwt/n;
    double AvgTat=(double)totTaT/n;
    printf("\nAverage Waiting Time: %.2lf\n",Avgwt);
    printf("Average Turnaround Time: %.2lf\n",AvgTat);
}
int main(){
    int n;
    Process pn[MP];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("Enter Arrival Time: ");
        scanf("%d",&pn[i].aT);
        printf("Enter Burst Time: "),
        scanf("%d",&pn[i].bt);
        pn[i].pId=i+1;
    }
    calAvgTimes(pn,n);
    return 0;
}