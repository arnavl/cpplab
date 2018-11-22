#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
        int rank;
        int buf;
        const int root=0;
		int global_sum;
        
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		
		buf=(rank*2+1)%5;
		printf("[%d]: Before Reduce, buf is %d\n", rank, buf);
		
		MPI_Reduce(&buf, &global_sum, 1, MPI_INT, MPI_SUM, 0,
           MPI_COMM_WORLD);
        
        if(rank == root) {
 
           printf("[%d]: After reduce, sum is %d\n", rank, global_sum);
        }

        
        /* everyone calls bcast, data is taken from root and ends up in everyone's buf */
        
        
        //printf("[%d]: After Bcast, buf is %d\n", rank, buf);

        MPI_Finalize();
        return 0;
}
