#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) 
{
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int *globaldata=NULL;
    int localdata;
	int i;
    if (rank == 0) 
    {
        globaldata = malloc(size * sizeof(int) );
        for ( i=0; i<size; i++)
            globaldata[i] = 2*i+1;
        printf("Processor %d has value: ", rank);
        for ( i=0; i<size; i++)
            printf("%d ", globaldata[i]);
        printf("\n");
    }
    MPI_Scatter(globaldata, 1, MPI_INT, &localdata, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Processor %d has value %d\n", rank, localdata);
    localdata *= 2;
    printf("Processor %d doubled the value, updated value now is %d\n", rank, localdata);
    MPI_Gather(&localdata, 1, MPI_INT, globaldata, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Processor %d has value: ", rank);
        for ( i=0; i<size; i++)
            printf("%d ", globaldata[i]);
        printf("\n");
    }
    if (rank == 0)
        free(globaldata);
    MPI_Finalize();
    return 0;
}


Output:


Program 2:
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
struct mystruct{
    int sendarray[4];
    int a;
    char array2[4];
};
typedef struct mystruct struct_t;
int main (int argc, char ** argv)
{
    int rank, size;
    struct_t fd;
    struct_t recv;
    int i, j;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // init
    for (i=0;i<4;i++){
        fd.sendarray[i] = 0;
        fd.array2[i] = 0;

        recv.sendarray[i] =999;
        recv.array2[i]    = 99;
    }
    recv.a =999;
    // put some stuff in your array
    fd.sendarray[rank] = rank*10;
    fd.array2[rank]    = (char)(rank*20);
    fd.a = rank;
    printf("rank : %d, fd.sendarray[%d] : %d\n", rank, rank, fd.sendarray[rank]);
    // gather data from all now.. send the int:
    MPI_Allgather (&(fd.sendarray[rank]), 1, MPI_INT,  recv.sendarray, 1, MPI_INT,  MPI_COMM_WORLD);
    // then the char
    MPI_Allgather (&(fd.array2[rank]),    1, MPI_CHAR, recv.array2,    1, MPI_CHAR, MPI_COMM_WORLD);
    // check if correct data has been received
    if (rank == 0) {
        printf("Received:\n");
        printf("---\n");
        printf("int array:  ");
        for (j=0; j<4; j++) printf("%3d ", recv.sendarray[j]);
        printf("\nchar array: ");
        for (j=0; j<4; j++) printf("%3d ", (int)(recv.array2[j]));
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}  	   
Output:

Program 3:
#include <stdio.h>
#include "mpi.h"

int main( int argc, char **argv )
{
    int send[4], recv[3];
    int rank, size, k;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    if (size != 4) {
       printf("Error,Number of processors must be equal to 4");
       printf("Program aborting");
       MPI_Abort(MPI_COMM_WORLD, 1);
    }
    for (k=0;k<size;k++)
     send[k] = (k+1) + rank*size;
    printf("Rank %d : send = %d %d %d %d\n", rank, send[0], send[1], send[2], send[3]);
    MPI_Alltoall(&send, 1, MPI_FLOAT, &recv, 1, MPI_INT, MPI_COMM_WORLD);
    printf("Rank %d : receive = %d %d %d %d\n", rank, recv[0], recv[1], recv[2], recv[3]);
    MPI_Finalize();
    return 0;
}
Output:

Program 4:
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv) 
{
  MPI_Init(NULL, NULL);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int number_amount;
  if (world_rank == 0) 
  {
    const int MAX_NUMBERS = 100;
    int numbers[MAX_NUMBERS];
    srand(time(NULL));
    number_amount = (rand() / (float)RAND_MAX) * MAX_NUMBERS;
    MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
    printf("Rank 0 sent %d numbers to Rank 1\n", number_amount);
  } 
  else if (world_rank == 1) 
  {
    MPI_Status status;
    MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_INT, &number_amount);
    int* number_buf = (int*)malloc(sizeof(int) *number_amount);
    MPI_Recv(number_buf, number_amount, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    printf("Rank 1 dynamically received %d numbers from Rank 0.\n",number_amount);
    free(number_buf);
  }
  MPI_Finalize();
}
Output:

Program 5:

#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    int myid, numprocs, i, j;
    int buffer[10], buffer2[10];
    MPI_Request req, req2;
    MPI_Status status;
    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    j = (myid + 1) % numprocs;
    i = myid - 1;
    if (i < 0)
        i = numprocs - 1;       
       if(MPI_Issend(buffer2, 10, MPI_INT,j, 123, MPI_COMM_WORLD, &req2)==0)
     {
         printf("Success in Issend()\n");
      }
     if(MPI_Irecv(buffer, 10, MPI_INT,i, 123, MPI_COMM_WORLD, &req)==0)
     {
         printf("Success in Irecv()\n");
      }    
    MPI_Wait(&req, &status);
    MPI_Wait(&req2, &status);
    MPI_Finalize();
    return 0;
}
Output:

Program 6:
#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    int myid, numprocs, left, right, flag=0;
    int buffer[10], buffer2[10];
    MPI_Request request;
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    right = (myid + 1) % numprocs;
    left = myid - 1;
    if (left < 0)
        left = numprocs - 1;
    MPI_Irecv(buffer, 10, MPI_INT, left, 123, MPI_COMM_WORLD, &request);
    MPI_Send(buffer2, 10, MPI_INT, right, 123, MPI_COMM_WORLD);
    MPI_Test(&request, &flag, &status);
    if(flag)
      printf("Test Passed request Accepted\n");
    else
      printf("Test Failed\n");
    MPI_Finalize();
    return 0;
}
Output:




