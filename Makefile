OBJECTS = libFsm.a
CFLAGS = 
CXXFLAGS = -fPIC
ASMFLAGS =
CC = g++
AS = g++
AR = ar
LD = ld
LIBS = 
LIBPATH = 
INCLUDEPATH := -I State -I Transition -I.
SRCS := $(wildcard *.cpp ./Transition/*.cpp ./State/*.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

$(OBJECTS) : $(OBJS)
	$(AR) rcs $@ $<

$(OBJS) : %.o : %.cpp
	$(CC) -c -g $(INCLUDEPATH) $<

#安装已编译好的程序
.PHONY : install 
install :

#列出改变过的文件
.PHONY : print
print :

#源程序打包备份
.PHONY : tar
tar :

#创建一个压缩文件
.PHONY : dist
dist :

#更新所有目标
.PHONY : TAGS
TAGS :

#测试流程
.PHONY : check
check :


#清理文件
.PHONY : clean
clean :
	rm -f *.o $(OBJECTS)

