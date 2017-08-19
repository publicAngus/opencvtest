comp := g++ 
cflags :=-std=c++11 -c
dir_lib := ./lib
dir_obj_ns_test := ./obj/ns_test
dir_src_ns_test := ./src/ns_test
lib_ns_test := ns_test.a
outFiles := $(patsubst %.cpp,%.o,$(wildcard $(dir_src_ns_test)/*.cpp))
outFiles := $(patsubst $(dir_src_ns_test)/%.o,$(dir_obj_ns_test)/%.o, $(outFiles))
ns_test:$(outFiles)
	echo $(MAKECMDGOALS) $(CURDIR) $(MAKE_VERSION) $(MAKEFILE_LIST) $(VARIABLES)
	ar rvs $(dir_lib)/ns_test.a  $(dir_obj_ns_test)/*
	$(comp) main.cpp $(dir_lib)/$(lib_ns_test) -o main.out
$(dir_obj_ns_test)/%.o:$(dir_src_ns_test)/%.cpp
	${comp} $(cflags) $< -o $@
clean:
	rm ./lib/*
