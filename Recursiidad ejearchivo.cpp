#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Archivo{ //Anidamos porque no sabemos cuantos vectpres con archivos hay, los archivos tendran solo un nombre 
string name; //(sub dic 1)
};

struct Directorio{
string name; 
vector<Archivo> archivos;
vector<Directorio> subdirectorio;
};
bool findFile(Directorio&dir,string&path,string&target){//usa referencias de memoria, para que no copie el parametro con otra direccion de memoria
    for (auto arch: dir.archivos){ //iteramos archivps que la raiz que es clase base
        if(arch.name==target){
            path+="/"+dir.name;
        return true;
        }
    } 
    for (auto&subdir: dir.subdirectorio){
        string subdirpath=path + "/" + dir.name;
        if(findFile(subdir,subdirpath,target)){
            path=subdirpath;
            return true;
        }
    }
    return false; //cuando no exista el archivo
}

    //iteramos sobre subdirectorios que hara referencia al sistema de archivos, sera .sub
int main(){
    Directorio sistemaDeArchivos = {
       "root",
       {
               {"archivo1.txt"},
               {"archivo2.txt"}
       },
       {
               {
                   "subdir1",
                   {
                       {"archivo3.txt"},
                   },
                   {
                       {
                           "subdir2",
                           {
                               {"target.txt"},
                               {"archivo4.txt"}
                           },
                           {}
                       }
                   }
               },
               {"archivo5.txt"}
       }
    };

    string target = "archivo4.txt";
    string path = "";

        //funcion boolenada
        if(findFile(sistemaDeArchivos,path,target)){
            cout<<"El archivo "<<target<<" se encuentra en el directorio "<<path<<endl;
        }else{
            cout<<"El archivo "<<target<<" no se encuentra en el directorio "<<path<<endl;
        }
};