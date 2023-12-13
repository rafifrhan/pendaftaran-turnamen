#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

struct Input
{
    char data;
}team, idsquad; //objek dari struct input

struct Hasil
{
    char team, idsquad;
}result;    //objek dari struct hasil


void input (Input team, Input idsquad)
{
    // datainput1 dan datainput2 merupakan objek dari ofstream
    // data yang diinput disimpan dalam "input1.txt" dan "input2.txt"

    ofstream dataInput3 ("input3.txt");
    ofstream dataInput4 ("input4.txt");
    cout << "Masukkan Nama Team : "; cin >> team.data;
    cout << "Masukkan ID SQUAD : "; cin >> idsquad.data;

    //menyimpan ke dalam file

    dataInput3.write((char*)& team, sizeof(team));
    dataInput4.write((char*)& idsquad, sizeof(idsquad));

    //menutup file

    dataInput3.close();
    dataInput4.close();
}

void HASIL(Input team, Input idsquad)
{
    Hasil result;
    ofstream dataHasil("hasil.txt");
    
    //ifstream untuk membaca file (input1.txt)
    ifstream bukainput3("input3.txt", ios::in);
    bukainput3.read((char*)&team, sizeof(team));
  
    
    //ifstream untuk membaca file (input2.txt)
    ifstream bukainput4("input4.txt", ios::in);
    bukainput4.read((char*)&idsquad, sizeof(idsquad));

  result.team = team.data;
    result.idsquad = idsquad.data;

    dataHasil.write((char*)&result, sizeof(result));       //menulis hasil berupa objek ke dalam file

    bukainput3.close();
    bukainput4.close();
    dataHasil.close();
}

void hasil(Hasil result)
{
    ifstream bukaHasil("hasil.txt");       //membaca data objek yang ada di dalam file "hasil1.txt"

    
    bukaHasil.read((char*)&result, sizeof(result));
    cout << "" << endl;
    cout << "===========================================" << endl;  
    cout << "      SELAMAT ANDA TELAH BERGABUNG" << endl;
    cout << "===========================================" << endl;  
    cout << "DENGAN NAMA TEAM = " << result.team << endl;
    cout << "DENGAN IDSQUAD = " << result.idsquad << endl;
    cout << "===                  TERIMAKASIH                           ===" << endl;  
    

    bukaHasil.close();
}
int main()
{
	cout << "===========================================" << endl;  
    cout << "=    PENDAFTARAN TURNAMEN MOBILE LEGEN    =" << endl;
    cout << "===========================================" << endl;  
    cout << "=          KAMPUNG DURIAN RUNTUH          =" << endl;
    cout << "===========================================" << endl;  
    cout << "=    by.MUHAMMAD RAFI FARHAN (202131145)  =" << endl;
    cout << "===========================================" << endl;  
    cout << "===========================================" << endl;   

    //memanggil fungsi
    input(team, idsquad);
    HASIL(team, idsquad);
    hasil(result);

    _getch();

}
