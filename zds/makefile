
#OBJS specifies which files to compile as part of the project 
OBJS = main.cpp Game.cpp Log.cpp
#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
COMPILER_FLAGS = -w 

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lSDL2 -lSDL2_image -L/usr/include/lua5.1/include -L/usr/include/lua5.1/lib -I/usr/include/lua5.1/ -Lllua

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = zds 

#This is the target that compiles our executable 
all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) 
