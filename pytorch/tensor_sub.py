import torch


def tensor_sub_1() -> None:
    r"""
    tensor减法
    """
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a - b
    print(c)


def tensor_sub_2() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = torch.sub(a, b)
    print(c)


def tensor_sub_3() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a.sub(b)
    print(c)


def tensor_sub_4() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    # a会被修改
    a.sub_(b)
    print(a)


if __name__ == "__main__":
    # tensor_sub_1()
    # tensor_sub_2()
    # tensor_sub_3()
    tensor_sub_4()
