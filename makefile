all:
	g++ main.cpp headers.h Guide.cpp Generation.cpp Routing.cpp Selection.cpp ExtractSVG.cpp
	./a.out
build:
	g++ main.cpp extraccionSVG.cpp headers.h Guide.cpp Generation.cpp Routing.cpp Selection.cpp
