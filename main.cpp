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

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
