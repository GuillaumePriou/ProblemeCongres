#ifndef SOLUTION_H
#define SOLUTION_H

#define NB_SESSIONS 11

class Solution
{
    public:
        Solution();
        virtual ~Solution();

        void evaluerEfficacite();
        void verfierContraiteSalles();
        void veriferContrainteIncompatibiliteSession();
        void verifierContraintePrecedence();

    protected:

    private:
        /*
            Tableau contenant le creneau horaire de chaque session
            valeur de chaque case : 1 � 4 (i�me demi journ�e du congres de 2 jours
        */
        short solution[NB_SESSIONS];

        /*
            Indique les performances de la solution. A minimiser.
            0 = La solution satisfait le probleme du congres

            La valeur augmente d'un point pour chaque session ayant un conflit :
            - incompatibilit� avec une autre session (m�me presentateur)
            - probleme de precedance (prerequis d'un cours de niveau 1 pour assister au cours de niveau 2)
            - probleme de salle (seulement 3 salles donc autant de sessions prenant place simultanement)
        */
        double efficacite;

        /*
        */
        short conflitParSession[NB_SESSIONS];
};

#endif // SOLUTION_H
