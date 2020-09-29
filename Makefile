# 最终目标文件
TARGET = test

# 中间文件路径
OBJ_PATH = objs

# 源文件路径
SRCDIR = ./main

# 头文件路径
INCLUDES += -I./ -I./main

# lib库路径
LIBS =

#编译器
CC = gcc
CPP = g++ -std=c++17

G = -g
CFLAGS :=-Wall  -Wno-unknown-pragmas $(G)
LINKFLAGS = 


CPP_SRCDIR = $(SRCDIR)
CPP_SOURCES = $(foreach dir,$(CPP_SRCDIR),$(wildcard $(dir)/*.cpp) )
CPP_OBJS = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(CPP_SOURCES))
CPP_DEPEND = $(patsubst %.cpp, $(OBJ_PATH)/%.d, $(CPP_SOURCES))


default:init compile

$(CPP_OBJS):$(OBJ_PATH)/%.o:%.cpp
	$(CPP) -c $(CFLAGS) $(INCLUDES) $< -o $@



init:subdirs_compile
	$(foreach d,$(SRCDIR), mkdir -p $(OBJ_PATH)/$(d);)

compile:$(CPP_OBJS)
	$(CPP)  $^ -o $(TARGET)  $(LINKFLAGS) $(LIBS)

subdirs_compile:

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(TARGET)