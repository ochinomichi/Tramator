#include "Eric.h"
using namespace std;
Eric::Eric(string st) : Trame()
{
    //ctor
    CR = "0D";
    state = "";
    pds_br = "";
    pds_tr = "";
    pds_nt = "";
    DSD = "";
    date = "";
    time = "";
    generate_values(st);
}

Eric::~Eric()
{
    //dtor
}

void Eric::generate_values(string st){
    int brut = rand_int(750, 99999);
    int tare = rand_int(1, 500);
    state = st;
    pds_br = int_to_str_len(brut,5);
    pds_tr = int_to_str_len(tare,5);
    pds_nt = int_to_str_len(compute_pds_nt(brut, tare),5);
    DSD = int_to_str_len(rand_int(1, 999999), 6);
    date = int_to_str_len(rand_int(1, 28), 2);
    date += int_to_str_len(rand_int(1, 12), 2);
    date += getDateTimeFormatted(1);
    time = int_to_str_len(rand_int(0, 23), 2);
    time += int_to_str_len(rand_int(0, 59), 2);
    time += int_to_str_len(rand_int(0, 59), 2);
}

std::string Eric::cks(){
    int hex_sum = 0;
    for(unsigned int i = 2;i<Trame::trameHexa.length();i+=2){
        string hex_char = "";
        for(int j = 0;j<2;j++){
            hex_char += trameHexa[i+j];
        }
        hex_sum += (hexa_int_table(hex_char[0])*16)+hexa_int_table(hex_char[1]);
    }
    hex_sum = hex_sum & 127;
    return int_hexa_table((hex_sum)/16) + int_hexa_table((hex_sum)%16);
}

void Eric::generate_trame(std::string tdde){
    trameHexa = CR + state;

    if(tdde == "P"){
        trameHexa += string_to_hexa(pds_br);
    }

    if(tdde == "B" or tdde == "N" or tdde == "A" or tdde == "I"){
        if(tdde =="N"){
            trameHexa += string_to_hexa(" " + pds_nt);
        }else{
            trameHexa += string_to_hexa(" " + pds_br);
        }
        if(tdde == "A" or tdde == "I"){
            trameHexa += string_to_hexa(" " + pds_tr + " " + pds_nt);
            if(tdde == "I"){
                trameHexa += string_to_hexa(DSD);
                trameHexa += string_to_hexa(date);
                trameHexa += string_to_hexa(time);
            }
        }
    }

    trameHexa += cks();
    trame_from_hexa_to_string();
}

void Eric::print_all(){
    print_data(collect_data());
    print_trame("P");
    print_trame("B");
    print_trame("N");
    print_trame("A");
    print_trame("I");
}

string Eric::collect_data(){
    string data = "";
    data += "Bloc de debut de trame (hexa)  : " + CR + "\n";
    data += "Etat pont bascule (hexa)       : " + state + "\n";
    data += "Poids brut                     : " + pds_br + "\n";
    data += "Poids de tare                  : " + pds_tr + "\n";
    data += "Poids net                      : " + pds_nt + "\n";
    data += "Numero DSD                     : " + DSD + "\n";
    data += "Date de la pesee               : " + date + "\n";
    data += "Heure de la pesee              : " + time + "\n";

    return data;
}

void Eric::print_data(string data){
    cout << data << endl;
}

void Eric::print_trame(string tdde){
    cout << get_trame(tdde) << endl;
}

string Eric::get_trame(string tdde){
    string exit = "";
    generate_trame(tdde);
    exit += "Trame resultant d'une demande : " + tdde + "\n";
    exit += "---------Debut trame Hexa---------\n";
    exit += trameHexa + "\n";
    exit += "----------Fin trame Hexa----------\n";

    exit += "---------Debut trame Ascii---------\n";
    exit += trameAscii + "\n";
    exit += "----------Fin trame Ascii----------\n";

    return exit;
}

void Eric::save_all(){
    ofstream monFlux("ERIC"+getDateTimeFormatted(3)+".txt");
    if(monFlux){
        monFlux << collect_data() << endl;
        monFlux << get_trame("P") << endl;
        monFlux << get_trame("B") << endl;
        monFlux << get_trame("N") << endl;
        monFlux << get_trame("A") << endl;
        monFlux << get_trame("I") << endl;
    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    monFlux.close();
}
