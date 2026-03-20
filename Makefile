CXX      = g++
CXXFLAGS = -Wall -std=c++11 -I. -I./Bestioles -I./CapteursEtAccessoires -I./Comportements -I./Creation -I./Observation  -I./Simulation -I./Visitor -I./Lib

SRCS = main.cpp \
       Bestioles/Bestiole.cpp \
	   CapteursEtAccessoires/DecCamouflage.cpp \
	   CapteursEtAccessoires/DecCarapace.cpp \
	   CapteursEtAccessoires/DecYeux.cpp \
       Simulation/Milieu.cpp \
       Simulation/Aquarium.cpp \
	   Comportements/Gregaire.cpp \
	   Creation/ConfigurationPopulation.cpp \
	   Creation/BestioleFactory.cpp \
	   Observation/JournalSimulation.cpp 

OBJS = $(SRCS:.cpp=.o)

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS) -lX11 -lpthread

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) main