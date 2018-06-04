/*
        Pseudo-code algorithme

        nbCreneaux = 4

        Start:
            var meilleureSolutionActuelle = tab[11]
            var nouvelleSolution = tab[11]

            var efficaciteMeilleureSolutionActuelle = tab[11]
            var efficaciteNouvelleSolution = tab[11]

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
#include "Solution.h"
#include <time.h>

using namespace std;

int main()
{
    Solution meilleureSolutionActuelle;;
    Solution nouvelleSolution;
    meilleureSolutionActuelle = initRandom(meilleureSolutionActuelle);
    srand (time(NULL));

    short incompatiblites[NB_SESSIONS][NB_SESSIONS] = {   {0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
                                                          {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
                                                          {1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0 },
                                                          {0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
                                                          {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1 },
                                                          {0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0 },
                                                          {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
                                                          {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 },
                                                          {0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0 },
                                                          {1, 0, 0, 1, 2, 1, 0, 0, 1, 0, 0 },
                                                          {0, 1, 0, 2, 1, 2, 0, 1, 0, 0, 0 }
                                                        };

}

Solution initRandom(Solution sol)
{
    for (auto item : sol.planning)
    {
        item = rand() % (NB_CRENEAUX - 1) +1;
    }

    return sol;
}