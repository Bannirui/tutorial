import torch


# tensor的乘法运算是对应的元素相乘 叫哈达玛积

def tensor_mul_1() -> None:
    r"""
    tensora乘法
    """
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a * b
    print(c)


def tensor_mul_2() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = torch.mul(a, b)
    print(c)


def tensor_mul_3() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a.mul(b)
    print(c)


def tensor_mul_4() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    # a会被修改
    a.mul_(b)
    print(a)


if __name__ == "__main__":
    tensor_mul_1()
    tensor_mul_2()
    tensor_mul_3()
    tensor_mul_4()
