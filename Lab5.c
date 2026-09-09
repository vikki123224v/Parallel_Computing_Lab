#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank,size;
    int number;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(size<2){
        if(rank==0){
            printf("This program requires at least 2 processes.\n");
        }
        MPI_Finalize();
        return 0;
    }

    if (rank==0) {
        // Process 0 sends a number to Process 1
    number = 42;
    printf("Process 0 is sending number %d to Process 1\n", number);
    MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
} else if (rank == 1) {
    // Process 1 receives a number from Process 0
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from Process 0\n", number);
}

// Finalize the MPI environment
MPI_Finalize();
return 0;
}
//Output
// cl Lab5.c msmpi.lib
// Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35215 for x64
// Copyright (C) Microsoft Corporation.  All rights reserved.

// Lab5.c
// Microsoft (R) Incremental Linker Version 14.44.35215.0
// Copyright (C) Microsoft Corporation.  All rights reserved.

// /out:Lab5.exe
// Lab5.obj
// msmpi.lib

//  mpiexec -n 2 Lab5.exe
// Process 0 is sending number 42 to Process 1
// Process 1 received number 42 from Process 0
//  mpiexec -n 3 Lab5.exe
// Process 1 received number 42 from Process 0
// Process 0 is sending number 42 to Process 1

//  mpiexec -n 4 Lab5.exe
// Process 1 received number 42 from Process 0
// Process 0 is sending number 42 to Process 1

// mpiexec -n 23 Lab5.exe
// Process 1 received number 42 from Process 0
// Process 0 is sending number 42 to Process 1

//  mpiexec -n 44 Lab5.exe
// Process 0 is sending number 42 to Process 1
// Process 1 received number 42 from Process 0
