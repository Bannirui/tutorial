CUDA
---

### FUNCTION QUALIFIERS

- __global__ called by host, runs on device
- __device__ called by device, runs on device
- __host__ normal host function

### API

- `cudaMalloc(void** devPtr, size_t sizeInBytes);`
- `cudaFree(void** devPtr);`
- `cudaMemcpy(void* dest, void* src, size_t sizeInBytes, enum direction);`

### SYNTAX

- `SomeKernel<<<m,n>>>(parameters)` launch m block with n thread