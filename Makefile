prog:*.h *.c
	gcc *.h *.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm  -o prog -g 
jeu.o:anim.c
	gcc -c anim.c -g


