#include "carro.hpp"

Carro::Carro(string cor){
    this->cor = cor;
}

Carro::Carro(){
    this->cor = "Branco";
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