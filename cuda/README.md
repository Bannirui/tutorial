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

- `SomeKernel<<<m,n>>>(parameters)` launch m block with n thread, m*n threads in total

### DATA TYPE

- dim3 Dim3 is a 3d structure or vector type with three integers, x, y and z. Can initialise as many of the three coordinates as like
  - `dim3 threads(256)` Initialise with x as 256, y and z will both be 1
  - `dim3 blocks(100, 100);` Initialise x and y, z will be 1
  - `dim3 anotherOne(10, 54, 32);` Initialise all three values, x will be 10, y gets 54 and z will be 32