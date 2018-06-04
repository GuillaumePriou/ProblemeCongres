#include "Solution.h"

Solution::Solution()
{

}

Solution::~Solution()
{
    //dtor
}

void Solution::evaluerEfficacite()
{
    //
}

void Solution::verfierContrainteSalles(Solution sol)
{
    // Compte l'utilisation de chaque creneau horaire
    short compteCreneaux[NB_CRENEAUX] = {0,0,0,0} ;

    for (short i=0; i<NB_SESSIONS; i++)
        compteCreneaux[sol.planning[i]]++;

    // Increase cost for each color being used to much (value added : the exceeding amount of use)

    // Pour chaque creneau
    for (short creneauSelectionne=0; creneauSelectionne<NB_CRENEAUX; creneauSelectionne++)
        // si le creneau est est trop utilise (trop de salles)
        if (compteCreneaux[creneauSelectionne] > 3)
            // Incrementer le cout de chaque session utilisant cette salle
            for (short sessionSelectionnee=0; sessionSelectionnee<NB_SESSIONS; sessionSelectionnee++)
                if (sol.planning[sessionSelectionnee] == creneauSelectionne)
                    sol.conflitParSession[sessionSelectionnee] += compteCreneaux[creneauSelectionne] - 3;
}
void Solution::veriferContrainteIncompatibiliteSession(Solution sol)
{
    //pour chaque session
    for(short sessionAVerifier=0;sessionAVerifier<NB_SESSIONS;sessionAVerifier++)
        //chercher les autres sessions prenant place au même creneau horaire
        for(short autreSession =0;autreSession<NB_SESSIONS;autreSession++)
            //si c'est le même creneau
            if(sol.planning[sessionAVerifier]==sol.planning[autreSession])
                //consultation de la matrice d'imcompatibilité
                if(matrice[autreSession][sessionAVerifier]==1)
                    //incrementation du coup la session
                    sol.conflitParSession[sessionAVerifier] ++;

}
void Solution::verifierContraintePrecedence()
{
    //
}
