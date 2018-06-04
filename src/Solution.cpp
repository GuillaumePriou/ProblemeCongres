#include "Solution.h"

Solution::Solution():m_efficacite(0)
{
        //efficacite = 0;
}

Solution::~Solution()
{
    //dtor
}

void Solution::evaluerEfficacite(short incompatiblites[NB_SESSIONS][NB_SESSIONS])
{
    verfierContrainteSalles(m_planning, m_conflitParSession);
    veriferContrainteIncompatibiliteSession(m_planning, m_conflitParSession, incompatiblites);
    verifierContraintePrecedence(m_planning, m_conflitParSession);
    for(auto item : m_conflitParSession)
    {
        m_efficacite+=item;
    }

}

void Solution::verfierContrainteSalles(short planning[], short conflitParSession[])
{
    // Compte l'utilisation de chaque creneau horaire
    short compteCreneaux[NB_CRENEAUX] = {0,0,0,0} ;

    for (short i=0; i<NB_SESSIONS; i++)
        compteCreneaux[planning[i]]++;

    // Increase cost for each color being used to much (value added : the exceeding amount of use)

    // Pour chaque creneau
    for (short creneauSelectionne=0; creneauSelectionne<NB_CRENEAUX; creneauSelectionne++)
        // si le creneau est est trop utilise (trop de salles)
        if (compteCreneaux[creneauSelectionne] > 3)
            // Incrementer le cout de chaque session utilisant cette salle
            for (short sessionSelectionnee=0; sessionSelectionnee<NB_SESSIONS; sessionSelectionnee++)
                if (planning[sessionSelectionnee] == creneauSelectionne)
                    conflitParSession[sessionSelectionnee] += compteCreneaux[creneauSelectionne] - 3;
}
void Solution::veriferContrainteIncompatibiliteSession(short planning[], short conflitParSession[], short incompatiblites[NB_SESSIONS][NB_SESSIONS])
{
    //pour chaque session
    for(short sessionAVerifier=0;sessionAVerifier<NB_SESSIONS;sessionAVerifier++)
        //chercher les autres sessions prenant place au meme creneau horaire
        for(short autreSession =0;autreSession<NB_SESSIONS;autreSession++)
            //si c'est le m�me creneau
            if(planning[sessionAVerifier]==planning[autreSession])
                //consultation de la matrice d'imcompatibilite
                if(incompatiblites[autreSession][sessionAVerifier]==1)
                    //incrementation du coup la session
                    conflitParSession[sessionAVerifier] ++;

}
void Solution::verifierContraintePrecedence(short planning[], short conflitParSession[])
{
    // E must precede J
    if (planning[E] >= planning[J])
    {
        conflitParSession[E]+=3 ;
        conflitParSession[J]+=3 ;
    }

    // D must precede K
    if (planning[D] >= planning[K])
    {
        conflitParSession[D]+=3 ;
        conflitParSession[K]+=3 ;
    }

    // F must precede K
    if (planning[F] >= planning[K])
    {
        conflitParSession[F]+=3 ;
        conflitParSession[K]+=3 ;
    }
}
