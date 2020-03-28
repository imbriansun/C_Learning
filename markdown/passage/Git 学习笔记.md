# Git 学习笔记

1. **Linux 下安装 Git** ：`sudo apt-get install git`

2. **配置Git用户名&email地址**：

   `` git config --global user.name "Your Name"`` 

   `git config --global user.email "email@example.com"`

   （Tip：git config 命令的 --global 参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。）

3. **创建版本库**

   创建一个文件夹(任意名称，这里我叫做mygit），并将这个文件夹初始化为Git仓库

   `mkdir mygit`

   `cd mygit`

   `git init`		<!--初始化mygit成为版本库（git可以管理的仓库）-->

   

   ***Tip：***

   *此处打开mygit文件夹查看是空空如也的，但使用`ls -a`是可以查看到此处有一个'.git'的隐藏文件夹的。*

   *在git 克隆代码之后，还不能直接使用git，而需要初始化git，它会自动创建git仓库需要的目录。这些文件存在于项目下的.git文件夹下。*

    .git文件夹是git init后在当前目录生成的**一个管理git仓库的文件夹**，这里包含所有git操作所需要的东西，

   *[转载：.git文件夹详解](https://blog.csdn.net/mayfla/article/details/78653396)*

   下图的版本库即为我们的.git文件夹下的内容

   ![git-repo](https://www.liaoxuefeng.com/files/attachments/919020037470528/0)

4. **正式使用Git：**

   创建文件后，想将文件添加到Git仓库，分两步：

   `git add 文件名`　　将本地仓库的文件提交到git的**暂存区(stage/index)** 

   `git commit -m “本次提交的说明”`　　将暂存的所有文件提交到版本库的当前分支

   ***Tip.***

   *使用命令`git status`可以查看当前处理文件所在状态*

   *多次修改可以用`git diff 文件名`查看版本间内容差异 (前提是没有提交到版本库过一次)*

5. **版本回退：**

   Git允许我们在版本的历史之间穿梭，使用命令`git reset --hard commit_id`

   关于commit_id：

   `HEAD`表示当前版本

   `HEAD^`表示上一版本

   `HEAD^^`表示上上一版本

   `HEAD～20`表示回退到倒数第20个版本

   `324ea...`像这样的一串16进制数

   均可以用以上代码替换commit_id，以回到想回到文件版本。

   ***Tip.***

   *这里可以使用`git log`查看提交历史的记录，以便确定要回退到哪个版本*

   *`git reflog`查看使用的命令历史记录，当在历史版本情况下，想返回当时在未来某时刻的版本，可使用这个命令来查看到那时的commit_id*

   

6. **git三区**

   工作区，暂存区（stage/index)，历史记录区

   ![git-repo](https://www.liaoxuefeng.com/files/attachments/919020037470528/0)

7. **撤销修改**：

   命令`git checkout -- readme.txt`意思就是，把`readme.txt`文件**在工作区的修改**全部撤销，这里有两种情况：

   一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

   一种是`readme.txt`已经添加到暂存区后，又作了修改，现在，撤销修改就让工作区的readme.txt回到添加到暂存区的状态。

   总之，就是让工作区的这个文件回到最近一次`git commit`或`git add`时的状态。

   

   若是修改了readme.txt并且已经git add了但没有commit

   `git reset HEAD readme.txt`可以把暂存区的修改撤销掉（unstage），重新放回工作区

   （`git reset`命令既可以回退版本，也可以**把暂存区的修改回退到工作区**。当我们用`HEAD`时，表示最新的     版本。）

   此时再使用`git reset HEAD <file>`来将readme.txt回退到上一次commit时的版本

   

   **SUM：**

   **场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- file`。**

   **场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD <file>`，就回到了场景1，第二步按场景1操作。**

   **场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考 版本回退 ，不过前提是没有推送到远程库。**

8. **删除文件**

   使用`rm readme.txt`删除工作区的readme.txt文件

   之前有在版本库提交过readme.txt，因此要同步地在版本库中删除该文件，

   使用`git rm readme.txt`   `git commit -m "xxx"`来同步操作

   -->万一删错了怎么办？可以使用`git checkout -- readme.txt`来在工作区恢复文件（该文件版本即版本库中文件）tip：从来没有被添加到版本库就被删除的文件，是无法恢复的！