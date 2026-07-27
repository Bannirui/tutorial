import torch

def cmp()->None:
    a = torch.rand(2,3)
    b = torch.rand(2,3)
    print(torch.eq(a,b))
    print(torch.equal(a,b))
    print(torch.gt(a,b))
    print(torch.ge(a,b))
    print(torch.lt(a,b))
    print(torch.le(a,b))
    print(torch.ne(a,b))

if __name__ == '__main__':
    cmp()
