LIBS=-L./lib -lxml2 /users/ems/open2000e/lib/libodb_apiall_lib.so -L/users/ems/open2000e/lib/

INCPATH=-I/users/ems/wd_file_console/include/libxml2 -I/users/ems/wd_file_console/db_api -I/usr/local/corba/include

d:ServerTest.o Data.o
	g++ -m32 -o wd ServerTest.o Data.o $(LIBS) -L. 

ServerTest.o:ServerTest.cpp Data.h
	g++ -m32 -o ServerTest.o -c $(INCPATH) ServerTest.cpp -c

Data.o:Data.cpp Data.h 
	g++ -m32 -c $(INCPATH) Data.cpp -o Data.o

clean:
	rm wd *.o
