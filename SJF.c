#include<stdio.h>
int  main(){
    int n , i , j ,temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int bt[n], wt[n],tat[n],p[n];
    float t_tat = 0 ; float t_wt = 0 ;
    printf("Enter burst times:\n");
    for(i = 0 ; i < n  ; i++){
        printf("P%d : ", i+1);
        scanf("%d",&bt[i]);
        p[i] = i+1 ;

        for ( i = 0; i < n; i++)
        {
           for (j = 0; j < n; i++)
           {
            if(bt[i] > bt[j]){
                temp = bt[i] ;
                bt[i] = bt[j] ;
                bt[j] = temp11 ;

                temp = p[i];
                p[i ] = p[j] ; 
                p[j] = temp ; 
            }
           }
           
        }

        wt[0] = 0 ; 
        for ( i = 1; i < n; i++)
        {
           wt[i] = wt[i-1] + bt[i-1] ; 
        }

        for(i = 0 ; i < n  ; i++ ){
            tat[i] = wt[i] + bt[i] ;
            t_tat += tat[i] ;
            t_wt += wt[i] ; 
        }

        printf("\nProcess\tBT\tWT\tTAT\n");
        for(i = 0 ; i < n ; i++){
            printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
        }
        printf("\nAverage Waiting Time: %.2f",t_wt/n);
        printf("\nAverage Turnaround Time: %.2f\n",t_tat/n);
        
        
    }
}