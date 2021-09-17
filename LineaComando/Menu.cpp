/*
 * Menu.cpp
 *
 *  Created on: 17 set 2021
 *      Author: alexm
 */

#include <iostream>
#include <string>
using namespace std;

#include "Menu.h"
#include "../gestoreDispositivo/gestoreDispositivo.h"
//#include "../Dispositivo/Allarme.h"
//#include "../Dispositivo/SensoreRaggInfrarossi.h"
//#include "../Dispositivo/Telecamera.h"
//#include "../Dispositivo/TelecameraAllarmata.h"
//#include "../Dispositivo/DispositivoSicurezza.h"

Menu::Menu() {
	scelta = 0;
	next = true;
}

Menu::~Menu() {
}

bool Menu::getnext() {

}

string Menu::showMenu() {
	while (next) {
		cout << "-----   MENU  ------\n\n";

		cout << "1) Aggiungere un dispositivo.\n";
		cout << "2) Rimuovi un dispositvo.\n";
		cout << "3) Stampare lista dispositivi.\n";
		cout << "4) Stampare lista dispositivi accesi.\n";
		cout << "5) Accendi un dispositvo.\n";
		cout << "6) Spegni un dispositvo.\n";
		cout << "7) Spegni tutti i dispositivi.\n";
		cout << "8) Simula movimento.\n";
		cout << "9) Simula suono Allarme\n";
		cout << "0) uscita dal progrmma\n";
		cout << "\nImmettere scelta...";
		cin >> scelta;
		cout << endl<<endl;

		switch (scelta) {
		case 0:
			cout << "CHIUSURA PROGRAMMA...";
			next = false;
			break;
		case 1:
			caso1();
			break;
		case 2:
			caso2();
			break;
		case 3:
			caso3();
			break;
		case 4:
			caso4();
			break;
		case 5:
			caso5();
			break;
		case 6:
			caso6();
			break;
		case 7:
			caso7();
			break;
		case 8:
			caso8();
			break;
		case 9:
			caso9();
			break;
		default:
			cout<<"**errore: scelta non valida**";
			break;
		} //fine switch
	} //fine while
} //fine funzione

void Menu::caso1() {
	cout<< "->Inserire tipo di dispositivo (s: Sensore, a: Allarme, t Telecamera, p TelecameraAllarmata: ";
	cin >> tipo;
	switch (tipo) {
	case 's':
		cout <<"Inserire nome sensore: ";
		cin>> nome;
		cout <<"Inserire luogo in cui viene collocato (cucina, sala, etc): ";
		cin>> collocamento;
		temp = new SensoreRaggInfrarossi(nome, false, collocamento);
		GestoreSicurezza::instance().aggiungiDispositivo(temp);
		cout<<"\n\n--->Sensore "<<nome<<" inserito correttamente!\n\n";
		break;
	case 'a':
		cout <<"Inserire nome allarme: ";
		cin>> nome;
		cout <<"Inserire luogo in cui viene collocato (cucina, sala, etc): ";
		cin>> collocamento;
		temp = new Allarme(nome, false, collocamento);
		GestoreSicurezza::instance().aggiungiDispositivo(temp);
		cout<<"\n\n--->Allarme "<<nome<<" inserito correttamente!\n\n";

		break;
	case 't':
		cout <<"Inserire nome telecamera: ";
		cin>> nome;
		cout <<"Inserire luogo in cui viene inserito (cucina, sala, etc): ";
		cin>> collocamento;
		cout <<"Inserire costo telecamera: ";
		cin>> costo;
		cout <<"Inserire modello telecamera: ";
		cin>> modello;
		temp = new Telecamera(nome, false, collocamento, costo, modello);
		GestoreSicurezza::instance().aggiungiDispositivo(temp);
		cout<<"\n\n--->Telecamera "<<nome<<" inserita correttamente!\n\n";

		break;
	case 'p':
		cout <<"Inserire nome telecamera allarmata: ";
		cin>> nome;
		cout <<"Inserire luogo in cui viene inserito (cucina, sala, etc): ";
		cin>> collocamento;
		cout <<"Inserire costo telecamera allarmata: ";
		cin>> costo;
		cout <<"Inserire modello telecamera allarmata: ";
		cin>> modello;
		temp = new TelecameraAllarmata(nome, false, collocamento, costo, modello);
		GestoreSicurezza::instance().aggiungiDispositivo(temp);
		cout<<"\n\n--->Telecamera allarmata "<<nome<<" inserita correttamente!\n\n";
		break;
	}
}

void Menu::caso2() {
	cout <<"Inserire ID del dispositivo da rimuovere (se non si ricorda l'ID faccia prima una stampa) : ";
	cin>> id;
	GestoreSicurezza::instance().rimuoviDispositivoID(id);

}

void Menu::caso3() {
	GestoreSicurezza::instance().stampaDispositiviTotali();
}

void Menu::caso4() {
	GestoreSicurezza::instance().stampaDispositiviAccesi();
}

void Menu::caso5() {
	cout<<"Inserire ID del dispositivo da accendere (se non si ricorda l'ID faccia prima una stampa) : ";
	cin>>id;
	GestoreSicurezza::instance().accendiDispositivo(id);
}

void Menu::caso6() {
	cout<<"Inserire ID del dispositivo da spegnere (se non si ricorda l'ID faccia prima una stampa) : ";
	cin>>id;
	GestoreSicurezza::instance().SpegniDispositivo(id);
}

void Menu::caso7() {
	cout<<"Spengo tutti i dispositivi...";
	GestoreSicurezza::instance().spegniDispositivi();
}

void Menu::caso8() {
	cout<<"Quale dispositivo vuoi simulare? (se non si ricorda l'ID faccia prima una stampa)";
	cin>>id;
	GestoreSicurezza::instance().SegnalaMovimento(id);
}

void Menu::caso9() {
	cout<<"Quale suono allarme vuoi simulare? (se non si ricorda l'ID faccia prima una stampa)";
	cin>>id;
	GestoreSicurezza::instance().AemettiSuono(id);
}

