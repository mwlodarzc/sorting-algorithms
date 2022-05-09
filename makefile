TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++17 -g -iquote inc

${TRGDIR}/a.out: ${OBJ} ${OBJ}/main.o ${OBJ}/MovieRatingDataset.o
	g++ -o ${TRGDIR}/a.out ${OBJ}/main.o ${OBJ}/MovieRatingDataset.o
	
${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/MovieRatingDataset.o: src/MovieRatingDataset.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/MovieRatingDataset.o src/MovieRatingDataset.cpp 

clear:
	rm -r ${OBJ} a.out
