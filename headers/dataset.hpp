#ifndef DATASET_H
#define DATASET_H

#include <vector>

#include "headers/utility.hpp"

class DataSet
{
public:
    /// Constructeur permettant d'initialiser un jeu de données à partir d'un vecteur de données
    /**
     * Initialisation du jeu de données et calcul des mesures statistiques
     * @param dataVect : vecteur de données (float)
     * @param sample : nombre d'apprentissage correspondant au dataSet
     */
    DataSet(int sample, std::vector<float> dataVect = {{}});

    /// Fonction permettant l'ajout d'une valeur dans le jeu de données
    /**
     * @param data :  nouvelle valeur ajoutée dans le vecteur de données
     * @param process : bool true pour process les données (voir processData)
     */
    void addRawData(float data, bool process = false);

    /// Fonction permettant l'ajout d'un vecteur de données dans le jeu de données
    /**
     * @param dataVect  nouveau vecteur ajouté dans le vecteur de données
     */
    void addRawData(std::vector<float> dataVect);

    /// Fonction calculant les moyennes, écarts-types et les données associées du jeu de données
    /**
     * Calcul de la moyenne et de l'intervalle de confiance
     * Calcul de l'écart-type et de son intervalle de confiance
     * Calcul de la médiane de l'échantillon
     */
    void processData();

    /// Fonction renvoyant Data, contenant la moyenne, écart-type et intervalle de confiance
    Statistics::Data getData();
    /// Fonction renvoyant le nombre d'apprentissage correspondant au DataSet
    int getSample();

private:
    /// Vecteur contenant les données brutes du jeu
    std::vector<float>              mRawData;
    /// Structure contenant la moyenne, l'écart-type et l'intervalle de confiance à 95% du jeu de données
    Statistics::Data                mData;
    /// Médiane du jeu de données
    float                           mMedian;

    /// Entier correspondant au nombre d'apprentissage correspondant au DataSet
    int                             mSample;
    /// Booleen
    bool                            isProcessed;

};

#endif // DATASET_H
