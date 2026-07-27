import torch


# 幂运算 n次方
def tensor_pow() -> None:
    a = torch.ones(1, 2)
    print(torch.pow(a, 2))
    print(a.pow(2))
    print(a ** 2)
    print(a.pow(2))


if __name__ == "__main__":
    tensor_pow()
