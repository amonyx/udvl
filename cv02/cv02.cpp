//diagonaly som neriesil
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//pomocna fnkcia na oznacenie pre SAT solver
int q(int i, int j, int N) {
	return i*N + j + 1;
}

void podmienky(int n) {
	ofstream o("input.txt");

	/*oznacenie dam*/
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			o << q(i,j,n) << " ";
		}
		o << "0" << endl;
	}
	/*-oznacenie dam*/

	
	/*v kazdom stlpci ak je dama, tak je len ona*/
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(j != k) {
					o << -(q(j,i,n)) << " " << -(q(k,i,n)) << " 0" << endl;
				}
			}
		}
	}
	/*-v kazdom stlpci ak je dama, tak je len ona*/

	/*v kazdom riadku ak je dama, tak je len ona*/
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(j != k) {
					o << -(q(i,j,n)) << " " << -(q(i,k,n)) << " 0" << endl;
				}
			}
		}
	}
	/*-v kazdom riadku ak je dama, tak je len ona*/
}

void vystup(const int n) {
	ifstream in;
	in.open("output.txt");
	cout<<endl;

	while(!in.eof()){
		char c;
		in >> c;
		if(c == 'S'){
			for(int j = 0; j < 2; j++){
				in >> c;
			}
			break;
		}
		if(c == 'U'){
			for(int j = 0; j < 11; j++){
				in >> c;
			}
			break;
		}
		//preskocenie pismeniek
	}
	int pocet = 0;
	while(!in.eof()){
		int i;
		in >> i;
		pocet++;
		if(i > 0){
			cout << "X "; //oznacuje, kde je dama
		} else{
			cout << "0 ";//oznacuje, kde nie je dama
		}
		if(pocet % 4 == 0){
			cout << endl; //pre prehladnost
		}
		if(pocet == n*n){
			break; //uz nebudu dalsie damy
		}
	}
	in.close();
}

int main() {
	int N = 0;
	cin >> N;
	podmienky(N);
	system("MiniSat_v1.14.exe input.txt output.txt");
	vystup(N);

	int pom;
	cin >> pom; //aby bolo vidiet vystup
	return 0;
}

