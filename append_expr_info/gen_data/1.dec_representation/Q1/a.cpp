#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <fstream>
#include <cstring>
using namespace std;
#define random(x) rand()%(x)
string gen_data(int length){
    string data_str = "";
    int t = random(10);
    while( t == 0 ){
        t = random(10);
    }
    data_str += to_string(t);
    for(int i=1; i<length; i++){
        t = random(10);
        data_str += to_string(t);
    }
    return data_str;
}
int main()
{
    long long number = 10000000;
#ifdef LEN_2
    int prec[] = {16, 16, 16};
    int scale[] = {2, 2, 2};
    string file = "./LEN_2/data.tbl";
#elif LEN_4
    int prec[] = {34,34,34};
    int scale[] = {2,2,2};
    string file = "./LEN_4/data.tbl";
#elif LEN_8
    int prec[] = {70,70,70};
    int scale[] = {2,2,2};
    string file = "./LEN_8/data.tbl";
#elif LEN_16
    int prec[] = {142,142,142};
    int scale[] = {2,2,2};
    string file = "./LEN_16/data.tbl";
#elif LEN_32
    int prec[] = {286,286,286};
    int scale[] = {2,2,2};
    string file = "./LEN_32/data.tbl";
#endif
    int data_per_row = 3;
    srand((unsigned)time(NULL));
    string filename(file);
    fstream file_out;
    file_out.open(filename, ios_base::out);
    for (int index = 0; index < number; index++){
        string row_data = "";
        for(int row_index = 0; row_index < data_per_row; row_index++){
            int sign = random(2);
            if(sign == 1)
                row_data += "-"+ gen_data(prec[row_index] - scale[row_index]) + "." + gen_data(scale[row_index]);
            else
                row_data += gen_data(prec[row_index] - scale[row_index]) + "." + gen_data(scale[row_index]);
            if(row_index < data_per_row - 1)
                row_data += "|";
        }
        file_out<< row_data <<endl;
    }
    return 0; 
}