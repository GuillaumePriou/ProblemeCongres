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

Solution initRandom(Solution sol);
void printSolution (Solution sol);


int main()
{
    Solution meilleureSolutionActuelle;;
    Solution nouvelleSolution;
    meilleureSolutionActuelle = initRandom(meilleureSolutionActuelle);
    srand (time(nullptr));
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

    /*
    Solution sol;
                           // A  B  C  D  E  F  G  H  I  J  K
    short tab1[NB_SESSIONS]= {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3};
    sol.setPlanning(tab1);

    sol.resetCompteursEfficacite();
    sol.verfierContrainteSalles(sol.getPlanning(), sol.m_conflitParSession);
    printSolution (sol);

    sol.resetCompteursEfficacite();
    sol.veriferContrainteIncompatibiliteSession(sol.getPlanning(), sol.m_conflitParSession, incompatiblites);
    printSolution (sol);

    sol.resetCompteursEfficacite();
    sol.verifierContraintePrecedence(sol.getPlanning(), sol.m_conflitParSession);
    printSolution (sol);

    sol.resetCompteursEfficacite();
    sol.evaluerEfficacite(incompatiblites);
    printSolution (sol);
    */
}


Solution initRandom(Solution sol)
{
    for (short item=0; item<NB_SESSIONS; item++)
    {
        sol.setPlanning(item, rand() % (NB_CRENEAUX - 1) +1);
    }

    return sol;
}
void printSolution (Solution sol)
{
    cout << "Cout total : " << sol.m_efficacite << endl;

    cout << "Conflit par session : " ;
    for (short i=0; i<NB_SESSIONS; i++)
    {
        cout << " "<< sol.m_conflitParSession[i] ;
    }
    cout << endl ;

}
