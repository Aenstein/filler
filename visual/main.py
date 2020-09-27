#!/usr/local/bin/python3

from tkinter import *
import sys
from time import sleep, time


clr_pl1 = '#E20048'
clr_pl1_bfr = '#F16C97'
clr_pl2 = '#510FAD'
clr_pl2_bfr = '#976BD6'
clr_tkn = '#aaffaa'

try:
	buf = input()
except EOFError:
	print("Not valid file")
	exit()

while buf.find("Plateau") == -1:
	if buf.find("p1") != -1:
		mas = buf.split('/')
		player1 = mas[len(mas) - 1].split('.')[0]
	if buf.find("p2") != -1:
		mas = buf.split('/')
		player2 = mas[len(mas) - 1].split('.')[0]
	buf = input()

width_board = int(buf.split(' ')[2].split(':')[0])
height_board = int(buf.split(' ')[1])

maps = []
tokens = []
while 1:
	try:
		lines = []
		buf = input()
		for i in range(height_board):
			buf = input()
			lines.append(buf.split(' ')[1])
		maps.append(lines)
		buf = input()
		try:
			y = int(buf.split(' ')[1])
		except ValueError:
			break
		lines = []
		for i in range(y):
			buf = input()
			lines.append(buf)
		tokens.append(lines)
		while buf.find("Plateau") == -1:
			buf = input()
	except EOFError:
		break

w_map = 900
h_map = 800
sq = int(w_map / max(height_board, width_board))

window = Tk()
window.title("Filler")
window.geometry('1400x1400+800+300')
Label(window, text=player1, bg=clr_pl1).place(x=10, y=10, width=100, height=20)
Label(window, text=player2, bg=clr_pl2).place(x=100, y=10, width=100, height=20)
b1 = Button(text="Start", width=10, height=3)

def draw_filler(c, filler, x0, y0, sq):
	for j in range(len(filler)):
		for i in range(len(filler[j])):
			if filler[j][i] == 'O':
				c.create_rectangle(x0 + i * sq, y0 + j * sq, x0 + sq * (i + 1), y0 + sq * (j + 1), fill=clr_pl1, width=1)
			elif filler[j][i] == 'o':
				c.create_rectangle(x0 + i * sq, y0 + j * sq, x0 + sq * (i + 1), y0 + sq * (j + 1), fill=clr_pl1_bfr, width=1)
			elif filler[j][i] == 'X':
				c.create_rectangle(x0 + i * sq, y0 + j * sq, x0 + sq * (i + 1), y0 + sq * (j + 1), fill=clr_pl2, width=1)
			elif filler[j][i] == 'x':
				c.create_rectangle(x0 + i * sq, y0 + j * sq, x0 + sq * (i + 1), y0 + sq * (j + 1), fill=clr_pl2_bfr, width=1)
			elif filler[j][i] == '.':
				c.create_rectangle(x0 + i * sq, y0 + j * sq, x0 + sq * (i + 1), y0 + sq * (j + 1), fill='#E5FB71', outline='black', width=1)
			elif filler[j][i] == '*':
				c.create_rectangle(x0 + i * sq, y0 + j * sq, x0 + sq * (i + 1), y0 + sq * (j + 1), fill='#A101A6', width=1)

def change():
	c = Canvas(window, width=2000, height=2000, bg='white')
	c.place(y=80)
	for k in range(1, len(maps)):
		c.delete("all")
		draw_filler(c, maps[k], 10, 10, sq)
		try:
			draw_filler(c, tokens[k + 1], w_map + 10, 10, sq)
		except IndexError:
			draw_filler(c, tokens[k], w_map + 10, 10, sq)	
		c.update()
		sleep(0.05)

b1.config(command=change)
b1.place(x=500)

c = Canvas(window, width=2000, height=2000, bg='white')
c.place(y=80)
for j in range(len(maps[0])):
	for i in range(len(maps[0][j])):
		if maps[0][j][i] == 'O':
			c.create_rectangle(10 + i * sq, 10 + j * sq,\
					10 + sq * (i + 1), 10 + sq * (j + 1), fill=clr_pl1, width=1)
		elif maps[0][j][i] == 'X':
			c.create_rectangle(10 + i * sq, 10 + j * sq,\
					10 + sq * (i + 1), 10 + sq * (j + 1), fill=clr_pl2, width=1)
		elif maps[0][j][i] == '.':
			c.create_rectangle(10 + i * sq, 10 + j * sq,\
					10 + sq * (i + 1), 10 + sq * (j + 1), fill='#E5FB71', outline='black', width=1)

window.mainloop()