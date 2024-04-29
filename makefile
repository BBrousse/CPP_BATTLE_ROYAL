BUILD=./build
PROG=baston
PROGTEST=baston_test
SRC=./src
# BANK=$(SRC)/bank
MAIN=$(SRC)/main.cpp
SYS=$(SRC)/system
GRID=$(SRC)/grid
CHAR=$(SRC)/character
SHOT=$(CHAR)/shooter
FIGHT=$(CHAR)/fighter
WEAP=$(SRC)/weapon
TEST=$(SRC)/main_test.cpp
LIB=./lib
GTEST=-lgtest -lpthread
LIBDYN=$(LIB)/libbaston.so

O_LIST= $(addsuffix .o, game_core game_grid character character_builder fighter shooter gunner dwarf archer weapon ranged_weapon coordinates)

DEPS= $(addprefix $(BUILD)/, $(O_LIST))

all : $(PROG) $(PROGTEST)

build :
	if ! [ -d $(BUILD) ]; then mkdir $(BUILD); fi

lib :
	if ! [ -d $(LIB) ]; then mkdir $(LIB); fi

$(BUILD)/weapon.o : $(WEAP)/weapon.cpp $(WEAP)/weapon.h
	g++ -c  $(WEAP)/weapon.cpp -o $@

$(BUILD)/ranged_weapon.o : $(WEAP)/ranged_weapon.cpp $(WEAP)/ranged_weapon.h
	g++ -c  $(WEAP)/ranged_weapon.cpp -o $@

$(BUILD)/archer.o : $(SHOT)/archer.cpp $(SHOT)/archer.h
	g++ -c  $(SHOT)/archer.cpp -o $@

$(BUILD)/gunner.o : $(SHOT)/gunner.cpp $(SHOT)/gunner.h
	g++ -c  $(SHOT)/gunner.cpp -o $@

$(BUILD)/shooter.o : $(SHOT)/shooter.cpp $(SHOT)/shooter.h
	g++ -c  $(SHOT)/shooter.cpp -o $@

$(BUILD)/dwarf.o : $(FIGHT)/dwarf.cpp $(FIGHT)/dwarf.h
	g++ -c  $(FIGHT)/dwarf.cpp -o $@

$(BUILD)/fighter.o : $(FIGHT)/fighter.cpp $(FIGHT)/fighter.h
	g++ -c  $(FIGHT)/fighter.cpp -o $@

$(BUILD)/character_builder.o : $(CHAR)/character_builder.cpp $(CHAR)/character_builder.h
	g++ -c  $(CHAR)/character_builder.cpp -o $@

$(BUILD)/character.o : $(CHAR)/character.cpp $(CHAR)/character.h
	g++ -c  $(CHAR)/character.cpp -o $@

$(BUILD)/coordinates.o : $(GRID)/coordinates.cpp $(GRID)/coordinates.h
	g++ -c  $(GRID)/coordinates.cpp -o $@

$(BUILD)/game_grid.o : $(GRID)/game_grid.cpp $(GRID)/game_grid.h
	g++ -c  $(GRID)/game_grid.cpp -o $@

$(BUILD)/game_core.o : $(SYS)/game_core.cpp $(SYS)/game_core.h
	g++ -c  $(SYS)/game_core.cpp -o $@



$(LIBDYN): lib build $(DEPS) 
	g++ $(DEPS) -shared -fPIC -o $@
	

so : $(LIBDYN)

$(PROGTEST): $(TEST) build lib $(LIBDYN) o_clean
		g++ $(TEST) $(LIBDYN) $(GTEST) -o $@

test: $(PROGTEST)

$(PROG): $(MAIN) build lib $(LIBDYN) o_clean
	g++ $(MAIN) $(LIBDYN) -o $@

exe : $(PROG)





rebuild: clean all

lib_clean:
	rm -rf $(LIB)

o_clean :
	rm -rf $(BUILD)

clean : lib_clean o_clean
	rm $(PROG)


