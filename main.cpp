#include <iostream>
#include <mpi.h>
#include <fstream>
#include <string>
#include <vector>

static int rank, num_proces, bloque;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    // Obtener el rank y el número de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proces);


    MPI_Finalize();
    return 0;
}