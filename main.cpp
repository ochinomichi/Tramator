#include "Eric.h"
#include "PT6S3.h"
#include "Precia.h"

using namespace std;

int main(){
    /*
    Trame test;
    chrono::system_clock::time_point today = (chrono::system_clock::now());
    time_t timer = chrono::system_clock::to_time_t(today);
    time(&timer);

    for(int i = 0;i<20;i++)
    {
        cout << test.rand_int(0, 200) << endl;
    }

    cout << test.int_to_str_len(86, 5) << endl;

    cout << test.string_to_hex("33E28") << endl;

    cout << test.compute_pds_nt(238, 23) << endl;

    cout << ctime(&timer) << endl;
    */

    Eric test1;
    test1.save_all();

    PT6S3 test2;
    test2.save_all();

    Precia test3;
    test3.save_all();

    //system("cls");


    return 0;
}
