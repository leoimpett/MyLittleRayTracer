all: firstShader basicShader eigenShader

firstShader:
	g++ firstShader.cpp -o firstShader

basicShader: eigenShader.cpp
	g++ basicShader.cpp -o basicShader

eigenShader: eigenShader.cpp
	g++ -I ./eigen/ eigenShader.cpp  -o eigenShader
