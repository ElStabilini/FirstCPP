LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.o Funzioni.o Integral.o IntegraliMC.o RandomGen.o
	g++ main.o Funzioni.o Integral.o IntegraliMC.o RandomGen.o -o main ${INCS} ${LIBS}

main.o: main.cxx Funzioni.h Integral.h IntegraliMC.h RandomGen.h
	g++ -c main.cxx -o main.o ${INCS} ${LIBS}

Funzioni.o: Funzioni.cxx Funzioni.h
	g++ -c Funzioni.cxx -o Funzioni.o

Integral.o: Integral.cxx Integral.h Funzioni.h IntegraliMC.h
	g++ -c Integral.cxx -o Integral.o

RandomGen.o: RandomGen.cxx RandomGen.h Funzioni.h
	g++ -c RandomGen.cxx -o RandomGen.o

IntegraliMC.o: IntegraliMC.cxx IntegraliMC.h Funzioni.h RandomGen.h statistica.h
	g++ -c IntegraliMC.cxx -o IntegraliMC.o
	
clear:
	rm main
