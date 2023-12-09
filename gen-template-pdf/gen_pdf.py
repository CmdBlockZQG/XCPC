#! /usr/bin/python3
import os

res = ""

def walk(path, dep):
	subdir = []
	for i in sorted(os.listdir(path)):
		if i[0] == '_':
			continue
		title = i[i.find('#') + 1:]
		t = title.rfind('.')
		if t != -1:
			title = title[:t]
		path_i = path + '/' + i
		global res
		res += '=' * dep + ' ' + title + '\n'
		if os.path.isfile(path_i):
			if i.find(".typ") != -1:
				res += '#include "%s"\n' % path_i
			else:
				res += '#code(read("%s"))\n' % path_i
		else:
			walk(path_i, dep + 1)

if __name__ == "__main__":
	walk("../code-template", 1)
	template = ""
	with open("template.typ", "r") as f:
		template = f.read()
	with open("main.typ", "w") as f:
		f.write(template + '\n' + res)
	os.system("./typst compile ./main.typ --root ../")
	# os.system("./typst.exe compile ./main.typ --root ../") # Windows
