import torch


def tensor_add_1() -> None:
    r"""
    tensor加法
    """
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a + b
    print(c)


def tensor_add_2() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = torch.add(a, b)
    print(c)


def tensor_add_3() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    c = a.add(b)
    print(c)


def tensor_add_4() -> None:
    a = torch.tensor([[1, 2], [3, 4]])
    b = torch.tensor([[5, 6], [7, 8]])
    # a会被修改
    a.add_(b)
    print(a)


if __name__ == "__main__":
    # tensor_add_1()
    # tensor_add_2()
    # tensor_add_3()
    tensor_add_4()
