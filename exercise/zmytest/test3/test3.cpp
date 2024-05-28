#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include <typeinfo>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

#include "../../vector/vector.hpp"
#include "../../list/list.hpp"

#include "../../hashtable/hashtable.hpp"
#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"

namespace t {
    string chars19 {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?"};
    random_device rdp;
    mt19937 generator19(rdp());

    string rand19 (int lenght){
        string output(chars19);
        shuffle(output.begin(), output.end(), generator19);
        return output.substr(0, lenght);
    }

    void pienoxString(lasd::Vector<string>& v, unsigned int dim){
        for(unsigned int i=0; i < dim; i++){
            v[i] = rand19(5);
        }
    }

    template<typename Data>
    void pieno19(lasd::Vector<Data>& v, unsigned int dim){
        Data dataRandom;
        srand ((unsigned int)time(NULL));
        std::string type_name = "";

        for(unsigned int i = 0; i < dim; i++){
            dataRandom = (Data)rand() / 100 + 1;
            v[i] = dataRandom;
        }
    }


    void MenuHashCls(int type){
        cout << "Test HashtableClsAdr" << endl;
        int x = -1;
        while (x!=0){
            cout << "1: Test Size partendo da vec" << endl;
            cout << "2: Test collisioni" << endl;
            cout << "3: Test Resize" << endl;
            cout << "4: Test Clear" << endl;
            cout << "5: Test Some" << endl;
            if (type == 1){cout << "6: Test Size in double Insert" << endl;}
            cout << "0: Tornare indietro" << endl;

            cin >> x;

            if (x == 1 && type == 1){
                cout << "Test Size" << endl;
        
                lasd::HashTableClsAdr<int> ht(10);
                cout <<"Table creata con tablesize==10" << endl;
                cout <<"size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(5);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(11);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(15);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 3" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(15);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(11);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Clear table" << endl;
                cout << "size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::Vector<int> vec(10);
                pieno19(vec, 10);
                cout << "Creazione vec" << endl;

                lasd::HashTableClsAdr<int> ht1(vec);
                lasd::HashTableClsAdr<int> ht2(10, vec);
                lasd::HashTableClsAdr<int> ht3(5, vec);
                cout << "Accesso a size del primo: " << ht1.Size() << endl;
                cout << "Accesso a size del secondo: " << ht2.Size() << endl;
                cout << "Accesso a size del terzo: " << ht3.Size() << endl;

                ht1.Resize(254);
                cout << "Accesso a size dopo Resize: " << ht1.Size() << endl;
                lasd::HashTableClsAdr<int> ht4(254);
                for(int i = 0; i < 10; ++i){
                    ht4.Insert(i);
                }
                cout << "Accesso a size di table uguale a quella con la resize: " << ht4.Size() << endl;
                if (ht1 == ht4){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                lasd::HashTableClsAdr<int> ht5(150, vec);
                lasd::HashTableClsAdr<int> ht6(120, vec);
                cout << "Accesso a size: " << ht5.Size() << endl;
                cout << "Accesso a size: " << ht6.Size() << endl;
            }
            else if (x == 1 && type == 2){
                cout << "Test Size" << endl;
        
                lasd::HashTableClsAdr<double> ht(10.1);
                cout <<"Table creata con tablesize==10" << endl;
                cout <<"size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(5.7);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(11.4);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(15.6);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 3" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(15.6);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(11.4);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Clear table" << endl;
                cout << "size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::Vector<double> vec(10);
                pieno19(vec, 10);
                cout << "Creazione vec" << endl;

                lasd::HashTableClsAdr<double> ht1(vec);
                lasd::HashTableClsAdr<double> ht2(10, vec);
                lasd::HashTableClsAdr<double> ht3(5, vec);
                cout << "Accesso a size del primo: " << ht1.Size() << endl;
                cout << "Accesso a size del secondo: " << ht2.Size() << endl;
                cout << "Accesso a size del terzo: " << ht3.Size() << endl;

                ht1.Resize(254);
                cout << "Accesso a size dopo Resize: " << ht1.Size() << endl;
                lasd::HashTableClsAdr<double> ht4(254);
                for(int i = 0; i < 10; ++i){
                    ht4.Insert(i);
                }
                cout << "Accesso a size di table uguale a quella con la resize: " << ht4.Size() << endl;
                if (ht1 == ht4){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                lasd::HashTableClsAdr<double> ht5(150, vec);
                lasd::HashTableClsAdr<double> ht6(120, vec);
                cout << "Accesso a size: " << ht5.Size() << endl;
                cout << "Accesso a size: " << ht6.Size() << endl;
            }
            else if (x == 1 && type == 3){
                cout << "Test Size" << endl;
        
                lasd::HashTableClsAdr<string> ht(10);
                cout <<"Table creata con tablesize==10" << endl;
                cout <<"size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert("bbt");
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert("allor");
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert("test");
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 3" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove("test");
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove("allor");
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Clear table" << endl;
                cout << "size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::Vector<string> vec(10);
                pienoxString(vec, 10);
                cout << "Creazione vec" << endl;

                lasd::HashTableClsAdr<string> ht1(vec);
                lasd::HashTableClsAdr<string> ht2(10, vec);
                lasd::HashTableClsAdr<string> ht3(5, vec);
                cout << "Accesso a size del primo: " << ht1.Size() << endl;
                cout << "Accesso a size del secondo: " << ht2.Size() << endl;
                cout << "Accesso a size del terzo: " << ht3.Size() << endl;

                ht1.Resize(254);
                cout << "Accesso a size dopo Resize: " << ht1.Size() << endl;
                // lasd::HashTableOpnAdr<string> ht4(254);
                // for(int i = 0; i < 10; ++i){
                //     ht4.Insert(i);
                // }
                // cout << "Accesso a size di table uguale a quella con la resize: " << ht4.Size() << endl;
                // if (ht1 == ht4){
                //     cout << "Uguali" << endl;
                // }
                // else {
                //     cout << "Diversi" << endl;
                // }

                lasd::HashTableClsAdr<string> ht5(150, vec);
                lasd::HashTableClsAdr<string> ht6(120, vec);
                cout << "Accesso a size: " << ht5.Size() << endl;
                cout << "Accesso a size: " << ht6.Size() << endl;
            }
            else if (x == 2 && type == 1){
                lasd::Vector<int> vec1(125);
                pieno19(vec1, 125);
                lasd::HashTableClsAdr<int> ht1(vec1);
                cout << "Creazione prima hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht1.Size() << endl;
                lasd::HashTableClsAdr<int> ht2(10, vec1);
                cout << "Creazione seconda hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                
                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                ht1.Clear(); ht2.Clear();
                cout << "Clear effettuate" << endl;

                lasd::Vector<int> vec2(250);
                pieno19(vec2, 250);
                ht1.InsertAll(vec2);
                ht2.InsertAll(vec2);
                cout << "Inserimento nelle due tabelle" << endl;

                cout << "Size dovrebbe essere 250, accesso a size: " << ht1.Size() << endl;
                cout << "Size dovrebbe essere 250, accesso a size: " << ht2.Size() << endl;

                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                lasd::HashTableClsAdr<int> ht3(vec2);
                cout << "Creazione terza hashtable";
                cout << "Size dovrebbe essere 250, accesso a size: " << ht3.Size() << endl;

                if (ht1 == ht3){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht3){
                    cout << "Confronto diversi" << endl;
                }
            }
            else if (x==2 && type == 2){
                lasd::Vector<double> vec1(125);
                pieno19(vec1, 125);
                lasd::HashTableClsAdr<double> ht1(vec1);
                cout << "Creazione prima hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht1.Size() << endl;
                lasd::HashTableClsAdr<double> ht2(10, vec1);
                cout << "Creazione seconda hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                
                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                ht1.Clear(); ht2.Clear();
                cout << "Clear effettuate" << endl;

                lasd::Vector<double> vec2(250);
                pieno19(vec2, 250);
                ht1.InsertAll(vec2);
                ht2.InsertAll(vec2);
                cout << "Inserimento nelle due tabelle" << endl;

                cout << "Size dovrebbe essere 250, accesso a size: " << ht1.Size() << endl;
                cout << "Size dovrebbe essere 250, accesso a size: " << ht2.Size() << endl;

                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                lasd::HashTableClsAdr<double> ht3(vec2);
                cout << "Creazione terza hashtable";
                cout << "Size dovrebbe essere 250, accesso a size: " << ht3.Size() << endl;

                if (ht1 == ht3){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht3){
                    cout << "Confronto diversi" << endl;
                }
            }
            else if (x == 2 && type == 3){
                lasd::Vector<string> vec1(125);
                pienoxString(vec1, 125);
                lasd::HashTableClsAdr<string> ht1(vec1);
                cout << "Creazione prima hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht1.Size() << endl;
                lasd::HashTableClsAdr<string> ht2(10, vec1);
                cout << "Creazione seconda hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                
                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                ht1.Clear(); ht2.Clear();
                cout << "Clear effettuate" << endl;

                lasd::Vector<string> vec2(250);
                pienoxString(vec1, 250);
                ht1.InsertAll(vec2);
                ht2.InsertAll(vec2);
                cout << "Inserimento nelle due tabelle" << endl;

                cout << "Size dovrebbe essere 250, accesso a size: " << ht1.Size() << endl;
                cout << "Size dovrebbe essere 250, accesso a size: " << ht2.Size() << endl;

                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                lasd::HashTableClsAdr<string> ht3(vec2);
                cout << "Creazione terza hashtable";
                cout << "Size dovrebbe essere 250, accesso a size: " << ht3.Size() << endl;

                if (ht1 == ht3){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht3){
                    cout << "Confronto diversi" << endl;
                }
            }
            else if (x == 3 && type == 1){
                lasd::Vector<int> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableClsAdr<int> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                lasd::HashTableClsAdr<int> ht2(1, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                lasd::HashTableClsAdr<int> ht3 (5, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht3.Size() << endl;

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                ht3.Clear();
                ht3.Resize(83);
                ht3.InsertAll(vec);

                ht2.Resize(40);

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
            }
            else if (x == 3 && type == 2){
                lasd::Vector<double> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableClsAdr<double> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                lasd::HashTableClsAdr<double> ht2(1, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                lasd::HashTableClsAdr<double> ht3 (5, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht3.Size() << endl;

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                ht3.Clear();
                ht3.Resize(83);
                ht3.InsertAll(vec);

                ht2.Resize(40);

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
            }
            else if (x == 3 && type == 3){
                lasd::Vector<string> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableClsAdr<string> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                lasd::HashTableClsAdr<string> ht2(1, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                lasd::HashTableClsAdr<string> ht3 (5, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht3.Size() << endl;

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                ht3.Clear();
                ht3.Resize(83);
                ht3.InsertAll(vec);

                ht2.Resize(40);

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }
            }
            else if (x == 4 && type == 1){
                lasd::Vector<int> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableClsAdr<int> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                ht.Clear();
                cout << "Clear effettuata"<< endl;
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                for (unsigned int i = 0; i < vec.Size() ; ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                ht.InsertAll(vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
            }
            else if (x==4 && type == 2){
                lasd::Vector<double> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableClsAdr<double> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                ht.Clear();
                cout << "Clear effettuata"<< endl;
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                for (unsigned int i = 0; i < vec.Size() ; ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                ht.InsertAll(vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
            }
            else if (x == 4 && type == 3){
                lasd::Vector<string> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableClsAdr<string> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                ht.Clear();
                cout << "Clear effettuata"<< endl;
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                for (unsigned int i = 0; i < vec.Size() ; ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                ht.InsertAll(vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
            }
            else if (x == 5 && type == 1){
                lasd::Vector<int> vec(57);
                pieno19(vec, 57);

                lasd::HashTableClsAdr<int> ht1(10);
                ht1.InsertSome(vec);
                lasd::HashTableClsAdr<int> ht2(40);
                ht2.InsertSome(vec);

                if (ht1 == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Diversi" << endl;
                }

                ht1.RemoveSome(vec);
                ht2.RemoveSome(vec);
            }
            else if (x==5 && type == 2){
                lasd::Vector<double> vec(57);
                pieno19(vec, 57);

                lasd::HashTableClsAdr<double> ht1(10);
                ht1.InsertSome(vec);
                lasd::HashTableClsAdr<double> ht2(40);
                ht2.InsertSome(vec);

                if (ht1 == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Diversi" << endl;
                }

                ht1.RemoveSome(vec);
                ht2.RemoveSome(vec);
            }
            else if (x == 5 && type == 3){
                lasd::Vector<string> vec(57);
                pienoxString(vec, 57);

                lasd::HashTableClsAdr<string> ht1(10);
                ht1.InsertSome(vec);
                lasd::HashTableClsAdr<string> ht2(40);
                ht2.InsertSome(vec);

                if (ht1 == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Diversi" << endl;
                }

                ht1.RemoveSome(vec);
                ht2.RemoveSome(vec);
            }
            else if (x == 6){
                lasd::Vector<int> vec(20);
                pieno19(vec, 20);

                cout << "Creazione HashTable" << endl;
                lasd::HashTableClsAdr<int> ht(vec);

                cout << "Size dovrebbe essere: 20" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                cout << "Re-insert del contenitore in HashTable" << endl;
                for (unsigned long i = 0; i < vec.Size(); ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere: 20" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                cout << "Rimozione degli elementi di Hashtable" << endl;
                ht.Clear();
                cout << "Size dovrebbe essere: 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                for (unsigned long i = 0; i < vec.Size(); ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere: 20" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;
            }
        }
    }
    void MenuHashOpn(int type){
        cout << "Test HashTableOpnAdr" << endl;
        int x = -1;
        while(x!=0){
            cout << "1: Test Size partendo da vec" << endl;
            cout << "2: Test collisioni" << endl;
            cout << "3: Test Clear" << endl;
            cout << "4: Test Some" << endl;
            if (type == 1){cout << "5: Test costruttore default" << endl;}
            if (type == 1){cout << "6: Test Size su double Insert" << endl;}
            cout << "0: Per tornare indietro" << endl;

            cin>> x;

            if (x == 1 && type == 1){
                cout << "Test Size" << endl;
        
                lasd::HashTableOpnAdr<int> ht(10);
                cout <<"Table creata con tablesize==10" << endl;
                cout <<"size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(5);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(11);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(15);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 3" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(15);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(11);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Clear table" << endl;
                cout << "size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::Vector<int> vec(10);
                pieno19(vec, 10);
                cout << "Creazione vec" << endl;

                lasd::HashTableOpnAdr<int> ht1(vec);
                lasd::HashTableOpnAdr<int> ht2(10, vec);
                lasd::HashTableOpnAdr<int> ht3(5, vec);
                cout << "Accesso a size del primo: " << ht1.Size() << endl;
                cout << "Accesso a size del secondo: " << ht2.Size() << endl;
                cout << "Accesso a size del terzo: " << ht3.Size() << endl;

                ht1.Resize(254);
                cout << "Accesso a size dopo Resize: " << ht1.Size() << endl;
                lasd::HashTableOpnAdr<int> ht4(254);
                for(int i = 0; i < 10; ++i){
                    ht4.Insert(i);
                }
                cout << "Accesso a size di table uguale a quella con la resize: " << ht4.Size() << endl;
                if (ht1 == ht4){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                lasd::HashTableOpnAdr<int> ht5(150, vec);
                lasd::HashTableOpnAdr<int> ht6(120, vec);
                cout << "Accesso a size: " << ht5.Size() << endl;
                cout << "Accesso a size: " << ht6.Size() << endl;
            }
            else if (x == 1 && type == 2){
                cout << "Test Size" << endl;
        
                lasd::HashTableOpnAdr<double> ht(10.1);
                cout <<"Table creata con tablesize==10" << endl;
                cout <<"size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(5.7);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(11.4);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert(15.6);
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 3" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(15.6);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove(11.4);
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Clear table" << endl;
                cout << "size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::Vector<double> vec(10);
                pieno19(vec, 10);
                cout << "Creazione vec" << endl;

                lasd::HashTableOpnAdr<double> ht1(vec);
                lasd::HashTableOpnAdr<double> ht2(10, vec);
                lasd::HashTableOpnAdr<double> ht3(5, vec);
                cout << "Accesso a size del primo: " << ht1.Size() << endl;
                cout << "Accesso a size del secondo: " << ht2.Size() << endl;
                cout << "Accesso a size del terzo: " << ht3.Size() << endl;

                ht1.Resize(254);
                cout << "Accesso a size dopo Resize: " << ht1.Size() << endl;
                lasd::HashTableOpnAdr<double> ht4(254);
                for(int i = 0; i < 10; ++i){
                    ht4.Insert(i);
                }
                cout << "Accesso a size di table uguale a quella con la resize: " << ht4.Size() << endl;
                if (ht1 == ht4){
                    cout << "Uguali" << endl;
                }
                else {
                    cout << "Diversi" << endl;
                }

                lasd::HashTableOpnAdr<double> ht5(150, vec);
                lasd::HashTableOpnAdr<double> ht6(120, vec);
                cout << "Accesso a size: " << ht5.Size() << endl;
                cout << "Accesso a size: " << ht6.Size() << endl;
            }
            else if (x == 1 && type == 3){
                cout << "Test Size" << endl;
        
                lasd::HashTableOpnAdr<string> ht(10);
                cout <<"Table creata con tablesize==10" << endl;
                cout <<"size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert("bbt");
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert("allor");
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Insert("test");
                cout <<"Inserito dato" << endl;
                cout << "size dovrebbe essere 3" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove("test");
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 2" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Remove("allor");
                cout <<"Rimozione dato" << endl;
                cout << "size dovrebbe essere 1" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Clear table" << endl;
                cout << "size dovrebbe essere 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::Vector<string> vec(10);
                pienoxString(vec, 10);
                cout << "Creazione vec" << endl;

                lasd::HashTableOpnAdr<string> ht1(vec);
                lasd::HashTableOpnAdr<string> ht2(10, vec);
                lasd::HashTableOpnAdr<string> ht3(5, vec);
                cout << "Accesso a size del primo: " << ht1.Size() << endl;
                cout << "Accesso a size del secondo: " << ht2.Size() << endl;
                cout << "Accesso a size del terzo: " << ht3.Size() << endl;

                ht1.Resize(254);
                cout << "Accesso a size dopo Resize: " << ht1.Size() << endl;
                // lasd::HashTableOpnAdr<string> ht4(254);
                // for(int i = 0; i < 10; ++i){
                //     ht4.Insert(i);
                // }
                // cout << "Accesso a size di table uguale a quella con la resize: " << ht4.Size() << endl;
                // if (ht1 == ht4){
                //     cout << "Uguali" << endl;
                // }
                // else {
                //     cout << "Diversi" << endl;
                // }

                lasd::HashTableOpnAdr<string> ht5(150, vec);
                lasd::HashTableOpnAdr<string> ht6(120, vec);
                cout << "Accesso a size: " << ht5.Size() << endl;
                cout << "Accesso a size: " << ht6.Size() << endl;
            }

            else if (x == 2 && type == 1){
                lasd::Vector<int> vec1(125);
                pieno19(vec1, 125);
                lasd::HashTableOpnAdr<int> ht1(vec1);
                cout << "Creazione prima hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht1.Size() << endl;
                lasd::HashTableOpnAdr<int> ht2(10, vec1);
                cout << "Creazione seconda hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                
                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                ht1.Clear(); ht2.Clear();
                cout << "Clear effettuate" << endl;

                lasd::Vector<int> vec2(250);
                pieno19(vec2, 250);
                ht1.InsertAll(vec2);
                ht2.InsertAll(vec2);
                cout << "Inserimento nelle due tabelle" << endl;

                cout << "Size dovrebbe essere 250, accesso a size: " << ht1.Size() << endl;
                cout << "Size dovrebbe essere 250, accesso a size: " << ht2.Size() << endl;

                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                lasd::HashTableOpnAdr<int> ht3(vec2);
                cout << "Creazione terza hashtable";
                cout << "Size dovrebbe essere 250, accesso a size: " << ht3.Size() << endl;

                if (ht1 == ht3){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht3){
                    cout << "Confronto diversi" << endl;
                }
            }
            else if (x==2 && type == 2){
                lasd::Vector<double> vec1(125);
                pieno19(vec1, 125);
                lasd::HashTableOpnAdr<double> ht1(vec1);
                cout << "Creazione prima hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht1.Size() << endl;
                lasd::HashTableOpnAdr<double> ht2(10, vec1);
                cout << "Creazione seconda hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                
                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                ht1.Clear(); ht2.Clear();
                cout << "Clear effettuate" << endl;

                lasd::Vector<double> vec2(250);
                pieno19(vec2, 250);
                ht1.InsertAll(vec2);
                ht2.InsertAll(vec2);
                cout << "Inserimento nelle due tabelle" << endl;

                cout << "Size dovrebbe essere 250, accesso a size: " << ht1.Size() << endl;
                cout << "Size dovrebbe essere 250, accesso a size: " << ht2.Size() << endl;

                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                lasd::HashTableOpnAdr<double> ht3(vec2);
                cout << "Creazione terza hashtable";
                cout << "Size dovrebbe essere 250, accesso a size: " << ht3.Size() << endl;

                if (ht1 == ht3){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht3){
                    cout << "Confronto diversi" << endl;
                }
            }
            else if (x == 2 && type == 3){
                lasd::Vector<string> vec1(125);
                pienoxString(vec1, 125);
                lasd::HashTableOpnAdr<string> ht1(vec1);
                cout << "Creazione prima hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht1.Size() << endl;
                lasd::HashTableOpnAdr<string> ht2(10, vec1);
                cout << "Creazione seconda hashtable" << endl;
                cout << "Size dovrebbe essere 125, accesso a size: " << ht2.Size() << endl;
                
                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                ht1.Clear(); ht2.Clear();
                cout << "Clear effettuate" << endl;

                lasd::Vector<string> vec2(250);
                pienoxString(vec1, 250);
                ht1.InsertAll(vec2);
                ht2.InsertAll(vec2);
                cout << "Inserimento nelle due tabelle" << endl;

                cout << "Size dovrebbe essere 250, accesso a size: " << ht1.Size() << endl;
                cout << "Size dovrebbe essere 250, accesso a size: " << ht2.Size() << endl;

                if (ht1 == ht2){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Confronto diversi" << endl;
                }

                lasd::HashTableOpnAdr<string> ht3(vec2);
                cout << "Creazione terza hashtable";
                cout << "Size dovrebbe essere 250, accesso a size: " << ht3.Size() << endl;

                if (ht1 == ht3){
                    cout << "Confronto uguali" << endl;
                }
                if (ht1 != ht3){
                    cout << "Confronto diversi" << endl;
                }
            }
            else if (x == 3 && type == 1){
                lasd::Vector<int> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableOpnAdr<int> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                ht.Clear();
                cout << "Clear effettuata"<< endl;
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                for (unsigned int i = 0; i < vec.Size() ; ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                ht.InsertAll(vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
            }
            else if (x==3 && type == 2){
                lasd::Vector<double> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableOpnAdr<double> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                ht.Clear();
                cout << "Clear effettuata"<< endl;
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                for (unsigned int i = 0; i < vec.Size() ; ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                ht.InsertAll(vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
            }
            else if (x == 3 && type == 3){
                lasd::Vector<string> vec(127);
                for (uint i = 0; i < 127; i++) {
                    vec[i] = pow(-2, i % 24) * ((61 * i + 29) % 127);
                }

                lasd::HashTableOpnAdr<string> ht(83, vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
                ht.Clear();
                cout << "Clear effettuata"<< endl;
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                for (unsigned int i = 0; i < vec.Size() ; ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;

                ht.Clear();
                cout << "Size dovrebbe essere 0, accesso a size: " << ht.Size() << endl;
                ht.InsertAll(vec);
                cout << "Size dovrebbe essere 125, accesso a size: " << ht.Size() << endl;
            }
            else if (x == 4 && type == 1){
                lasd::Vector<int> vec(57);
                pieno19(vec, 57);

                lasd::HashTableOpnAdr<int> ht1(10);
                ht1.InsertSome(vec);
                lasd::HashTableOpnAdr<int> ht2(40);
                ht2.InsertSome(vec);

                if (ht1 == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Diversi" << endl;
                }

                ht1.RemoveSome(vec);
                ht2.RemoveSome(vec);
            }
            else if (x==4 && type == 2){
                lasd::Vector<double> vec(57);
                pieno19(vec, 57);

                lasd::HashTableOpnAdr<double> ht1(10);
                ht1.InsertSome(vec);
                lasd::HashTableOpnAdr<double> ht2(40);
                ht2.InsertSome(vec);

                if (ht1 == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Diversi" << endl;
                }

                ht1.RemoveSome(vec);
                ht2.RemoveSome(vec);
            }
            else if (x == 4 && type == 3){
                lasd::Vector<string> vec(57);
                pienoxString(vec, 57);

                lasd::HashTableOpnAdr<string> ht1(10);
                ht1.InsertSome(vec);
                lasd::HashTableOpnAdr<string> ht2(40);
                ht2.InsertSome(vec);

                if (ht1 == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht1 != ht2){
                    cout << "Diversi" << endl;
                }

                ht1.RemoveSome(vec);
                ht2.RemoveSome(vec);
            }
            else if (x == 5){
                lasd::HashTableOpnAdr<int> ht{};
                bool empty = ht.Empty();
                if (empty)
                cout << "Empty" << endl;
                else
                cout << "Not Empty" << endl;

                cout << "Accesso a size: " << ht.Size() << endl;

                lasd::HashTableOpnAdr<int> ht2{};
                bool empty2 = ht2.Empty();
                if (empty2)
                cout << "Empty" << endl;
                else
                cout << "Not Empty" << endl;

                cout << "Accesso a size: " << ht2.Size() << endl;

                if (ht == ht2){
                    cout << "Uguali" << endl;
                }
                if (ht != ht2){
                    cout << "Diversi" << endl;
                }

                lasd::HashTableOpnAdr<int> ht3{32};
                bool empty3 = ht3.Empty();
                if (empty3)
                cout << "Empty" << endl;
                else
                cout << "Not Empty" << endl;

                cout << "Accesso a size: " << ht3.Size() << endl;

                if (ht == ht3){
                    cout << "Uguali" << endl;
                }
                if (ht != ht3){
                    cout << "Diversi" << endl;
                }
            }
            else if (x == 6){
                lasd::Vector<int> vec(20);
                pieno19(vec, 20);

                cout << "Creazione HashTable" << endl;
                lasd::HashTableOpnAdr<int> ht(vec);

                cout << "Size dovrebbe essere: 20" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                cout << "Re-insert del contenitore in HashTable" << endl;
                for (unsigned long i = 0; i < vec.Size(); ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere: 20" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                cout << "Rimozione degli elementi di Hashtable" << endl;
                ht.Clear();
                cout << "Size dovrebbe essere: 0" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;

                for (unsigned long i = 0; i < vec.Size(); ++i){
                    ht.Insert(vec[i]);
                }
                cout << "Size dovrebbe essere: 20" << endl;
                cout << "Accesso a size: " << ht.Size() << endl;
            }
        }
    }

    void testPersonal3(){
        cout << "Inizio Test Hash Table" << endl;
        int scelta = -1; int type = -1;
        while (scelta != 0){
            while (type != 0){
                cout << "Su quale tipo vuoi testare" << endl;
                cout << "1: int"<< endl;
                cout << "2: double" << endl;
                cout << "3: string" << endl;
                cout << "0: out" << endl;
                cin >> type;

                cout << "1: Testing Close Addressing" << endl;
                cout << "2: Testing Open Addressing" << endl;
                cout << "0: Per terminare il test" << endl;
                cin >> scelta;

                if (scelta == 1){
                    MenuHashCls(type);
                }
                else if (scelta == 2){
                    MenuHashOpn(type);
                }       
            }

        }
        cout << "Fine test hashTable" << endl;
    }

}