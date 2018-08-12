#ifndef ERIC_H
#define ERIC_H
#include "Trame.h"

class Eric : public Trame
{
    public:
        Eric(std::string st = "49");
        virtual ~Eric();
        void generate_values(std::string st = "49");
        void generate_trame(std::string tdde = "I");
        std::string collect_data();
        std::string get_trame(std::string tdde);
        void print_all();
        void print_data(std::string data);
        void print_trame(std::string tdde);
        void save_all();

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
        std::string cks();
};

#endif // ERIC_H
