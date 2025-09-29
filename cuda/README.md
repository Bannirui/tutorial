CUDA
---

### API

- `cudaMalloc(void** devPtr, size_t sizeInBytes);`
- `cudaFree(void** devPtr);`
- `cudaMemcpy(void* dest, void* src, size_t sizeInBytes, enum direction);`

### SYNTAX

- `SomeKernel<<<m,n>>>(parameters)` launch m block with n thread