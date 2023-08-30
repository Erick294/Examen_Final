#include <iostream>
#include <mpi.h>
#include <fstream>
#include <string>
#include <vector>

static int rank, num_proces, bloque;
static std::vector<float> A(8*8); 
static std::vector<float> B(8);

static void llenar(){
    for(int i=0; i < A.size(); i++){
        A[i]=1;
    }

    for(int i=0; i < B.size(); i++){
        B[i]=2;
    }
}

static std::vector<float> multiplicar(std::vector<float> a, std::vector<float> b){
    std::vector<float> tmp(a.size());

    for(int i=0; i < a.size(); i++){
        tmp[i] = a[i]*b[i];
    }

    return tmp;
}

static std::vector<float> sumar(std::vector<float> resp, std::vector<float> tm){
    std::vector<float> tmp(resp.size());

    for(int i=0; i < resp.size(); i++){
        tmp[i] = resp[i]  + tm[i];
    }

    return tmp;
}

int main(int argc, char **argv) {

    llenar();

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proces);

    bloque = A.size()/num_proces;

    MPI_Bcast(&bloque, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(B.data(), B.size(), MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        
        for (int rank = 1; rank < num_proces; rank++) {
            MPI_Send(&A[(rank-1) * bloque], bloque, MPI_FLOAT, rank, 0, MPI_COMM_WORLD);
        }

        std::vector<float> vec(A.begin() + bloque*(num_proces-1), A.end());
        std::vector<float> vecFinal = multiplicar(vec, B);

        for (int rank = 1; rank < num_proces; rank++) {
            static std::vector<float> tmp(bloque);

            MPI_Recv(tmp.data(), bloque, MPI_FLOAT, rank, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            vecFinal = sumar(vecFinal, tmp);
        }

        std::printf("Vector Final:\n");
        for (int i = 0; i < vecFinal.size(); ++i) {
            std::printf("{%f}, ", vecFinal[i]);
        }
    } else {
        static std::vector<float> tmp(bloque);

        MPI_Recv(tmp.data(), bloque, MPI_FLOAT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        static std::vector<float> resp = multiplicar(tmp, B);

        MPI_Send(resp.data(), bloque, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}