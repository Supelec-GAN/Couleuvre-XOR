#include <iostream>

#include "headers/neuronelayer.hpp"

using namespace std;

int main()
{
    // On créé une couche de neurones à 5 entrées et 5 sorties
    NeuroneLayer n(5, 5);
    
    cout << n << "\n";

    // On créé un vecteur d'entrée de dimension 5x1 valant (1, 2, 3, 4, 5)
    Eigen::VectorXf input(5);
    input << 1,2,3,4,5;
    
    
    // On affiche la sortie de la couche de neurones
    cout << n.process(input) << endl;

    return 0;
}
