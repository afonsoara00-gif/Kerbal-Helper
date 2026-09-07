#include <cstdlib>
#include <iterator>
#include <ostream>
#include <print>
#include <string.h>
#include <iostream>
#include "deltaV.hpp"
#include <cmath>
#include <windows.h>

using std::println;
using std::print;
using std::cin;
using std::string;

void deltav(){
    float gravidade = 9.81;
    string startbody,endbody;
    float deltav,lsp,mstart,mend;
    println("██████╗ ███████╗██╗  ████████╗ █████╗ ██╗   ██╗");
    println("██╔══██╗██╔════╝██║  ╚══██╔══╝██╔══██╗██║   ██║");
    println("██║  ██║█████╗  ██║     ██║   ███████║██║   ██║");
    println("██║  ██║██╔══╝  ██║     ██║   ██╔══██║╚██╗ ██╔╝");
    println("██████╔╝███████╗███████╗██║   ██║  ██║ ╚████╔╝ ");
    println("╚═════╝ ╚══════╝╚══════╝╚═╝   ╚═╝  ╚═╝  ╚═══╝  ");
    println("Delta-v is the measure of the maximum change in velocity a spacecraft can achieve using all its propellant (fuel)");
    println("It is useful for knowing if you can reach a celestial body."); 
    println("Formula: Δv = Lsp(vac)*9,81*In(mstart/mend) for every stage");
    print("Lsp(vac):");
    cin >> lsp;
    print("Mass of the stage with a full fuel load:");
    cin >> mstart;
    print("Mass of the stage with an empty fuel load:");
    cin >> mend;
    deltav = lsp*gravidade*log(mstart/mend);
    println("{} ≃ {}" ,deltav,round(deltav));
    system("pause");
}