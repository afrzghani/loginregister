#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct user {
    string username;
    string password;
};

void regist () {
    user baru;
    cout << "------Registrasi Akun------" << endl;
    cout << "Masukkan Username : ";
    getline(cin, baru.username);
    cout << "Masukkan Password : ";
    getline(cin, baru.password);

    // Cek apakah password mengandung spasi
    if (baru.password.find(' ') != string::npos) {
        cout << "Password tidak boleh menggunakan spasi!" << endl;
        return;
    }

    // Cek apakah username sudah ada
    ifstream infile("user.txt");
    string line;
    while (getline(infile, line) && !line.empty()) {
        if (line == "Username : " + baru.username) {
            cout << "Akun sudah ada, Coba gunakan username lain!" << endl;
            infile.close();
            return;
        }
    }
    infile.close();

    // Simpan user baru ke file
    ofstream outfile("user.txt", ios::app);
    outfile << "Username : " << baru.username << endl;
    outfile << "Password : " << baru.password << endl;
    outfile.close();

    cout << "Akun berhasil di daftarkan!" << endl;
}

void login() {
    user login;
    cout << "------Login------" << endl;
    cout << "Masukkan Username : ";
    getline(cin, login.username);
    cout << "Masukkan Password : ";
    getline(cin, login.password);

    ifstream infile("user.txt");
    string line;
    bool found = false;

    while (getline(infile, line) && !found) {
        string adaUsername = line.substr(11); // Ambil username
        getline(infile, line); // Ambil password
        string adaPassword = line.substr(11); // Ambil password

        if (adaUsername == login .username && adaPassword == login .password) {
            found = true;
        }
    }
    infile.close();

    if (found) {
        cout<<"Login Berhasil!"<<endl;
    } else {
        cout <<"Username atau Password Salah!"<< endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout<<"Pilih Menu :"<< endl;
        cout<<"1. Registrasi"<< endl;
        cout<<"2. Login"<<endl;
        cout<<"Pilihan : ";
        cin>>choice;
        cin.ignore();

        if(choice==1) {
            regist();
        }else if(choice == 2) {
            login();
        }else{
            cout<<"Pilihan tidak valid!"<<endl;
        }
    }
    return 0;
}
