#include <cstdlib>
#include <print>
#include <iostream>
#include "deltaV.hpp"
#include <cmath>
#include <synchapi.h>
#include <windows.h>
#include <string.h>
#include <winnt.h>

using std::println;
using std::print;
using std::cin;
using std::string;

void deltav(){
    restart:
    float gravidade = 9.81;
    string startbody,endbody;
    float vacdeltav,ALSdeltav,Ispvac,IspALS,mstart,mend;
    println("");
    println("██████╗ ███████╗██╗  ████████╗ █████╗ ██╗   ██╗");
    println("██╔══██╗██╔════╝██║  ╚══██╔══╝██╔══██╗██║   ██║");
    println("██║  ██║█████╗  ██║     ██║   ███████║██║   ██║");
    println("██║  ██║██╔══╝  ██║     ██║   ██╔══██║╚██╗ ██╔╝");
    println("██████╔╝███████╗███████╗██║   ██║  ██║ ╚████╔╝ ");
    println("╚═════╝ ╚══════╝╚══════╝╚═╝   ╚═╝  ╚═╝  ╚═══╝  ");
    println("Delta-v is the measure of the maximum change in velocity a spacecraft can achieve using all its propellant (fuel)");
    println("It is useful for knowing if you can reach a celestial body."); 
    println("Formula: Δv = Isp*9,81*In(mass full of fuel/mass without fuel) for every stage");
    println("");
    println("Note: The weight must be exact; to find the weight or mass, go to the Engineer's Report, where you will find the mass in tons, and then copy that value here.");
    println("If you dont know your Isp it is on your Rocket status (vac = vacuum and ALS = Above Sea Level)");
    println("");
    print("Isp(ALS): ");
    cin >> IspALS;
    print("Isp(vac): ");
    cin >> Ispvac;
    print("Mass of the stage with a full fuel load: ");
    cin >> mstart;
    print("Mass of the stage with an empty fuel load: ");
    cin >> mend;
    vacdeltav = Ispvac*gravidade*log(mstart/mend);
    ALSdeltav = IspALS*gravidade*log(mstart/mend);
    println("");
    println("Deltav at ALS  = {} ≃ {}" ,ALSdeltav,round(ALSdeltav));
    println("Deltav at vac = {} ≃ {}" ,vacdeltav,round(vacdeltav));
    cin.ignore();
    println("");
    println("");
    println("Do you want to perform another calculation or go to the menu?");
    println("1-Menu | Enter to do Again");
    string escolha;
    restartescolha:
    std::getline(cin,escolha);
    for (size_t i = 0; i < escolha.size(); i++) {
        escolha[i] = std::tolower(static_cast<unsigned char>(escolha[i]));
    }
    println("{}",escolha);
    if(escolha.empty()){
        system("cls");
        goto restart;
    }else if (escolha == "1" || escolha =="menu"){
        system("cls");
    }else if (escolha != "1" || escolha !="menu") {
        MessageBox(NULL, "Not found", "ERRO", MB_OK | MB_ICONERROR);
        goto restartescolha;
    }
}