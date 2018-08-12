#ifndef PT6S3_H
#define PT6S3_H
#include "Trame.h"

class PT6S3 : public Trame
{
    public:
        PT6S3(std::string st = "49");                    //ctor
        virtual ~PT6S3();                                //dtor
        void generate_values(std::string st = "49");     //Genere les valeurs qui seront contenues dans la trame
        std::string cks();                               //Calcul la checksum de la trame au format hexa
        void generate_trame(std::string tdde = "q");     //Genere la trame sous sa forme hexa et Ascii
        std::string collect_data();                      //Formate les donnees de la trame pour en préparer l'affichage
        std::string get_trame(std::string tdde);         //Formate les trames hexa et ascii pour en preparer l'affichage
        void print_all();                                //Affiche dans la console les donnees et les trames selon les types de demandes
        void print_data();                               //Affiche les donnees
        void print_trame(std::string tdde);              //Affiche une trame selon un type de demande
        void save_all();                                 //Enregisre les donnees et trames sous la forme des différentes demandes

    protected:

    private:
        std::string p1;
        std::string state;
        std::string pds;
        std::string p2;
        std::string DSD;
        std::string p3;
};

#endif // PT6S3_H
