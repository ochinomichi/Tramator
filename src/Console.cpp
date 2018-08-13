#include "Console.h"

using namespace std;

void process_init(){
    int i = -1;
    do{
        cout << "----------------TRAMATOR Version 1.3.0----------------" << endl;
        cout << "1- Generation automatique aleatoire (tous protocoles)" << endl;
        cout << "2- ERIC" << endl;
        cout << "3- PT6S3" << endl;
        cout << "4- Precia A+" << endl;
        cout << "0- Quitter" << endl << endl;
        cout << "Votre choix ? ";
        cin >> i;
        cls();
        switch(i){
        case 1 :
            process_auto(0);
            break;
        case 2 :
            cout << "avant process eric" << endl;
            process_eric();
            cout << "apres process eric" << endl;
            break;
        case 3 :
            process_pt6s3();
            break;
        case 4 :
            process_precia();
            break;
        case 0 :
            break;
        default :
            i=-1;
            cout << "Ce choix n'existe pas" << endl;
            pause();
        }
    }while(i!=0);
}

void process_auto(int protocole){
    if(protocole == 1 || protocole == 0){
        Eric trameE;
        trameE.save_all();
        cout << "Fichier Eric cree." << endl;
    }
    if(protocole == 2 || protocole == 0){
        PT6S3 tramePT;
        tramePT.save_all();
        cout << "Fichier PT6S3 cree." << endl;
    }
    if(protocole == 3 || protocole == 0){
        Precia tramePr;
        tramePr.save_all();
        cout << "Fichier Precia A+ cree." << endl;
    }
    pause();
}

void process_eric(){
    int i = -1;
    do{
        cout << "----------------    PROTOCOLE ERIC    ----------------" << endl;
        cout << "1- Generation automatique aleatoire" << endl;
        cout << "2- Saisie manuelle" << endl;
        cout << "0- Quitter" << endl << endl;
        cout << "Votre choix ? ";
        cin >> i;
        cls();
        switch(i){
        case 1 :
            process_auto(1);
            break;
        case 2 :
            input_eric();
            break;
        case 0 :
            break;
        default :
            i=-1;
            cout << "Ce choix n'existe pas" << endl;
            pause();
        }
    }while(i!=0);
}

void input_eric(){
    Eric trameE;
    string CR = "0D";
    string state = "49";
    int pds_br = 0;
    int pds_tr = 0;
    string DSD = "";
    string date = "";
    string time = "";
    cout << "Poids brut (entier sur 5 chiffres)" << endl;
    cin >> pds_br;
    cls();
    cout << "Poids de tare (entier sur 5 chiffres)" << endl;
    cin >> pds_tr;
    cls();
    cout << "Numero DSD (6 caracteres de 0 a 9)" << endl;
    cin >> DSD;
    cls();
    cout << "Date de pesee (format JJMMAA)" << endl;
    cin >> date;
    cls();
    cout << "Heure de pesee (format HHMMSS)" << endl;
    cin >> time;
    cls();
    trameE.set_values(CR, state, pds_br,pds_tr, DSD, date, time);
    cout << "Valeurs saisies et enregistrees :" << endl;
    trameE.print_data();
    trameE.save_all();
    pause();
}

void process_pt6s3(){
    int i = -1;
    do{
        cout << "----------------    PROTOCOLE PT6S3   ----------------" << endl;
        cout << "1- Generation automatique aleatoire" << endl;
        cout << "2- Saisie manuelle" << endl;
        cout << "0- Quitter" << endl << endl;
        cout << "Votre choix ? ";
        cin >> i;
        cls();
        switch(i){
        case 1 :
            process_auto(2);
            break;
        case 2 :
            input_pt6s3();
            break;
        case 0 :
            break;
        default :
            i=-1;
            cout << "Ce choix n'existe pas" << endl;
            pause();
        }
    }while(i!=0);
}

void input_pt6s3(){
    PT6S3 trameE;
    string p1 = "0D";
    string state = "49";
    int pds = 0;
    string p2 = "00";
    string DSD = "";
    string p3 = "00";
    cout << "Poids (entier sur 5 chiffres)" << endl;
    cin >> pds;
    cls();
    cout << "Numero DSD (5 caracteres de 0 a 9)" << endl;
    cin >> DSD;
    cls();
    trameE.set_values(p1, state, pds, p2, DSD, p3);
    cout << "Valeurs saisies et enregistrees :" << endl;
    trameE.print_data();
    trameE.save_all();
    pause();
}

void process_precia(){
    int i = -1;
    do{
        cout << "----------------   PROTOCOLE PRECIA   ----------------" << endl;
        cout << "1- Generation automatique aleatoire" << endl;
        cout << "2- Saisie manuelle" << endl;
        cout << "0- Quitter" << endl << endl;
        cout << "Votre choix ? ";
        cin >> i;
        cls();
        switch(i){
        case 1 :
            process_auto(3);
            break;
        case 2 :
            input_precia();
            break;
        case 0 :
            break;
        default :
            i=-1;
            cout << "Ce choix n'existe pas" << endl;
            pause();
        }
    }while(i!=0);
}

void input_precia(){
    Precia trameE;
    string SOH = "01";
    string type_prot = "09";
    string num_mac = "3030";
    int pds_br = 0;
    int pds_tr = 0;
    string unit = "6B6720";
    string idDSD  = "";
    string DSD = "";
    string date = "";
    string time = "";
    string blck_sep = "02";
    string end_blck = "0D0A";
    cout << "Poids brut (entier sur 7 chiffres)" << endl;
    cin >> pds_br;
    cls();
    cout << "Poids de tare (entier sur 7 chiffres)" << endl;
    cin >> pds_tr;
    cls();
    cout << "Numero identifiant DSD (2 caracteres de 0 a 9)" << endl;
    cin >> idDSD;
    cls();
    cout << "Numero DSD (5 caracteres de 0 a 9)" << endl;
    cin >> DSD;
    cls();
    cout << "Date de pesee (format JJMMAAAA)" << endl;
    cin >> date;
    cls();
    cout << "Heure de pesee (format HHMM)" << endl;
    cin >> time;
    cls();
    trameE.set_values(SOH, type_prot, num_mac, pds_br, pds_tr, unit, idDSD, DSD, date, time, blck_sep, end_blck);
    cout << "Valeurs saisies et enregistrees :" << endl;
    trameE.print_data();
    trameE.save_all();
    pause();
}

void cls(){
    system("cls");
}

void pause(){
    system("pause");
    cls();
}
