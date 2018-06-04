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
    verfierContrainteSalles(planning, conflitParSession);
    veriferContrainteIncompatibiliteSession(planning, conflitParSession);
    verifierContraintePrecedence(planning, conflitParSession);
    for(auto item : conflitParSession)
    {
        efficacite+=item;
    }

}

void Solution::verfierContrainteSalles(short planning[], short conflitParSession[])
{
    //
    planning;
}
void Solution::veriferContrainteIncompatibiliteSession(short planning[], short conflitParSession[])
{
    //
}
void Solution::verifierContraintePrecedence(short planning[], short conflitParSession[])
{
    //
}
