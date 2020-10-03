#!/usr/bin/env python

import os

def create_dir(folder):
	if not os.path.exists(folder):
		os.makedirs(folder)

def move_file(folderName, files):
	for file in files:
		create_dir(folderName)
		os.replace(file, f"{folderName}/{file}")

files = os.listdir()
files.remove("main.py")


imgExts = [".jpg",".png",".jpeg",".svg",".ico",".gif",".webp"]
images = [file for file in files if os.path.splitext(file)[1].lower() in imgExts ]

docExts = [".txt",".docx",".doc",".pdf",".md"]
docs = [file for file in files if os.path.splitext(file)[1].lower() in docExts ]

mediaExts = [".mp3",".mp4",".ogg",".flv",".mkv"]
media = [file for file in files if os.path.splitext(file)[1].lower() in mediaExts ]

archExts = [".zip",".gz",".7z",".rar",".tar"]
archives = [file for file in files if os.path.splitext(file)[1].lower() in archExts ]

codeExts = [".asm",".c",".cpp",".css",".html",".js",".json",".py",".xml",".php",".rb"]
code = [file for file in files if os.path.splitext(file)[1].lower() in codeExts ]


others = []
for file in files:
	ext = os.path.splitext(file)[1].lower()
	if (ext not in imgExts) and (ext not in docExts) and (ext not in mediaExts) and (ext not in archExts) and (ext not in codeExts) and os.path.isfile(file):
		others.append(file)

if __name__=='__main__':
	move_file('Images', images)
	move_file('Docs', docs)
	move_file('Media', media)
	move_file('Archives', archives)
	move_file('Code', code)
	move_file('Others', others)
