#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <cuda.h>

/**
 * kernel called by host, executed in device
 * add 2 nums
 */
__global__ void AddInt(int *a, int *b) {
    for (int i = 0; i < 10000005; i++) {
        a[0] += b[0];
    }
}

__global__ void AddInts(int *a, int *b, int count) {
    int id = blockIdx.x * blockDim.x + threadIdx.x;
    if (id < count) {
        a[id] += b[id];
    }
}

void test2NUms() {
    int a = 0, b = 1;
    int *p_a, *p_b;
    if (cudaMalloc(&p_a, sizeof(int)) != cudaSuccess) {
        std::cout << "error allocating memory" << std::endl;
        return;
    }
    if (cudaMalloc(&p_b, sizeof(int)) != cudaSuccess) {
        std::cout << "error allocating memory" << std::endl;
        return;
    }

    if (cudaMemcpy(p_a, &a, sizeof(int), cudaMemcpyHostToDevice) != cudaSuccess) {
        std::cout << "error cpy memory" << std::endl;
        cudaFree(p_a);
        cudaFree(p_b);
        return;
    }
    if (cudaMemcpy(p_b, &b, sizeof(int), cudaMemcpyHostToDevice) != cudaSuccess) {
        std::cout << "error cpy memory" << std::endl;
        cudaFree(p_a);
        cudaFree(p_b);
        return;
    }

    AddInt<<<1, 1>>>(p_a, p_b);

    cudaMemcpy(&a, p_a, sizeof(int), cudaMemcpyDeviceToHost);

    std::cout << "the result is " << a << std::endl;

    cudaFree(p_a);
    cudaFree(p_b);
}

void testThreads() {
    srand(time(nullptr));
    int count = 100;
    int *h_a = new int[count];
    int *h_b = new int[count];

    for (int i = 0; i < count; i++) {
        h_a[i] = rand() % 1000;
        h_b[i] = rand() % 1000;
    }
    std::cout << "Prior to addition:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << h_a[i] << " " << h_b[i] << std::endl;
    }
    int *d_a, *d_b;
    if (cudaMalloc(&d_a, sizeof(int) * count) != cudaSuccess) {
        std::cout << "malloc error" << std::endl;
        return;
    }
    if (cudaMalloc(&d_b, sizeof(int) * count) != cudaSuccess) {
        std::cout << "malloc error" << std::endl;
        cudaFree(d_a);
        return;
    }
    if (cudaMemcpy(d_a, h_a, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess) {
        std::cout << "cudaMemcpy error" << std::endl;
        cudaFree(d_a);
        cudaFree(d_b);
        return;
    }
    if (cudaMemcpy(d_b, h_b, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess) {
        std::cout << "cudaMemcpy error" << std::endl;
        cudaFree(d_a);
        cudaFree(d_b);
        return;
    }
    AddInts<<<count / 256 + 1,256>>>(d_a, d_b, count);
    if (cudaMemcpy(h_a, d_a, sizeof(int) * count, cudaMemcpyDeviceToHost) != cudaSuccess) {
        delete[] h_a;
        delete[] h_b;
        cudaFree(d_a);
        cudaFree(d_b);
        std::cout << "cudaMemcpy error" << std::endl;
        return;
    }
    // first 5
    for (int i = 0; i < 5; i++) {
        std::cout << "It's " << h_a[i] << std::endl;
    }
    cudaFree(d_a);
    cudaFree(d_b);
    delete[] h_a;
    delete[] h_b;
}

int main() {
    test2NUms();
    testThreads();
    return 0;
}
