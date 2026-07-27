import torch


def tensor_attr() -> None:
    r"""
    每个tensor的属性
      dtype
      device 对象创建之后存储在的设备名称
      layout 内存布局 稠密 or 稀疏
    默认创建的是稠密张量
    """
    a = torch.tensor([[1, 2], [3, 4]], dtype=torch.float64, device=torch.device('cpu'))
    print(a)
    # 定义稀疏张量需要指定坐标和值
    i = torch.tensor([[0, 1, 2, 0], [0, 1, 2, 3]])  # 指定稀疏张量非0值的坐标位置
    v = torch.tensor([1, 2, 3, 4])  # 指定稀疏张量上的非0值
    b = torch.sparse_coo_tensor(i, v, (4, 4),
                                dtype=torch.float32,
                                device=torch.device('cpu')
                                ).to_dense()  # 稀疏 稀疏转稠密
    print(b)


if __name__ == "__main__":
    tensor_attr()
