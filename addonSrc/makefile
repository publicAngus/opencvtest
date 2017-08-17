comp := g++ -std=c++11 -c
dir_lib := ./lib
dir_obj_ns_test := ./obj/ns_test
dir_src_ns_test := ./src/ns_test
outFiles := $(patsubst %.cpp,%.o,$(wildcard $(dir_src_ns_test)/*.cpp))
outFiles := $(patsubst $(dir_src_ns_test)/%.o,$(dir_obj_ns_test)/%.o, $(outFiles))
ns_test:$(outFiles)
	ar rvs $(dir_lib)/ns_test.a  $(dir_obj_ns_test)/*
$(dir_obj_ns_test)/%.o:$(dir_src_ns_test)/%.cpp
	${comp} $< -o $@
clean:
	rm ./lib/*
