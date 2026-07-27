import torch


# 开方运算
def tensor_sqrt() -> None:
    a = torch.ones(1, 2)
    print(a.sqrt())
    print(a.sqrt_())
    print(a)


if __name__ == "__main__":
    tensor_sqrt()
