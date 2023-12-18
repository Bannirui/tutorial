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

- `git commit -am '提交注释'` 合并add和commit两步

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

- `git push -u origin master` 首次推送，之后`git push`即可

- `git remote show` 查看远程分布式服务器列表

- `git remote show origin` 查看远程分支

- `git branch -av` 本地远程分支的commit对比

- `git clone repo地址 自定义项目名`或者`git clone repo地址`

- pull = fetch + merge

- `git log origin/master`或者`git log refs/remotes/origin/master` 查看远端master

- 分支关联

  - 本地有分支 远程没有分支
  
    - git push -u origin 分支名

    - git push --set-upstream origin 分支名

  - 本地没有分支 远程有分支

    - `git pull`将远程分支更新到追踪分支，然后追踪分支更新到本地分支

      - `git checkout -b 分支名 origin/分支名`

      - `git checkout -b --track origin/分支名`
  
    - `git pull origin 远程分支名:本地分支名`

- 删除远程分支

  - `git push origin :远程分支名`

  - `git push origin --delete 分支名`

- 删除没有用处的追踪分支

  - `git remote prune origin --dry-run`检测没有使用的追踪分支

  - `git remote prune origin`清理无效的追踪分支

- `git push origin --tags`将标签推送远程

- `git fetch origin tag 远程标签名`

- `git push origin :refs/tags/远程标签名`删除远程标签

- submodule

  - `git submodule add repo地址`

  - pull

    - 进入到子模块目录执行`git pull`

    - 所有子模块迭代pull`git submodule foreach git pull`

  - `git clone repo地址 --recursive`

  - 删除

    - `git rm --cached 模块名`删除暂存区

    - 删除工作区

      - `rm -rf 模块名`

      - `rm -rf .gitmodules`

    - 删除对象区

      - `git -am '删除对象区'`

      - `git push`

- submodule是单向操作

- subtree是双向操作

- subtree

  - `git remote add subtree-origin repo地址`远程地址别名

  - 远程master分支加到工程`git subtree add -P 本地subtree名 subree-origin master`

  - 更新`git subtree pull -P 子模块 subtree-origin master`

  - 在父工程子模块修改推送到子工程`git subtree push -P subtree-origin master`

- cherry-pick使用场景是转移分支的提交

  - `git checkout 分支`切到目标分支

  - `git cherry-pick sha1值`将commit提交复制过来

- 变基(衍合)

  - rebase会改变历史提交线

  - rebase之后的提交线路是一条直线

  - 冲突

    - 解决冲突后提交`git add .`, 继续rebase`git rebase --continue`

    - 忽略冲突`git rebase --skip`

  - 终止rebase，还原rebase之前的场景`git rebase --abort`

  - 最好只在本地分支rebase

  - 不要在master分支上rebase

  - 在dev分支上`git rebase master`