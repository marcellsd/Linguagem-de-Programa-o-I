#include <string>
#include "motor.hpp"

using namespace std;

class Carro{
    public:
    string tipo;
    string placa;
    int numPortas;
    int velocidade;
    string cor;
    Motor motor;
    static  int numeroDeCarros;

    Carro(string cor_, string tipo_, int numPortas_);
    Carro();

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};