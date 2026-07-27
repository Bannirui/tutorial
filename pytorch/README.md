LEARN PYTORCH
---

### 1 HOST ENV

verify the cuda version requirement in advance

```sh
nvidia-smi
```

and my GPU is GeForce MX150, and the cuda version is 12.2

### 2 INSTALL PYTORCH

#### 2.1 python virtual env

```sh
python3 -m venv .venv
```


#### 2.2 pytorch

then activate above py venv and install bellow packages:

```sh
pip install torch torchversion --index-url https://download.pytorch.org/whl/cuda126
```
