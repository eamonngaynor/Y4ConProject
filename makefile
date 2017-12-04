# Conleth Coughlan 
# C00197482
#
# Eamonn Gaynor
#C00197458
#
# Wator simulator
# CDDProject

cc=g++
cflags= -std=c++11  *.cpp -o wator
cfiles= wator.cpp 
all: $(cfiles)
	$(cc) $(cflags) 
