// Kerbal Helper - Copyright (c) 2026 Afonsothegoat (MIT License)
// The full license text must be maintained in the LICENSE.txt file
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string.h>
#include <string>
#include <windows.h>
#include <print>
#include <winnt.h>
#include <unordered_map> 
#include <vector>
#include "deltaV.hpp"

using std::println;
using std::print;
using std::cin;
using std::string;
using std::vector;

#define Listadetarefas\
    tarefa(deltav,"deltav","0") //lista de todas as tarefas(ex:deltav)
enum class tarefalista{ //criaçao um enum de tarefas
    #define tarefa(nomedatarefa,str,num) nomedatarefa,
    Listadetarefas
    #undef tarefa
    ERRO
};

const std::unordered_map<string, tarefalista>mapatarefas = { //gerar mapa de string para enum
    #define tarefa(nomedatarefa,str,num) {str,tarefalista::nomedatarefa},{num,tarefalista::nomedatarefa},
    Listadetarefas
    #undef tarefa
}; //gera a mapa

tarefalista ENUM(const string& tarefa){
    auto iterator = mapatarefas.find(tarefa);
    return iterator != mapatarefas.end() ? iterator->second :tarefalista::ERRO;
} //tradutor de string para enum


void Erro(const char* Titulo,const char* conteudo,const long typeofMB){ 
    MessageBox(NULL, conteudo, Titulo, typeofMB);
    system("cls");
} //pop up de erro 

bool listadetarefas(const string& tarefa){
   switch(ENUM(tarefa)) {
        case tarefalista::deltav:
            system("cls");
            deltav();
            break;
        default:
            Erro("ERRO","Not found",MB_RIGHT | MB_ICONERROR);
            return false ;
            break;
    } 
    return true;
}

void menu(){
    restart:
    string nomedatarefa,nomedatarefaLow;
    vector<string> tarefas = {
        "DeltaV"
    };
    println();
    println("███   ███ ████████ ███████▄  ██████▄  ▄███████▄ ████           ███   ███ ████████ ████      ███████▄  ████████ ███████▄ ");
    println("███  ▄██▀ ███      ███   ███ ███  ▐█▌ ███   ███ ████           ███   ███ ███      ████      ███   ███ ███      ███   ███");
    println("███▀▀██▄  ███▀▀▀   ████████  ███▀▀▀█▄ █████████ ████           ███▀▀▀███ ███▀▀▀   ████      ███████▀  ███▀▀▀   ████████ ");
    println("███   ███ ███▄▄▄▄▄ ███   ███ ███▄▄▄██ ███   ███ ████▄▄▄▄▄      ███   ███ ███▄▄▄▄▄ ████▄▄▄▄▄ ███       ███▄▄▄▄▄ ███   ███");
    println("▀▀▀   ▀▀▀ ▀▀▀▀▀▀▀▀ ▀▀▀   ▀▀▀ ▀▀▀▀▀▀▀  ▀▀▀   ▀▀▀ ▀▀▀▀▀▀▀▀▀      ▀▀▀   ▀▀▀ ▀▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀▀▀ ▀▀▀       ▀▀▀▀▀▀▀▀ ▀▀▀   ▀▀▀ Version 0.0.1");
    println("Here you'll find information on the Delta-V required for each planet, as well as TWR (Thrust-to-Weight Ratio) and much more.");
    println("This program is \033[1mOPEN SOURCE\033[0m under the MIT License. Copyright (c) 2026 Afonsothegoat."); // 
    println("Kerbal Helper is a program developed by a single person!");
    println("Credits:");
    println("> Dev: Afonsothegoat");
    println("> GitHub: https://github.com/afonsoara00-gif");
    println("> Discord: afonsothegoat");
    for(int x=0;x<4;x++){
        println();
    }
    println("Write the name or number of the option you want.");
    for(int i;i<tarefas.size();i++){
        if(i>tarefas.size()-1){
            println("{}-{}, ",i,tarefas[i]);
        }else {
            print("{}-{}, ",i,tarefas[i]);
        }
    }
    println(); 
    println();
    print("Type: ");
    cin >> nomedatarefa;
    for (size_t i = 0; i < nomedatarefa.size(); i++) {
        nomedatarefa[i] = std::tolower(static_cast<unsigned char>(nomedatarefa[i]));
    }
    if(listadetarefas(nomedatarefa) == false){
       goto restart;
    }
}
int main(){
    menu();
    return 0; 
} 
