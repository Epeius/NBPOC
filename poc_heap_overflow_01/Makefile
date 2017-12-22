export AFL_USE_ASAN=1
export ASAN_OPTIONS=symbolize=1

#CXX ?= g++
CXX = /home/binzhang/afl/afl-clang-fast++


CXXFLAGS += -fsanitize=address -ggdb  -g  -O0  -static -c -Wall  $(shell pkg-config --cflags /home/binzhang/fuzz/target/opencv-clang-install/lib/pkgconfig/opencv.pc)
LDFLAGS += $(shell pkg-config --libs --static /home/binzhang/fuzz/target/opencv-clang-install/lib/pkgconfig/opencv.pc)

all: for_submit

for_submit: for_submit.o;  $(CXX) $< -o $@ $(LDFLAGS)

%.o: %.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean:  
	rm -f for_submit for_submit.o

