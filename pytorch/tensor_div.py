import torch


def tensor_div_1() -> None:
    r"""
    tensora除法
    """
    a = torch.tensor([[1, 2], [3, 4]], dtype=torch.float)
    b = torch.tensor([[5, 6], [7, 8]], dtype=torch.float)
    c = a / b
    print(c)


def tensor_div_2() -> None:
    a = torch.tensor([[1, 2], [3, 4]], dtype=torch.float)
    b = torch.tensor([[5, 6], [7, 8]], dtype=torch.float)
    c = torch.div(a, b)
    print(c)


def tensor_div_3() -> None:
    a = torch.tensor([[1, 2], [3, 4]], dtype=torch.float)
    b = torch.tensor([[5, 6], [7, 8]], dtype=torch.float)
    c = a.div(b)
    print(c)


def tensor_div_4() -> None:
    a = torch.tensor([[1, 2], [3, 4]], dtype=torch.float)
    b = torch.tensor([[5, 6], [7, 8]], dtype=torch.float)
    # a会被修改
    a.div_(b)
    print(a)


if __name__ == "__main__":
    tensor_div_1()
    tensor_div_2()
    tensor_div_3()
    tensor_div_4()
