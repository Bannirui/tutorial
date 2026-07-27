import torch


# 二维矩阵相乘

def tensor_mm_1() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a @ b
    print(c)


def tensor_mm_2() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = torch.matmul(a, b)
    print(c)


def tensor_mm_3() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = torch.mm(a, b)
    print(c)


def tensor_mm_4() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a.matmul(b)
    print(c)


def tensor_mm_5() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a.mm(b)
    print(c)


def tensor_mm_6() -> None:
    r"""
    高维的矩阵乘法 dim>2
    定义矩阵乘法仅作用在最后的两个维度上 要求前面的维度必须保持一致
    运算操作只有matmul
    """
    a = torch.ones(1, 2, 3, 4)
    b = torch.ones(1, 2, 4, 5)
    print(a.matmul(b))
    print(torch.matmul(a, b))


if __name__ == "__main__":
    # tensor_mm_1()
    # tensor_mm_2()
    # tensor_mm_3()
    # tensor_mm_4()
    # tensor_mm_5()
    tensor_mm_6()
