//#include "split.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


// SPLIT

#include <string>
#include <sstream>
#include <vector>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

// FIM


// float DistanceCalculator(float la1, float lo1, float la2, float lo2);










int main(){

   string acharCidade(int);
void acharCoordenadas(string);
int es; // escolha
cout << "escolha uma opcao: " << endl;
cout << '\n'; // endl em c
cout << "1 = calculo individual "<< endl;
 cout << "2 = calculo em lote" << endl;
cin >> es;
cout <<endl;

if (es == 1){

cout << "Informe o primeiro cep : ";
    int cep1;
    cin >> cep1;
    acharCidade(cep1); // pegando a função achaCidade para mostrar o cep1
    cout << "Informe o segundo cep : ";
    int cep2;
    cin >> cep2;
   acharCidade(cep2); // pegando a função achacidade para mostrar o cep2

   acharCoordenadas(acharCidade(cep1));

    string nome = acharCidade(cep2);
   acharCoordenadas(nome);

}
else {
    cout << "erro" << endl; // lote
}




}
string acharCidade(int cep){


    string linha;
    bool encontrei = false;

    fstream cidades;
    cidades.open("cep.csv", ios::in); // abrindo arquivo cep
    while (cidades.good()){
        getline(cidades, linha);
        if (linha.size()==0)
            continue;
        vector<string> campos = split(linha, ';');
        int cep_inicial = atoi(campos[1].c_str()); // convertendo variavel inteira para variavel do tipo string
        int cep_final = atoi(campos[2].c_str());
        if (cep >= cep_inicial && cep <= cep_final){
           cout << campos[0] << "-" << campos[3] << endl; // mostrando nome da cidade[0] e estado [3]

            string cidade = campos[0];
            return cidade;

            encontrei = true;
            break;
        }
    }
    cidades.close();
    if (!encontrei){
        cout << "Não encontrei nenhuma cidade com esse cep." << endl;
    }
}


float Calculodist (float latitude1, float latitude2, float longitude2, float longitude1){


float PI = 3.1415926536; // lendo valor de pi
float  R = 6372.795477598; // lendo o raio

// grau X radiano
latitude1 = latitude1*PI/180;
longitude1 = longitude1*PI/180;
latitude2 = latitude2*PI/180;
longitude2 = longitude2*PI/180;

//vendo a curvatura da terra
float alpha = sin(latitude1) * sin(latitude2);
float beta = cos(latitude1) * cos(latitude2);
float gama = cos( longitude1 - longitude2 );

//return no calculo final
return (R * acos(alpha + beta * gama));


}


void acharCoordenadas(string cidade){
   string linha;
   bool encontrei = false;
    fstream arqCoordenadas;
    arqCoordenadas.open("municipios_br.csv", ios::in ); // abrindo o arquivo de municipio para utilizar a latitude e longitude dos ceps

    float late2,long1, long2, late1; // declarando latitude e longitude de A e B

   while (arqCoordenadas.good()){
       getline(arqCoordenadas, linha);
       if (linha.size()==0){
           //continue;
        vector<string> campos = split(linha, ';');
        string nome = campos[3].c_str(); // pegando o campo tres o nome da cidade


        if (cidade == nome){
          cout << campos[1] << " " << campos[2] << endl;

             late1 = atof(campos[1].c_str()); // convertendo float para string (c_str)
              long1 = atof(campos[2].c_str());
              late2 = atof(campos[1].c_str());
              long2 = atof(campos[2].c_str());
        }
       }


cout << "A distancia e: " << Calculodist(late1, long1, late2, long2) << endl; // dando retorno da função Distancia
         encontrei = true;
    break; // parando

    arqCoordenadas.close();

}
}

