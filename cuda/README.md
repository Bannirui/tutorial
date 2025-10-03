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

### THREAD

Each of the running threads is individual, they know the following.
Each of these are dim3 structures and can be read in the kernel to assign particular workloads to any thread.

- threadIdx Thread index within the block
- blockIdx Block index within the grid
- blockDim Block dimensions in threads
- gridDim Grid dimensions in blocks

### MEMORY

- Global All running threads can read and write global memory and so can the CPU. The functions cudaMalloc, cudaFree, cudaMemcpy and cudaMemset all deal with global memory
- Constant
- Texture
- Block
  - Shared memory
  - Thread
    - Local
    - Registers