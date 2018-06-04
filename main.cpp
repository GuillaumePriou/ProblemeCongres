/*
        Pseudo-code algorithme

        nbCreneaux = 4

        Start:
            var meilleureSolutionActuelle
            var nouvelleSolution

            var incompatiblites = tab[11][11]

            incompatibilites = {
                                ...
                                }


            meilleureSolutionActuelle = randomSolution()
            efficaciteMeilleureSolutionActuelle = evaluerSolution (meilleureSolutionActuelle)

            while (sommeDesCases(efficaciteMeilleureSolutionActuelle) > 0)
                ameliorerSolution ()

        ameliorerSolution:
            var sessionLaPlusConflictuelle = efficaciteMeilleureSolutionActuelle.maxConflit()

            nouvelleSolution = meilleureSolutionActuelle
            nouvelleSolution[sessionLaPlusConflictuelle] = rand()%nbCreneaux

            efficaciteNouvelleSolution = evaluerSolution (nouvelleSolution)

            if (efficaciteNouvelleSolution < efficaciteMeilleureSolutionActuelle)
                meilleureSolutionActuelle = nouvelleSolution
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Solution.h"

#define MAX_NB_ITERATION 500

using namespace std;

Solution initRandom(Solution sol, short incompatiblites[NB_SESSIONS][NB_SESSIONS]);
void printSolutions (Solution meilleurSol, Solution nouvSol);
short determinerSessionAChanger (Solution solAModif);


int main()
{
    vector<short> memProgression;
    short lastValMem = 666;

    short newVal ;
    srand (time(NULL));
                                                        // A  B  C  D  E  F  G  H  I  J  K
    short incompatiblites[NB_SESSIONS][NB_SESSIONS] = {   {0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0 }, // A
                                                          {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1 }, // B
                                                          {1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0 }, // C
                                                          {0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0 }, // D
                                                          {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1 }, // E
                                                          {0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0 }, // F
                                                          {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0 }, // G
                                                          {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 }, // H
                                                          {0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0 }, // I
                                                          {1, 0, 0, 1, 2, 1, 0, 0, 1, 0, 0 }, // J
                                                          {0, 1, 0, 2, 1, 2, 0, 1, 0, 0, 0 }  // K
                                                        };

    short nbIteration = 0;

    Solution meilleureSolutionActuelle;;
    Solution nouvelleSolution;

    // Initialisation solution initiale
    meilleureSolutionActuelle = initRandom(meilleureSolutionActuelle, incompatiblites);

    // Amelioration incrementale de la solution
    while (meilleureSolutionActuelle.m_efficacite > 0 && nbIteration < MAX_NB_ITERATION)
    {
        if (nbIteration%50 == 0)
            cout << "Uh" << endl;



        nouvelleSolution = meilleureSolutionActuelle;

        //  Recherche de la session posant le plus de problemes
        short sessionAChanger = determinerSessionAChanger (nouvelleSolution);


        // Changement aleatoire du creneau de cette session
        do
        {
            newVal = rand()% (NB_CRENEAUX -1)+1 ;
        } while (newVal == nouvelleSolution.getPlanning()[sessionAChanger]);

        nouvelleSolution.setPlanning(sessionAChanger, newVal);
        nouvelleSolution.evaluerEfficacite(incompatiblites);

        // Si la nouvelle est meilleure, on la garde
        if (meilleureSolutionActuelle.m_efficacite > nouvelleSolution.m_efficacite)
        {
            meilleureSolutionActuelle = nouvelleSolution ;
            meilleureSolutionActuelle.evaluerEfficacite(incompatiblites);
        }

        printSolutions (meilleureSolutionActuelle, nouvelleSolution);

        if (meilleureSolutionActuelle.m_efficacite != lastValMem)
        {
            lastValMem = meilleureSolutionActuelle.m_efficacite;
            memProgression.push_back(lastValMem);
        }

        nbIteration++ ;
    }

    for (short item=0; item<NB_SESSIONS; item++)
    {
        cout << "progression : " << memProgression[item] << endl ;
    }

    /*
    Solution sol;
                           // A  B  C  D  E  F  G  H  I  J  K
    short tab1[NB_SESSIONS]= {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3};
    sol.setPlanning(tab1);
    */
}


Solution initRandom(Solution sol, short incompatiblites[NB_SESSIONS][NB_SESSIONS])
{
    for (short item=0; item<NB_SESSIONS; item++)
    {
        sol.setPlanning(item, rand() % (NB_CRENEAUX) +1);
    }

    sol.evaluerEfficacite(incompatiblites);

    return sol;
}

void printSolutions (Solution meilleurSol, Solution nouvSol)
{
    cout << "Meilleure : ";

    // affiche le planning
    for (short i=0; i<NB_SESSIONS; i++)
            cout << meilleurSol.getPlanning()[i] << " " ;

    // Affiche le cout
    cout << "(cout : " << meilleurSol.m_efficacite << "<=";

    // affiche le cout par session
    for (short i=0; i<NB_SESSIONS; i++)
        cout << meilleurSol.m_conflitParSession[i] << " " ;

    cout  << ")" << endl;

    // Affiche nouvelle solution
        cout << "Candidate : ";

    // affiche le planning
    for (short i=0; i<NB_SESSIONS; i++)
            cout << nouvSol.getPlanning()[i] << " " ;

    // Affiche le cout
    cout << "(cout : " << nouvSol.m_efficacite << "<=" ;

    // affiche le cout par session
    for (short i=0; i<NB_SESSIONS; i++)
        cout << nouvSol.m_conflitParSession[i] << " " ;

    cout  << ")" << endl;

    cout << endl ;

}

short determinerSessionAChanger (Solution solAModif)
{
    short maximum = 0 ; // Valeur de conflit maximum relevee jusqu'a present
    vector<int> TabSessionsChiantes;

    for (short sessionAnalysee =0; sessionAnalysee<NB_SESSIONS; sessionAnalysee++)
    {
        if (maximum < solAModif.m_conflitParSession[sessionAnalysee])
        {
           TabSessionsChiantes.clear();
           maximum = solAModif.m_conflitParSession[sessionAnalysee];
           TabSessionsChiantes.push_back(sessionAnalysee);
        }
        else if (maximum == solAModif.m_conflitParSession[sessionAnalysee])
           TabSessionsChiantes.push_back(sessionAnalysee);

    }

    cout << "Contenu TabSessionsChiantes : " ;
    for (short i=0; i<TabSessionsChiantes.size(); i++)
        cout << TabSessionsChiantes[i] << " " ;

    cout << "Conflit max : " << maximum ;
    cout << " (" << TabSessionsChiantes.size() ;

    cout << "solutions aussi chiantes)" << endl;

    short BITE = rand() % TabSessionsChiantes.size();

    cout << "BITE = " << BITE << "mais y a de la place que pour " << TabSessionsChiantes.size() << " elements !" << endl;
    short sessionAChanger = TabSessionsChiantes[BITE] ;

    cout << "Session a changer : " << sessionAChanger << endl;
}
