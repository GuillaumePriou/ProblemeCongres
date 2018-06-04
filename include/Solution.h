#ifndef SOLUTION_H
#define SOLUTION_H

#define NB_SESSIONS 11
#define NB_SALLES 3
#define NB_CRENEAUX 4

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define J 9
#define K 10
class Solution
{
    public:
        Solution();
        virtual ~Solution();

        short* getPlanning(void);
        void setPlanning(short session, short nouvelleValeur);
        void setPlanning(short tab[]);

        void evaluerEfficacite(short incompatiblites[NB_SESSIONS][NB_SESSIONS]);
        void verfierContrainteSalles(short planning[], short conflitParSession[]);
        void veriferContrainteIncompatibiliteSession(short planning[], short conflitParSession[], short incompatiblites[NB_SESSIONS][NB_SESSIONS]);
        void verifierContraintePrecedence(short planning[], short conflitParSession[]);

    protected:

    private:
        /*
            Tableau contenant le creneau horaire de chaque session
            valeur de chaque case : 1 a 4 (ieme demi journee du congres de 2 jours
        */
        short m_planning[NB_SESSIONS];

        /*
            Indique les performances de la solution. A minimiser.
            0 = La solution satisfait le probleme du congres

            La valeur augmente d'un point pour chaque session ayant un conflit :
            - incompatibilit� avec une autre session (meme presentateur)
            - probleme de precedance (prerequis d'un cours de niveau 1 pour assister au cours de niveau 2)
            - probleme de salle (seulement 3 salles donc autant de sessions prenant place simultanement)
        */
        double m_efficacite;

        /*
        */
        short m_conflitParSession[NB_SESSIONS];
};

#endif // SOLUTION_H
