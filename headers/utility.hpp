#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <vector>

/// Classe statique utile pour les calculs statistiques
class Statistics
{
public:
    /// Structure contenant les mesures d'un jeu de donnée
    struct Data
    {
        /// Moyenne
        float mean;
        /// Ecart-type
        float deviation;
        /// Confiance à 95%
        float confRange;
    };

public:
    /// Fonction calculant les moyennes, écarts-types et les données associées du jeu de données
    /**
     * Calcul de la moyenne et de l'intervalle de confiance
     * Calcul de l'écart-type et de son intervalle de confiance
<<<<<<< HEAD
     * @param dataVect Vecteur de données
=======
     * @param Vecteur de données
>>>>>>> datacollector
     */
    static Data processData(const std::vector<float> &dataVect);


    /// Fonction calculant la médiane d'un jeu de données
    /**
<<<<<<< HEAD
     * @param dataVect Vecteur de données
=======
     * @param Vecteur de données
>>>>>>> datacollector
     */
    static float processMedian(std::vector<float> dataVect);
};

#endif // UTILITY_HPP
