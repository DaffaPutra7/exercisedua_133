#include <iostream>
#include <vector>
using namespace std;

class Pengarang;
class Penerbit {
public:
	string nama;
	vector<Pengarang*> daftar_Pengarang;
	Penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}

	void tambahPengarang(Pengarang*);
	void cetakPengarang();
};

class Pengarang {
public:
	string nama;
	vector<Penerbit*> daftar_Penerbit;

	Pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\" ada\n";
	}

	void tambahPenerbit(Penerbit*);
	void cetakPenerbit();
};

class Buku {
public:
	string nama;
	vector<Pengarang*> daftar_Pengarang;

	Buku(string pNama) :nama(pNama) {
		cout << "Buku \"" << nama << "\" ada\n";
	}

	void tambahPengarang(Pengarang*);
	void cetakPengarang();
};

void Penerbit::tambahPengarang(Pengarang* pPengarang) {
	daftar_Pengarang.push_back(pPengarang);
}
void Penerbit::cetakPengarang() {
	cout << "Daftar Pengarang yang bekerja di Penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_Pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void Pengarang::tambahPenerbit(Penerbit* pPenerbit) {
	daftar_Penerbit.push_back(pPenerbit);
	pPenerbit->tambahPengarang(this);
}
void Pengarang::cetakPenerbit() {
	cout << "Daftar Penerbit dari Pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_Penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void Buku::tambahPengarang(Pengarang* pPengarang) {
	daftar_Pengarang.push_back(pPengarang);
}
void Buku::cetakPengarang() {
	cout << "Daftar Buku dari Pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_Pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	Pengarang* varPengarang1 = new Pengarang("Joko");
	Pengarang* varPengarang2 = new Pengarang("Lia");
	Pengarang* varPengarang3 = new Pengarang("Giga");
	Pengarang* varPengarang4 = new Pengarang("Asroni");
	Penerbit* varPenerbit1 = new Penerbit("Game Press");
	Penerbit* varPenerbit2 = new Penerbit("Intan Pariwara");
	Buku* varBuku1 = new Buku("Fisika");
	Buku* varBuku2 = new Buku("Algoritma");
	Buku* varBuku3 = new Buku("Basis Data");
	Buku* varBuku4 = new Buku("Dasar Pemrograman");
	Buku* varBuku5 = new Buku("Matematika");
	Buku* varBuku6 = new Buku("Multimedia 1");

	varPengarang1->tambahPenerbit(varPenerbit1);
	varPengarang2->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);
	varPengarang4->tambahPenerbit(varPenerbit2);
	varBuku1->tambahPengarang(varPengarang1);
	varBuku2->tambahPengarang(varPengarang1);
	varBuku3->tambahPengarang(varPengarang2);
	varBuku4->tambahPengarang(varPengarang4);
	varBuku5->tambahPengarang(varPengarang3);
	varBuku6->tambahPengarang(varPengarang3);

	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();
	varPengarang3->cetakPenerbit();
	varPengarang4->cetakPenerbit();
	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varBuku1->cetakPengarang();
	varBuku2->cetakPengarang();
	varBuku3->cetakPengarang();
	varBuku4->cetakPengarang();
	varBuku5->cetakPengarang();
	varBuku6->cetakPengarang();

	delete varPenerbit1;
	delete varPenerbit2;
	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;
	delete varBuku1;
	delete varBuku2;
	delete varBuku3;
	delete varBuku4;
	delete varBuku5;
	delete varBuku6;

	return 0;
}
