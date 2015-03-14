cpps = main.cpp
hs = 
run = cam
com = g++ `pkg-config --cflags opencv` $(cpps) -o $(run) `pkg-config --libs opencv`
comp: $(cpps) $(hs)
	$(com)
run: cam
	./$(run)
compRun: main.cpp
	$(com)
	./$(run)

CFLAGS+=`pkg-config --cflags opencv`
LDFLAGS+=`pkg-config --libs opencv`
