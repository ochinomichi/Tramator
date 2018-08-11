#ifndef PT6S3_H
#define PT6S3_H
#include <string>
#include <fstream>
#include "Trame.h"


class PT6S3 : public Trame
{
    public:
        PT6S3(std::string st = "49");
        virtual ~PT6S3();
        void generate_values(std::string st = "49");
        std::string cks();
        void generate_trame(std::string tdde = "q");
        std::string collect_data();
        std::string get_trame(std::string tdde);
        void print_all();
        void print_data();
        void print_trame(std::string tdde);
        void save_all();

    protected:

    private:
        std::string p1;
        std::string state;
        std::string pds;
        std::string p2;
        std::string DSD;
        std::string p3;
};

#endif // PT6S3_H
