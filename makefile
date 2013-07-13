net-calc : calculator.c
	gcc -g calculator.c -o net-calc -lm

prefix=/usr/bin

install: net-calc
	install -m 0755 net-calc $(prefix)

.PHONY: install
