LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.o Funzioni.o RandomGen.o IntegrazioneMC.o 
	g++ main.o Funzioni.o RandomGen.o IntegrazioneMC.o -o main ${INCS} ${LIBS}

main.o: main.cxx Funzioni.h RandomGen.h IntegrazioneMC.h statistica.h
	g++ -c main.cxx -o main.o ${INCS} ${LIBS}

Funzioni.o: Funzioni.cxx Funzioni.h
	g++ -c Funzioni.cxx -o Funzioni.o

RandomGen.o: RandomGen.cxx RandomGen.h Funzioni.h
	g++ -c RandomGen.cxx -o RandomGen.o

IntegrazioneMC.o: IntegrazioneMC.cxx IntegrazioneMC.h Funzioni.h RandomGen.h
	g++ -c IntegrazioneMC.cxx -o IntegrazioneMC.o
	
clear:
	rm main


