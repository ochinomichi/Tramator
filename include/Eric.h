#ifndef ERIC_H
#define ERIC_H
#include "Trame.h"

class Eric : public Trame
{
    public:
        Eric(std::string st = "49");                    //ctor
        virtual ~Eric();                                //dtor
        void generate_values(std::string st = "49");    //Genere les valeurs qui seront contenues dans la trame
        void set_values(std::string car, std::string st, int brut, int tare, std::string ndsd, std::string dte, std::string tim);
        void generate_trame(std::string tdde = "I");    //Genere la trame sous sa forme hexa et Ascii
        std::string collect_data();                     //Formate les donnees de la trame pour en préparer l'affichage
        std::string get_trame(std::string tdde);        //Formate les trames hexa et ascii pour en preparer l'affichage
        void print_all();                               //Affiche dans la console les donnees et les trames selon les types de demandes
        void print_data();                              //Affiche les donnees
        void print_trame(std::string tdde);             //Affiche une trame selon un type de demande
        void save_all();                                //Enregisre les donnees et trames sous la forme des différentes demandes
        std::string cks();                              //Calcul la checksum de la trame au format hexa

    protected:

    private:
        std::string CR;
        std::string state;
        std::string pds_br;
        std::string pds_tr;
        std::string pds_nt;
        std::string DSD;
        std::string date;
        std::string time;
};

#endif // ERIC_H
