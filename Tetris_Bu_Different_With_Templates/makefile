all:driver1 driver2

driver1:
	@g++ ./driver1file/TetrisAdapter_functions.cpp ./driver1file/TetrisArray1D_functions.cpp ./driver1file/TetrisVector_functions.cpp ./driver1file/tetromino_functions.cpp ./driver1file/driver1.cpp
	@./a.out
	@rm -f *.o
	@rm a.out
driver2:
	@g++ ./driver2file/TetrisAdapter_functions.cpp ./driver2file/TetrisArray1D_functions.cpp ./driver2file/TetrisVector_functions.cpp ./driver2file/tetromino_functions.cpp ./driver2file/driver2.cpp
	@./a.out
	@rm -f *.o
	@rm a.out