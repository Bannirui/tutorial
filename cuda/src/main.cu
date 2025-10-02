#include <iostream>
#include <cuda.h>

__global__ void AddIntsCUDA(int *a, int *b) {
    for (int i = 0; i < 10000005; i++) {
        a[0] += b[0];
    }
}

int main() {
    int a = 0, b = 1;
    int *p_a, *p_b;
    if (cudaMalloc(&p_a, sizeof(int)) != cudaSuccess) {
        std::cout << "error allocating memory" << std::endl;
        return 0;
    }
    if (cudaMalloc(&p_b, sizeof(int)) != cudaSuccess) {
        std::cout << "error allocating memory" << std::endl;
        return 0;
    }

    if (cudaMemcpy(p_a, &a, sizeof(int), cudaMemcpyHostToDevice) != cudaSuccess) {
        std::cout << "error cpy memory" << std::endl;
        cudaFree(p_a);
        cudaFree(p_b);
        return 0;
    }
    if (cudaMemcpy(p_b, &b, sizeof(int), cudaMemcpyHostToDevice) != cudaSuccess) {
        std::cout << "error cpy memory" << std::endl;
        cudaFree(p_a);
        cudaFree(p_b);
        return 0;
    }

    AddIntsCUDA<<<1, 1>>>(p_a, p_b);

    cudaMemcpy(&a, p_a, sizeof(int), cudaMemcpyDeviceToHost);

    std::cout << "the result is " << a << std::endl;

    cudaFree(p_a);
    cudaFree(p_b);
    return 0;
}
