#include <iostream>
#include <mpi.h>
#include <fstream>
#include <string>
#include <vector>

static int rank, num_proces, bloque;
float A[8*8];
float B[8];

static void llenar(){
    for(int i=0; i < sizeof(A); i++){
        A[i]=1;
    }

    for(int i=0; i < sizeof(B); i++){
        B[i]=2;
    }
}

int main(int argc, char **argv) {

    llenar();

    MPI_Init(&argc, &argv);

    // Obtener el rank y el número de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proces);

    if (rank == 0) {
        bloque = sizeof(A) /num_proces;

        for (int rank = 1; rank < num_proces; rank++) {
            MPI_Send(&vector[(nRank-1) * bloque], bloque, MPI_INT, nRank, 0, MPI_COMM_WORLD);
        }

        std::vector<int> vec0(vector.begin() + bloque*(num_procesos-1), vector.end());
        std::vector<int> vecFinal = ordenar(vec0);

        for (int nRank = 1; nRank <num_procesos; nRank++) {
            std::vector<int> vecTemp(bloque);
            MPI_Recv(vecTemp.data(), bloque, MPI_INT, nRank, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            vecFinal = mezclar(vecTemp, vecFinal);
        }

        for (int i = 0; i < vecFinal.size(); ++i) {
            std::printf("{%d}, ", vecFinal[i]);
        }
        std::cout << std::endl;
    } else {
        bloque = vector.size() /num_procesos;
        std::vector<int> vectorTmp(bloque);
        MPI_Recv(vectorTmp.data(), bloque, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::vector<int> vectoResp = ordenar(vectorTmp);
        MPI_Send(vectoResp.data(), bloque, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }



    MPI_Finalize();
    return 0;
}