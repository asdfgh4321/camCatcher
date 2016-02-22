cpps = mysql.cpp
sqlFlags = -I/usr/local/include -I/usr/local/include/cppconn -lmysqlcppconn
run = test
comps = g++ -o $(run) $(sqlFlags) $(cpps)

comp: $(cpps)
	$(comps)