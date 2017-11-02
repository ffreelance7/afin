#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;
/*int convert(char c){
    int num=(int)c;
    return num;
}*/
 int a;
int inve;
int b=10;
int modulo(int a ,int b){
    int q;
    if(a>0){
        q=a/b;
        return a-q*b;
    }
    modulo(a+b,b);
}
int euclides(int a,int b){
    if(b==0){
        return a;
    }
    euclides(b,modulo(a,b));
}
int inver_desa(int a,int b,int p0=0,int p1=1){
    int q,r;
    static int s=a;
    int p;
    if(b==1){
        return modulo(p1,s);
    }else{
        q=a/b;
        r=a-q*b;
        p=p0-q*p1;
        p0=p1;
        p1=p;
        inver_desa(b,r,p0,p1);
    }
}
int inver(int a ,int b){
        if(euclides(b,a)!=1){
            return 0;
        }else{
            return inver_desa(b,a);
        }
}

vector<char> encriptar(vector<int>array_num){
    int num_encrip;
    char caracter;
    vector<char>cadena;
    for(int i=0;i<array_num.size();i++){
        num_encrip=modulo((array_num[i]*a)+b,256);
        caracter=(char)num_encrip;
        cadena.push_back(caracter);
    }
    return cadena;
}
vector<char> Desencriptar(vector<int>array_num){
    int num_desencrip;
    char caracter;
    vector<char>cadena;
    for(int i=0;i<array_num.size();i++){
        num_desencrip=modulo(inve*(array_num[i]-b),256);
        caracter=(char)num_desencrip;
        //cout<<modulo(num_desencrip,256)<<endl;
        cadena.push_back(caracter);
    }
    return cadena;
}
void read(vector<int>&array_num,char* texto){
    ifstream source;
    source.open(texto,ios::in);
   if(source.is_open()){
        char c = source.get();
        while (!source.eof()) {
            array_num.push_back((int)c);
            //cout << c;
            c = source.get();
        }
        source.close();
   }

}
void write(vector<char>cade,char* texto){
     ofstream ficherosalida;
    ficherosalida.open(texto,ios::out);
     if(ficherosalida.is_open()){
        for(int i=0;i<cade.size();i++){
            ficherosalida<<cade[i];
        }
        ficherosalida.close();
     }
}
int main(){

    vector<int>array_num;
    vector<int>array_num_1;
      srand(time(NULL));
    read(array_num,"normal.txt");


    do{
        a=rand()%257;
        inve=modulo(inver(a,256),256);
    }while(inve==0);

    cout<<"Tu numero para encriptar : "<<a<<endl;
    cout<<"Tu clave de desencriptacion : "<<inve<<endl;
    vector<char>cadena_encr=encriptar(array_num);
    write(cadena_encr,"encriptado.txt");
    read(array_num_1,"encriptado.txt");

    vector<char>cadena_desen=Desencriptar(array_num_1);
    write(cadena_desen,"desencriptado.txt");
    return 0;
      }

