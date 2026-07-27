import torch
from torch.utils.data import Dataset
import os
from PIL import Image
from pathlib import Path
from matplotlib import pyplot as plt


class MyData(Dataset):
    root: Path  # 数据源的绝对路径
    files: list[Path]  # 目录下的目录项对应的绝对路径 也就是图片的路径

    def __init__(self, root: str) -> None:
        r"""
        :param root: 数据集目录
        """
        self.root = Path(root)
        # 只要路径下的文件 不要目录项
        self.files = [p for p in self.root.iterdir() if p.is_file()]

    def __getitem__(self, index):
        r"""
        根据索引拿到一张图片
        :param index: 图片的索引
        :return: (图片对象 图片标签)
        """
        # 图片路径
        img_path = self.files[index]
        # 打开图片
        with Image.open(img_path) as img:
            img = img.convert("RGB")
        return img, img_path.name

    def __len__(self):
        # 多少个图片
        return len(self.files)


if __name__ == '__main__':
    ant_dataset = MyData("asset/train/ants_image")
    print(f'数据集大小{len(ant_dataset)}个图片')

    img, label = ant_dataset[0]
    print(f'标签是{label}\n图片大小{img.size}\n图片模式{img.mode}')
    # 显示图片
    plt.imshow(img)
    plt.axis('off')
    plt.show()
