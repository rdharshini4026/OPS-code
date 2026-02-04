
#include <stdio.h>

int main() {
    int n,tq,bt[10],rt[10],wt[10]={0},time=0,rem,i;

    printf("Processes: ");
    scanf("%d",&n);
    rem=n;

    for(i=0;i<n;i++){
        printf("BT P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Time Quantum: ");
    scanf("%d",&tq);

    while(rem){
        for(i=0;i<n;i++){
            if(rt[i]>0){
                int exec = (rt[i]>tq)?tq:rt[i];
                time += exec;
                rt[i] -= exec;

                if(rt[i]==0){
                    wt[i]=time-bt[i];
                    rem--;
                }
            }
        }
    }

    printf("\nP\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],wt[i]+bt[i]);

    return 0;
}

