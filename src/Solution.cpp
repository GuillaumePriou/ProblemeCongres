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

short Solution::verfierContrainteSalles(Solution sol)
{
    // Compte l'utilisation de chaque creneau horaire
    short colorsCount[NB_CRENEAUX] = {0,0,0,0} ;

    for (short i=0; i<NB_SESSIONS; i++)
        colorsCount[sol.planning[i]]++;

    // Increase cost for each color being used to much (value added : the exceeding amount of use)
    short cost = 0 ;

    for (short i=0; i<NB_COLORS; i++)
        if (colorsCount[i] > 3)
            cost += colorsCount[i] - 3 ;

    cout << "Cost color use : " << cost << endl ;
    return cost ;

}
void Solution::veriferContrainteIncompatibiliteSession()
{
    //
}
void Solution::verifierContraintePrecedence()
{
    //
}
