#include<stdio.h> 
# define n 10 
int main() {
    int proc[n] , part[n] , p_alloc[n],used[n] = {0} ;
    int n_proc , n_part ;
    printf("Partition : ");
    scanf("%d" ,& n_part) ;
    for (int i = 0; i < n_part; i++) scanf("%d" , & part[i]) ;
   
     printf("Process : ");
    scanf("%d" ,& n_proc) ;
    for (int i = 0; i < n_proc; i++) scanf("%d" , & proc[i]) ;
   
    for (int i = 0; i < n_proc; i++)
    {
        int best = -1 ;
        for(int j = 0 ; j < n_part ; j++){
            if(!used[j] && part[j] >= proc[i]){
                if(best == -1 || part[j ] < part[best ] ){
                    best = j ;
                }
            }

            if(best != -1){
                p_alloc[i] = best ; 
                used[best] = 1 ;
            }
            else{
                p_alloc [i] = -10 ;
            }
        }

        printf("\nProcess\tSize\tPartition");
        for (int i = 0; i < n_proc; i++){ printf("%d\t%d",i+1 ,proc[i]) ;
        if(p_alloc[i] != -1) printf("%d\n",p_alloc[i] + 1) ;
        else printf("NOt allo") ;
    }
        
    }
    

    
}