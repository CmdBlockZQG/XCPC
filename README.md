# CmdBlock's XCPC Repo

## 自动生成代码模板

### Usage
切换当前目录到`gen-template-pdf`下，直接运行`./gen_pdf.py`（或`python3 gen_pdf.py`）就会生成`main.pdf`

可能需要为`typst`程序添加可执行权限，非windows系统可自行下载typst官方的cli工具替换（或者你想要更新或者你不信任我的版本）。可能还要改一下py脚本（比如windows加个.exe这种）

### 生成机制
递归遍历`code-template`的目录树，根据文件夹名和文件名生成各级标题
- 文件名由下划线`_`开头的文件会被忽略
- 顺序按照字典序
- 文件名开头直到第一个`#`的部分不会出现在标题中（这是用来帮助手动排序的）
- 文件名的拓展名也不会出现在标题中
- 拓展名为`.typ`的文件会被渲染，其他的会作为代码块

### 渲染模板
`template.typ`可以自己改改