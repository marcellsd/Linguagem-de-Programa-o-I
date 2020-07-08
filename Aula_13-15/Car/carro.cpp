#include "carro.hpp"

int Carro::numeroDeCarros;

Carro::Carro(string cor_, string tipo_, int numPortas_){
    this->cor = cor_;
    this->tipo = tipo_;
    this->numPortas = numPortas_;
    this->numeroDeCarros +=1;
}

Carro::Carro(){
    this->cor = "Branco";
    this->tipo = "Hatch";
    this->numPortas = 2;
    this->numeroDeCarros +=1;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}