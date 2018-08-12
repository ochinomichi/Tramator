#include "Precia.h"

using namespace std;

Precia::Precia()
{
    //ctor
    SOH = "01";             //caractere de debut : start of header (01h)
    type_prot = "09";       //valeur hexa a indique selon le protocole (maitre : 0bh ; esclave : 09h)
    num_mac = "3030";       //numero de la machine en hexa (exemple : machinne 00d => 3030h)
    pds_br = "";            //poids brut
    pds_tr = "";            //poids tare
    pds_nt = "";            //poids net
    unit = "6B6720";        //unite de poids en hexa (kg = 6B6720, gramme = 206720)
    idDSD  = "";            //identifiant DSD
    DSD = "";               //numero DSD
    date = "";              //date jjmmaaaa
    time = "";              //heure hhmm
    blck_sep = "02";        //caractère indiquant le debut d''un noveau bloc de donnees (01h)
    end_blck = "0D0A";
    generate_values(1, "3030");
}

Precia::~Precia()
{
    //dtor
}

void Precia::generate_values(int slave, string inNum_mac, string inUnit){
    int brut = rand_int(750, 99999);
    int tare = rand_int(1, 500);
    if(slave == 1){
        type_prot = "09";
    }else{
        type_prot = "0B";
    }
    num_mac = inNum_mac;
    pds_br = int_to_str_len(brut,7);
    pds_tr = int_to_str_len(tare,7);
    pds_nt = int_to_str_len(compute_pds_nt(brut, tare),7);
    unit = inUnit;
    idDSD = int_to_str_len(rand_int(1, 99), 2);
    DSD = int_to_str_len(rand_int(1, 99999), 5);
    date = int_to_str_len(rand_int(1, 28), 2);
    date += int_to_str_len(rand_int(1, 12), 2);
    date += getDateTimeFormatted(2);
    time = int_to_str_len(rand_int(0, 23), 2);
    time += int_to_str_len(rand_int(0, 59), 2);
}

void Precia::set_values(string start, string type, string nmac, int br, int tr, string un, string iDSD, string DS, string dte, string tim, string blcksep, string endblck){
    SOH = start;
    type_prot = type;
    num_mac = nmac;
    pds_br = int_to_str_len(br, 7);
    pds_tr = int_to_str_len(tr, 7);
    pds_nt = int_to_str_len(compute_pds_nt(br,tr),7);
    unit = un;
    idDSD = iDSD;
    DSD = DS;
    date = dte;
    time = tim;
    blck_sep = blcksep;
    end_blck = endblck;
}

string Precia::cks(){
    int hex_xor = (hexa_int_table(trameHexa[0])*16)+hexa_int_table(trameHexa[1]);
    string exit = "    ";
    for(unsigned int i = 2;i<Trame::trameHexa.length();i+=2){
        string hex_char = "";
        for(int j = 0;j<2;j++){
            hex_char += trameHexa[i+j];
        }
        hex_xor = hex_xor ^ ((hexa_int_table(hex_char[0])*16)+hexa_int_table(hex_char[1]));
    }
    return "3" + int_hexa_table((hex_xor)/16) + "3" + int_hexa_table((hex_xor)%16);
}

void Precia::generate_trame(int instr, int check){
    trameHexa = SOH + type_prot;
    if(instr == 1){
        trameHexa += num_mac;
    }

    //poids brut
    trameHexa += blck_sep + "3031" + string_to_hexa(pds_br) + unit;
    //poids trame
    trameHexa += blck_sep + "3032" + string_to_hexa(pds_tr) + unit;
    //poids net
    trameHexa += blck_sep + "3033" + string_to_hexa(pds_nt) + unit;
    //date
    trameHexa += blck_sep + "3830" + string_to_hexa(date);
    //date
    trameHexa += blck_sep + "3831" + string_to_hexa(time);
    //id DSD
    trameHexa += blck_sep + "3938" + string_to_hexa(idDSD);
    //DSD
    trameHexa += blck_sep + "3939" + string_to_hexa(DSD);

    if(check == 1){
        trameHexa += cks();
    }

    trameHexa += end_blck;

    trame_from_hexa_to_string();
}

string Precia::collect_data(){
    string exit = "Bloc de debut de trame       : " + SOH + "\n";
    exit += "Type protocole (M/S)         : " + type_prot + "\n";
    exit += "Numero machin (hexa)         : " + num_mac + "\n";
    exit += "Poids brut                   : " + pds_br + "\n";
    exit += "Poids de tare                : " + pds_tr + "\n";
    exit += "Poids net                    : " + pds_nt + "\n";
    exit += "Unite de pesee               : " + unit + "\n";
    exit += "Identifiant DSD              : " + idDSD + "\n";
    exit += "Numero DSD                   : " + DSD + "\n";
    exit += "Date de la pesee             : " + date + "\n";
    exit += "Heure de la pesee            : " + time + "\n";
    exit += "Bloc de separation des infos : " + blck_sep + "\n";
    exit += "Bloc de fin de trame         : " + end_blck + "\n";

    return exit;
}

string Precia::get_trame(int instr, int check){
    string exit = "";
    generate_trame(instr, check);
    exit += "Trame resultant d'une demande avec instrument = " + int_to_str_len(instr, 1) + " et checksum = " + int_to_str_len(check,1) + "\n";
    exit += "---------Debut trame Hexa---------\n";
    exit += trameHexa + "\n";
    exit += "----------Fin trame Hexa----------\n";

    exit += "---------Debut trame Ascii---------\n";
    exit += trameAscii + "\n";
    exit += "----------Fin trame Ascii----------\n";

    return exit;
}

void Precia::print_all(){
    print_data();
    print_trame(0,0);
    print_trame(0,1);
    print_trame(1,0);
    print_trame(1,1);
}
void Precia::print_data(){
    cout << collect_data() << endl;
}

void Precia::print_trame(int instr, int check){
    cout << get_trame(instr, check) << endl;
}

void Precia::save_all(){
    ofstream monFlux("PRECIA"+getDateTimeFormatted(3)+".txt");
    if(monFlux){
        monFlux << collect_data() << endl;
        monFlux << get_trame(0,0) << endl;
        monFlux << get_trame(0,1) << endl;
        monFlux << get_trame(1,0) << endl;
        monFlux << get_trame(1,1) << endl;
    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    monFlux.close();
}
