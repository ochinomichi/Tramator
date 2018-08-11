#include "PT6S3.h"

using namespace std;

PT6S3::PT6S3(string st){
    //ctor
    trameHexa = "";
    trameAscii = "";
    p1 = "0D";
    state = "";
    pds = "";
    p2 = "00";
    DSD = "";
    p3 = "00";
    generate_values(st);
}

PT6S3::~PT6S3(){
    //dtor
}

void PT6S3::generate_values(string st){
    state = st;
    pds = int_to_str_len(rand_int(1, 99999), 5);
    DSD = int_to_str_len(rand_int(1, 99999), 5);
}

std::string PT6S3::cks(){
    int hex_sum = 0;
    for(unsigned int i=0;i < trameHexa.length();i+=2){
        string hex_char = "";
        for(unsigned int j=0;j<2;j++){
            hex_char += trameHexa[i+j];
        }
        hex_sum += (hexa_int_table(hex_char[0])*16)+hexa_int_table(hex_char[1]);
        if(hex_sum >= 256){
            hex_sum -= 256;
        }
    }
    hex_sum = hex_sum ^ 127;
    if(hex_sum < 32){
        hex_sum += 32;
    }
    return int_hexa_table((hex_sum)/16) + int_hexa_table((hex_sum)%16);
}

void PT6S3::generate_trame(string tdde){
    trameHexa = p1 + state + string_to_hexa(pds);

    if(tdde == "q"){
        trameHexa += "20" + string_to_hexa(DSD);
    }

    trameHexa +=  p2;
    trameHexa += cks() + p3;

    trame_from_hexa_to_string();
}

string PT6S3::collect_data(){
    string exit = "Bloc de debut de trame P1 (hexa) : " + p1 + "\n";
    exit += "Etat pont bascule (hexa)               : " + state + "\n";
    exit += "Poids                                  : " + pds + "\n";
    exit += "Numero DSD                             : " + DSD + "\n";
    exit += "Bloc separateur P2 (hexa)              : " + p2 + "\n";
    exit += "Bloc de fin P3 (hexa)                  : " + p3 + "\n";

    return exit;
}

string PT6S3::get_trame(string tdde){
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
void PT6S3::print_all(){
    print_data();
    print_trame("p, m, t, r, g, z ou w");
    print_trame("q");
}
void PT6S3::print_data(){
    cout << collect_data() << endl;
}
void PT6S3::print_trame(string tdde){
    cout << get_trame(tdde) << endl;
}
void PT6S3::save_all(){
    ofstream monFlux("PT6S3"+getDateTimeFormatted(3)+".txt");
    if(monFlux){
        monFlux << collect_data() << endl;
        monFlux << get_trame("p, m, t, r, g, z ou w") << endl;
        monFlux << get_trame("q") << endl;
    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    monFlux.close();
}
