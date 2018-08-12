#ifndef PRECIA_H
#define PRECIA_H
#include "Trame.h"
#include <iostream>
#include <fstream>
#include <string>


class Precia : public Trame
{
    public:
        Precia();
        virtual ~Precia();
        void generate_values(int slave = 1, std::string num_mac = "3030", std::string unit = "6B6720");
        std::string cks();
        void generate_trame(int instr = 1 , int check = 1);
        std::string collect_data();
        std::string get_trame(int instr, int check);
        void print_all();
        void print_data();
        void print_trame(int instr, int check);
        void save_all();

    protected:

    private:
        std::string SOH = "01";             //caractere de debut : start of header (01h)
        std::string type_prot = "09";       //valeur hexa a indique selon le protocole (maitre : 0bh ; esclave : 09h)
        std::string num_mac = "3030";       //numero de la machine en hexa (exemple : machinne 00d => 3030h)
        std::string pds_br = "";            //poids brut
        std::string pds_tr = "";            //poids tare
        std::string pds_nt = "";            //poids net
        std::string unit = "6B6720";        //unite de poids en hexa (kg = 6B6720, gramme = 206720)
        std::string idDSD  = "";            //identifiant DSD
        std::string DSD = "";               //numero DSD
        std::string date = "";              //date jjmmaaaa
        std::string time = "";              //heure hhmm
        std::string blck_sep = "02";        //caractère indiquant le debut d''un noveau bloc de donnees (01h)
        std::string end_blck = "0D0A";
};

#endif // PRECIA_H
