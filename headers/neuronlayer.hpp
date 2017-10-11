#ifndef NEURONLAYER_HPP
#define NEURONLAYER_HPP

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <functional>
#include <memory>


/// Classe modélisant une couche de neurones
/**
 *  NeuroneLayer représente une couche de neurones, avec une matrice de poids et une fonction d'activation
 */
class NeuronLayer
{
    public:
        /// Constructeur permettant d'initialiser les paramètres de la couche de neurones
        /**
         * \param inputSize le nombre d'inputs de cette couche
         * \param outputSize le nombre d'outputs de cette couche
         * \param activationF la fonction d'activation de tous les neurones de la couche
         *
         * La matrice de poids est de dimension outputSize x inputSize
         */
        NeuronLayer(unsigned int inputSize, unsigned int outputSize, std::function<float(float)> activationF = [] (float x) {return x;});

        /// La fonction effectuant le calcul de la sortie en fonction de l'entrée
        /**
         * \param inputs le vecteur d'input de la couche de neurones
         * \return le vecteur d'output de la couche de neurones
         * la fonction effectue le produit matriciel des poids par les entrées, puis applique la fonction d'activation
         */
        Eigen::VectorXf process(Eigen::VectorXf inputs) const;

    public:
        /// Fonction utilitaire permettant d'afficher le neurone
        /**
         * Cette fonction affiche la matrice des poids
         */
        friend std::ostream& operator<<(std::ostream& flux, NeuronLayer nl);

    private:
        /// La matrice des poids de la couche de neurones
        Eigen::MatrixXf                 mPoids;                 

        /// Le vecteur des biais de la couche de neurones
        Eigen::VectorXf                 mBiais;

        /// La fonction d'activation de la couche de neurones
        std::function<float(float)>     mActivationFun;
};

#endif // NEURONLAYER_HPP
