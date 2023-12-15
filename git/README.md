git教程
---

- `git commit --amend -m '提交注释'` 修改最近一次commit注释

- `git merge 分支名` master分支落后，dev分支靠前，二者不冲突，master可以通过merge直接追赶dev，成为`fast forward`。本质是分支指针的移动，中间跳过的commit会被保存，`git merge`默认使用的是`fast fast forward`

  - 两个分支fast forward，归于一点commit

  - 没有分支信息，丢失分支信息

- `git merge 分支名 --no-ff`

  - 两个分支fast forward，不会归于一点commit，主动合并的分支会前进一步

  - 分支信息完整，不会丢失分支信息

- `git log --graph` 显示分支信息

- `git log --graph --pretty=oneline --abbrev-commit` 简化提交信息

- `commit -am '提交注释'` 合并add和commit两步

- 版本穿梭

  - `git reset --hard HEAD^` 回退到上一次

  - `git reset --hard HEAD^^` 回退到上两次

  - `git reset --hard HEAD~n` 回退到n次前

  - `git reset --hard sha1值的前几位即可` 根据sha1值回退到任意次

  - `git reflog` 所有的提交，查到想要的sha1值，借助`git reset --hard sha1值`可以达到后悔版本回退的效果

  - `git checkout sha1值` 也可以穿越回去，处于游离状态

    - 修改后必须提交

    - 创建分支的好时机，因为在过去改了东西，未来无法感知，所以创建个分支`git branch 新分支名 sha1值`

- `checkout` 放弃修改

  - 当前在暂存区中，执行`git checkout 文件名`就是放弃工作区中的修改

- `reset` 当前在暂存区中，执行`git reset HEAD 文件名`可以将之前从工作区加到暂存区中的内容回退到工作区

- `git branch -m 分支名 新分支名` 修改分支名

- `stash`保存现场
  
  - 建议 在功能未开发完毕之前不要commit

  - 规定 在没commit之前不能checkout

    - 如果两个分支的commit是一样的 可以随便checkout

    - 如果两个分支的commit不一样 不要checkout

- `git stash` 将当前分支临时保存，然后可以切换到别的分支干活，之后再回来当前分支

  - `git stash` 保存的stash名字是随机值

  - `git stash save "给stash起个名字"` 便于根据名字找到stash

  - `git stash list`

  - `git stash pop` 还原现场，并且把临时文件删除

  - `git stash apply` 还原现场，保存临时文件不删除

  - `git stash drop stash名字` 手动删除某个stash

- tag标签 基于整个项目，和分支没有关系，在分支1中打tag，在分支2中也能看到tag

  - `git tag 标签名称`

  - `git tag -a 标签名称 -m "注释信息"`

  - `git tag`查看

  - `git tag -d 标签名称`删除

- `git diff`比较的是区中的文件

  - `git diff`比较暂存区和工作区中的差异

  - `git diff commit的sha1值`比较对象区和工作区的差异

  - `git diff 最新的commit的sha1值`比较对象区最新的commit和工作区的差异

  - `git diff head`比较对象区最新的commit和工作区的差异

  - `git diff --cached sha1值`比较对象区和暂存区

  - `git diff --cached HEAD`比较最新的对象区和暂存区