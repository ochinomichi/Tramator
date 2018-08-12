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
        Trame();
        virtual ~Trame();
        int rand_int (int val_min, int val_max);
        std::string int_to_str_len (int val, unsigned int length);
        //std::string str_to_hex (string val);
        std::string string_to_hexa(const std::string& input);
        void trame_from_hexa_to_string();
        std::string int_hexa_table(int val);
        int hexa_int_table(char val);
        std::string char_to_hexa(char val);
        std::string hexa_to_char(std::string val);
        //std::string int_to_hexa (string val);
        int compute_pds_nt(int brut, int tare);
        virtual std::string cks () = 0;
        std::string getDateTimeFormatted(int format);

    protected:
        std::string trameHexa;
        std::string trameAscii;
};

#endif // TRAME_H
