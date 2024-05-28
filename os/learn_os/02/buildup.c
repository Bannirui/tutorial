#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd, fd_kernel;
    int c;
    char buf[512];

    // 多个可执行文件整合到一个可执行文件中
    // 程序部分      部署位置    kvmtool的启动地址  各部分程序在整个可执行程序的相对偏移位置，就是相对16位实模式部分程序的第一条指令偏移地址
    // 16实模式      0x10000    0x10000          0x10000-0x10000
    // 32位保护模式   0x20000                     0x20000-0x10000
    // 64位模式      0x100000                    0x100000-0x10000
    fd_kernel = open("kernel.bin", O_WRONLY | O_CREAT, 0664);

    // 拷贝boot16
    fd = open("boot16.bin", O_RDONLY);
    while (1)
    {
        c = read(fd, buf, 512);
        if (c > 0)
        {
            write(fd_kernel, buf, c);
        }
        else
        {
            break;
        }
    }
    close(fd);

    // 拷贝boot32
    // 重置读写位置
    lseek(fd_kernel, 0x20000 - 0x10000, SEEK_SET);
    fd = open("boot32.bin", O_RDONLY);
    while (1)
    {
        c = read(fd, buf, 512);
        if (c > 0)
        {
            write(fd_kernel, buf, c);
        }
        else
        {
            break;
        }
    }
    close(fd);

	// 拷贝boot64
	// 重置读写位置
	lseek(fd_kernel, 0x100000 - 0x10000, SEEK_SET);
	fd = open("system.bin", O_RDONLY);
	while (1)
	{
		c = read(fd, buf, 512);
		if (c > 0)
		{
			write(fd_kernel, buf, c);
		}
		else
		{
			break;
		}
	}
	close(fd);

    close(fd_kernel);
    return 0;
}