ifeq ($(PROJ),)
PROJ = Elevador_Simulacao
endif

SOURCES_DIR=$(shell find ./src/ -name "*.cpp" -type f)
INCLUDE_DIR := inc
$(shell mkdir -p obj)

OBJ=$(patsubst ./src%, ./obj%, $(patsubst %.cpp, %.o , $(SOURCES_DIR)))
CXXFLAGS= -Wall  -g -Wextra -Wshadow -lSDL -lSDL_ttf $(addprefix -I ,$(INCLUDE_DIR))

all: $(PROJ)

$(PROJ): $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS)

obj/%.o: src/%.cpp
	g++ -c -o $@ $^ $(CXXFLAGS)


run: $(PROJ)
	./$(PROJ) 


run_valgrind:
	valgrind --leak-check=full --track-origins=yes ./$(PROJ) 
	
clean:
	@find . -type f -name "*.o" -exec rm '{}' \;
	@find . -type f -executable -exec rm '{}' \;

remake:
	$(MAKE) clean
	$(MAKE)
