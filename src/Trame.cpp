#include "Trame.h"

using namespace std;

Trame::Trame()
{
    //ctor
    trameHexa  = "";
    trameAscii = "";
}

Trame::~Trame()
{
    //dtor
}

int Trame::rand_int(int val_min, int val_max)
{
    //random.seed();
    return (rand() % (val_max - val_min)) + val_min;
}

string Trame::int_to_str_len (int val, unsigned int length)
{
    string str_val = to_string(val);
    while(str_val.length()<length)
    {
        str_val = "0" + str_val;
    }
    return str_val;
}
/*
string Trame::str_to_hex (string val)
{
    string hex_val = ""
    for(int i=0;i<val.length();i++){
        string hv = hex(val[i]).replace('0x', '')
        if len(hv) == 1:
            hv = '0'+hv
        hex_val += hv
    }
    return hex_val
}
*/
string Trame::string_to_hexa(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

void Trame::trame_from_hexa_to_string(){
    trameAscii = "";
    for(unsigned int i=0;i<trameHexa.length();i+=2){
        string sending = "  ";
        sending[0] = trameHexa[i];
        sending[1] = trameHexa[i+1];
        trameAscii += hexa_to_char(sending);
    }
}

string Trame::int_hexa_table(int val){
    string result = "";
    switch(val){
        case 0 :
            result = "0";
            break;
        case 1 :
            result = "1";
            break;
        case 2 :
            result = "2";
            break;
        case 3 :
            result = "3";
            break;
        case 4 :
            result = "4";
            break;
        case 5 :
            result = "5";
            break;
        case 6 :
            result = "6";
            break;
        case 7 :
            result = "7";
            break;
        case 8 :
            result = "8";
            break;
        case 9 :
            result = "9";
            break;
        case 10 :
            result = "A";
            break;
        case 11 :
            result = "B";
            break;
        case 12 :
            result = "C";
            break;
        case 13 :
            result = "D";
            break;
        case 14 :
            result = "E";
            break;
        case 15 :
            result = "F";
    }
    return result;
}

int Trame::hexa_int_table(char val){
    int result = 0;
    switch(val){
        case '0' :
            result = 0;
            break;
        case '1' :
            result = 1;
            break;
        case '2' :
            result = 2;
            break;
        case '3' :
            result = 3;
            break;
        case '4' :
            result = 4;
            break;
        case '5' :
            result = 5;
            break;
        case '6' :
            result = 6;
            break;
        case '7' :
            result = 7;
            break;
        case '8' :
            result = 8;
            break;
        case '9' :
            result = 9;
            break;
        case 'A' :
            result = 10;
            break;
        case 'B' :
            result = 11;
            break;
        case 'C' :
            result = 12;
            break;
        case 'D' :
            result = 13;
            break;
        case 'E' :
            result = 14;
            break;
        case 'F' :
            result = 15;
    }
    return result;
}

string Trame::char_to_hexa(char val){
    return int_hexa_table(((int)val)/16) + int_hexa_table(((int)val)%16);
}

string Trame::hexa_to_char(string val){
    string result = " ";
    result[0] = (char)((hexa_int_table(val[0])*16)+hexa_int_table(val[1]));
    return result;
}
/*
Trame::int_to_hexa (string val)
{
    hv = hex(val).replace('0x', '')
    if len(hv) == 1:
        hv = '0'+hv
    return hv
}
*/
Trame::compute_pds_nt(int brut, int tare)
{
    return int(brut) - int(tare);
}

string Trame::getDateTimeFormatted(int format){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    switch(format){
    case 1: // Annee au format AA
        strftime(buffer,sizeof(buffer),"%y",timeinfo);
        break;
    case 2: // Annee au format AAAA
        strftime(buffer,sizeof(buffer),"%Y",timeinfo);
        break;
    case 3:
        strftime(buffer,sizeof(buffer),"%d%m%Y-%I%M%S",timeinfo);
        break;
    default : // Format par défaut JJMMAAA-HHMMSS
         strftime(buffer,sizeof(buffer),"%d%m%Y-%I%M%S",timeinfo);
    }


    string str(buffer);
    return str;
}
