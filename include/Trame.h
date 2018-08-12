#ifndef TRAME_H
#define TRAME_H
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

class Trame
{
    public:
        Trame();                                                    //ctor
        virtual ~Trame();                                           //dtor
        int rand_int (int val_min, int val_max);                    //Genere un nombre aleatoire entre des valeurs donnees
        std::string int_to_str_len (int val, unsigned int length);  //Convertit une valeur entiere dans une chaine et complete avec des 0 non significatifs pour atteindre la longueur indiquee
        std::string string_to_hexa(const std::string& input);       //Convertit une chaine de caractere sous sa forme hexadecimale
        void trame_from_hexa_to_string();                           //Convertit la trameHexa en caractère Ascii pour l'affecter à trameAscii
        std::string int_hexa_table(int val);                        //Table de conversion entier vers hexa
        int hexa_int_table(char val);                               //Table de conversion hexa vers entier
        std::string char_to_hexa(char val);                         //Convertit un charactère en chaine representant sa valeur hexa
        std::string hexa_to_char(std::string val);                  //Convertit une chaine representant la valeur hexa d'un caractère dans sa representation Ascii
        int compute_pds_nt(int brut, int tare);                     //Calcul le poids net a partir des poids donnee en entree
        virtual std::string cks () = 0;                             //Calcul la checksum sous forme hexa et la retourne sous forme de chaine de caracteres
        std::string getDateTimeFormatted(int format);               //Retourne la date systeme selon de format demande

    protected:
        std::string trameHexa;                                      //Trame sous forme hexa
        std::string trameAscii;                                     //Trame sous forme Ascii
};

#endif // TRAME_H
