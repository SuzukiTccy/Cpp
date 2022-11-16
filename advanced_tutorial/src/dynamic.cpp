#include<iostream>
using namespace std;



void dynamicTest(){

    cout << "------------2-dimension array :-------------" << endl;
    int **array = nullptr; // [3][4]
    array = new int *[3];
    for(int i = 0; i<3; ++i){
        array[i] = new int [4];
        for(int j=0; j<4; ++j){
            array[i][j] = i*j;
        }
    }

    for(int i=0; i<3; ++i){
        for(int j=0; j<4; ++j){
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i=0; i<3; ++i){
        delete [] array[i];
        array[i] = nullptr;
    }

    delete array;
    array = nullptr;


    cout << "------------3-dimension array :-------------" << endl;
    int ***p = nullptr; //[3][4][5]
    p = new int **[3];
    int i,j,k;
    for(i=0;i<3;++i){
        p[i] = new int *[4];
        for(j=0;j<4;++j){
            p[i][j] = new int[5];
            for(k=0;k<5;++k){
                p[i][j][k] = i*j+k;
            }
        }
    }

    for(i=0;i<3;++i){
        cout << "[";
        for(j=0;j<4;++j){
            if (j == 0)
                cout << "[";
            else
                cout << "  ";
            for(k=0;k<5;++k){
                if(k == 4 && j == 3)
                    cout << p[i][j][k] << ']' << endl;
                else
                    cout << p[i][j][k] << '\t';
            }
            cout << endl;
        }
    }

    for(i=0;i<3;++i){
        for(j=0;j<4;++j){
            delete [] p[i][j];
            p[i][j] = nullptr;
        }
        delete [] p[i];
        p[i] = nullptr;
    }

    delete p;
    p = nullptr;

}