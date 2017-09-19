comp := g++ 
cflags :=-std=c++11 -c -fPIC
dir_lib := ./lib
dir_obj_ns_test := ./obj/ns_test
dir_src_ns_test := ./src/ns_test
lib_ns_test := ns_test.a
outFiles := $(patsubst %.cpp,%.o,$(wildcard $(dir_src_ns_test)/*.cpp))
outFiles := $(patsubst $(dir_src_ns_test)/%.o,$(dir_obj_ns_test)/%.o, $(outFiles))

test:
	@echo $(outFiles)
	@echo $(MAKECMDGOALS) $(CURDIR) $(MAKE_VERSION) $(MAKEFILE_LIST) $(VARIABLES)
	@echo `pkg-config --cflags --libs opencv3`
ns_test:$(outFiles)
	ar rvs $(dir_lib)/ns_test.a  $(dir_obj_ns_test)/*
	$(comp) -std=c++11 main.cpp $(dir_lib)/$(lib_ns_test) `pkg-config --cflags --libs opencv3` -o main.out
$(dir_obj_ns_test)/%.o:$(dir_src_ns_test)/%.cpp $(dir_src_ns_test)/%.hpp
	${comp} $(cflags) `pkg-config --cflags --libs opencv3` $< -o $@
clean:
	rm -f ./lib/*
	rm -f ./obj/ns_test/*
