import torch

def sort()->None:
    a = torch.tensor([[1,4,3,5,4],
                      [3,5,9,2,0]])
    print(a.shape)
    print(torch.sort(a,dim=1,descending=False))

def top_k()->None:
    a = torch.tensor([[1,4,3,5,4],
                      [3,5,9,2,0]])
    print(a.shape)
    print(torch.topk(a,dim=0,k=1))


def k_th()->None:
    a = torch.tensor([[1,4,3,5,4],
                      [3,5,9,2,0]])
    print(a.shape)
    print(torch.kthvalue(a,dim=0,k=1))

if __name__ == '__main__':
    #sort()
    #top_k()
    k_th()
