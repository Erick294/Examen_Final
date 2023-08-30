#include <iostream>
#include <mpi.h>
#include <fstream>
#include <string>
#include <vector>

static int rank, num_proces, bloque;
static std::vector<float> A(4*4);
static std::vector<float> B(4);

static void llenar(){
    for(int i=0; i < A.size(); i++){
        A[i]=1;
    }

    for(int i=0; i < B.size(); i++){
        B[i]=2;
    }
}

static std:vector<float> multiplicar(std::vector<float> a, std::vector<float> b){
    std::vector<float> tmp(a.size());

    for(int i=0; i < a.size(); i++){
        tmp[i] = a[i]*b[i];
    }

    return tmp;
}

int main(int argc, char **argv) {

    llenar();

    MPI_Init(&argc, &argv);

    // Obtener el rank y el número de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proces);

    MPI_Bcast(&B, sizeof(B), MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        bloque = sizeof(A)/num_proces;

        for (int rank = 1; rank < num_proces; rank++) {
            MPI_Send(&A[(rank-1) * bloque], bloque, MPI_FLOAT, rank, 0, MPI_COMM_WORLD);
        }

        for (int rank = 1; rank <num_proces; rank++) {
            float tmp[bloque];

            MPI_Recv(&tmp, bloque, MPI_FLOAT, rank, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    } else {
        bloque = sizeof(A) /num_proces;
        float tmp(bloque);

        MPI_Recv(&tmp, bloque, MPI_FLOAT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        float resp = tmp;

        MPI_Send(&resp, bloque, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}