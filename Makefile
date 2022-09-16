#/*
#Author: Justin Wong
#Course: CSCI-135
#Instructor: Mr. Zamansky
#Assignment: Lab4 Makefile
#
#The make file for lab 3 
#
#
main: main.o reservoir.o reverseorder.o
	g++ -o main main.o reservoir.o reverseorder.o

main.o: main.cpp reservoir.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp

reverseorder.o: reverseorder.cpp reverseorder.h
	g++ -c reverseorder.cpp
clean:
	rm -f main.o reservoir.o reverseorder.o

