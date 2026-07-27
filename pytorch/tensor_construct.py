import torch


def create_tensor() -> None:
    r"""
    创建tensor
    """
    # 直接用值初始化
    a = torch.Tensor([[1, 2], [3, 4]])
    print(a)
    print(a.type())
    # 指定形状 里面的值都是随机的
    b = torch.Tensor(2, 3)
    print(b)
    print(b.type())
    # 值都是1
    c = torch.ones(2, 3)
    print(c)
    print(c.type())
    # 值都是0
    d = torch.zeros(2, 3)
    print(d)
    print(d.type())
    # 对角线是1 其他是0
    e = torch.eye(2, 3)
    print(e)
    print(e.type())
    # 跟某个tensor形状一样 值都是0
    f = torch.zeros_like(a)
    print(f)
    print(f.type())
    # 随机
    g = torch.rand(2, 3)
    print(g)
    print(g.type())
    # 正态分布
    h = torch.normal(mean=0.0, std=torch.rand(5))
    print(h)
    print(h.type())
    i = torch.normal(mean=torch.rand(5), std=torch.rand(5))
    print(i)
    print(i.type())
    # 均匀分布
    j = torch.Tensor(2, 3).uniform_(-1, 1)
    print(j)
    print(j.type())
    # 序列 [n1...n2)左闭右开
    k = torch.arange(0, 10, 2)
    print(k)
    print(k.type())
    # [m...n]等差数列i个数字
    l = torch.linspace(2, 10, 4)
    print(l)
    print(l.type())


if __name__ == "__main__":
    create_tensor()
