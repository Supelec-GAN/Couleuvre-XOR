#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include <vector>

#include "utility.hpp"
#include "dataset.hpp"
#include "CSVFile.h"

class DataCollector
{
public:

    /// Constructeur permettant d'initialiser le DataCollector avec le nom du csv file
    /**
     * Initialisation du DataCollector : contient des données traitées (abcisse, moyenne, écart-type, intervalle de confiance) et un csv file
     * @param testName : nom du csv file associé à ce relevé de données
     */
    DataCollector(std::string testName = "resultat");

    /// Ajout d'un set de données traitées (abscisse, moyenne, écart-type, intervalle de confiance)
    void addData(DataSet dataSet);

    /// Inscrit le vecteur de données dans le csv file
    void exportData();

private:
    /// Vecteur de données traitées : nombre d'apprentissages, moyenne, écart-type, intervalle de confiance
    std::vector<std::pair<int, Statistics::Data>> mDataVector;
    csvfile csv;

};

#endif // DATACOLLECTOR_H
