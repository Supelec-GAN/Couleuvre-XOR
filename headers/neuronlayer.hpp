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
        Eigen::VectorXf process(Eigen::VectorXf inputs);


        /// La fonction effectuant les calculs de rétropropagation
        /**
         * La fonction calcule les 3 équations matricielles, mets à jour les poids et renvoie le vecteur de dérivées partielles
         * nécessaires pour la backprop de la couche précédente
         * @param xnPartialDerivative le vecteur des dérivées partielles selon Xn
         * @param step le pas d'apprentissage
         * @return le vecteur des dérivées partielles selon Xn-1 à envoyer à la couche précédente
         */
        Eigen::VectorXf backProp(Eigen::VectorXf xnPartialDerivative, float step);



    public:
        /// Fonction utilitaire permettant d'afficher le neurone
        /**
         * Cette fonction affiche la matrice des poids
         */
        friend std::ostream& operator<<(std::ostream& flux, NeuronLayer nl);

    private:
        /// Fonction transformant le vecteur d'input afin de pouvoir manipuler les biais comme un poids sur une entrée -1
        /**
         * La fonction ajoute la coordonnée -1 en fin de vecteur (la dimension augmente de 1)
         * @param input le vecteur auquel on ajoute une coordonnée
         * @return le vecteur augmenté d'une coordonnée
         */
        Eigen::VectorXf processInput(Eigen::VectorXf input);

        /// Fonction renvoyant le vecteur des dérivées de Fn évalué en Yn
        /**
         * Cette fonction calcule Fn'(Yn) ou Yn = mBufferActivationLevel
         * @return le vecteur des dérivées mises en colonne
         */
        Eigen::MatrixXf fnDerivativeMatrix() const;

    private:
        /// La matrice des poids de la couche de neurones
        Eigen::MatrixXf                 mPoids;                 

        /// La fonction d'activation de la couche de neurones
        std::function<float(float)>     mActivationFun;

        /// Buffer pour stocker Yn = WnXn-1, nécessaire pour la backprop
        Eigen::VectorXf                 mBufferActivationLevel;

        /// Buffer pour stocker l'input, nécessaire pour la backrprop
        Eigen::VectorXf                 mBufferInput;
};

#endif // NEURONLAYER_HPP
