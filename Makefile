################ MAKEFILE TEMPLATE ################                   

# Author : Lucas Carpenter                                            

# Usage : make target1                                                

# What compiler are we using? (gcc, g++, nvcc, etc)                   
LINK = gcc

# Name of our binary executable                                       
OUT_FILE = Sieves

# Any weird flags ( -O2/-O3/-Wno-deprecated-gpu-targets/-fopenmp/etc)
FLAGS = -Wall -fopenmp

all: Sieves

#Rules for compiling into *.o files                                   
%.o: %.c
	$(LINK) $(FLAGS) -c -o $@ $<


#Rules for compiling the Sieves program                          
Sieves: Sieves.o
	$(LINK) $(FLAGS) -o $(OUT_FILE) $^ -lm

clean:
	rm -f *.o *~ core $(OUT_FILE)

