cpps = main.cpp
run = /media/disk1/Dropbox/cam
CFLAGS=`pkg-config --cflags opencv`
LDFLAGS=`pkg-config --libs opencv`
SFFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -std=c++0x
com = g++ $(CFLAGS) $(cpps) -o $(run) $(SFFLAGS) $(LDFLAGS)


comp: $(cpps) $(hs)
	$(com)
compArun: $(run)
	$(com)
	./$(run)