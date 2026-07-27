LEARN PYTORCH
---

### 1 PRE-REQUIREMENT

#### 1.1 WITH CUDA

```sh
nvidia-smi

python3 -m venv .venv

pip install torch torchversion --index-url https://download.pytorch.org/whl/cuda126
```

#### 1.2 NO CUDA


```sh
python3 -m venv .venv

pip install torch torchvision torchaudio matplotlib

pip freeze > requirements.txt
```

### 2 Tensor

- [怎么定义tensor](./tensor_construct.py)
- [tensor有哪些属性](./tensor_attr.py)
- tensor的算数运算
    - [加](./tensor_add.py)
    - [减](./tensor_sub.py)
    - [点乘](./tensor_mul.py)
    - [除](./tensor_div.py)
    - [矩阵乘法](./tensor_mm.py)
    - [幂方](./tensor_pow.py)
    - [开方](./tensor_sqrt.py)

in place操作 就地操作 不允许使用临时变量 也称为原位操作 add_ sub_ mul_

广播机制 张量计算时参数不对齐 自动扩展为相同大小
广播机制需要满足2个条件
- 每个张量至少有一个维度
- 满足右对齐性质
  - 其中有个1
  - 两个相等
