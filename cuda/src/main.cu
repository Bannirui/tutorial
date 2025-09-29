#include <iostream>
#include <cuda.h>

__global__ void AddIntsCUDA(int *a, int *b) {
    a[0]+=b[0];
}

int main() {
    int a=5, b=8;
    int *p_a, *p_b;
    cudaMalloc(&p_a, sizeof(int));
    cudaMalloc(&p_b, sizeof(int));

    cudaMemcpy(p_a, &a, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(p_b, &b, sizeof(int), cudaMemcpyHostToDevice);

    AddIntsCUDA<<<1, 1>>>(p_a, p_b);

    cudaMemcpy(&a, p_a, sizeof(int), cudaMemcpyDeviceToHost);

    std::cout<<"the result is "<<a<<std::endl;

    cudaFree(p_a);
    cudaFree(p_b);
    return 0;
}
