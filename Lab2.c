#include<stdio.h>
#include <omp.h>

int main(){
    int num_iterations;
    printf("Enter the number of iterations:");
    scanf("%d",&num_iterations);
    #pragma omp parallel
    {
        #pragma omp for schedule(static ,2)
        for(int i=0;i<num_iterations;i++){
            printf("Thread %d : Iteration %d\n",omp_get_thread_num(),i);
        }  
        }
        return 0;
    }


//output
// Enter the number of iterations:5
// Thread 0 : Iteration 0
// Thread 0 : Iteration 1
// Thread 1 : Iteration 2
// Thread 1 : Iteration 3
// Thread 2 : Iteration 4
