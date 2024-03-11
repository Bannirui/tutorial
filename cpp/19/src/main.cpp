#include <iostream>

int main(int argc, char **argv)
{
    // 数组元素未初始化 内存随机值
    int arr1[5];
    std::cout << "内存随机值" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << arr1[i] << std::endl;

    int arr2[5];
    // 轮询赋值
    std::cout << "轮询赋值" << std::endl;
    for (int i = 0; i < 5; i++)
        arr2[i] = i;
    for (int i = 0; i < 5; i++)
        std::cout << arr2[i] << std::endl;

    // 全部初始化为某个值
    int arr3[5] = {2};
    std::cout << "初始化" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << arr3[i] << std::endl;

    // 初始化 逐个指定值
    int arr4[5] = {0, 1, 2, 3, 4};
    std::cout << "初始化" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << arr4[i] << std::endl;

    // 指针指向的是数组首个元素的地址
    int *ptr = arr4;
    arr4[2] = 5;
    *(int *)((char *)ptr + 12) = 6;
    for (int i = 0; i < 5; i++)
        std::cout << arr4[i] << std::endl;
    std::cout << "size arr4=" << sizeof(arr4) << std::endl;
    int sz = sizeof(arr4) / sizeof(int);
    std::cout << "sz arr4=" << sz << std::endl;

    int *arr5 = new int[5];
    for (int i = 0; i < 5; i++)
        arr5[i] = i;
    for (int i = 0; i < 5; i++)
        std::cout << arr5[i] << std::endl;
    std::cout << "size arr5=" << sizeof(arr5) << std::endl;

    delete[] arr5;
    return 0;
}