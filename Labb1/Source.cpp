//Kasper Rosenberg karo5568
#include <iostream>
#include <vector>


using namespace std;

struct Person
{
    string fnamn;
    string enamn;
    string nummer;
};

void visa_person(vector<Person> tfnregister, string fnamn)
{
    bool notFound = true;
    for (Person p : tfnregister) {
        if (p.fnamn == (fnamn)) {
            cout << p.fnamn << " " << p.enamn << ": " << p.nummer << endl;
            notFound = false;
        }
    }
    if (notFound) {
        cout << "Hittade inget nummer!" << endl;
    }
}

void skriv_hela_telefonreg(vector<Person> tfnregister)
{
    for (Person p : tfnregister)
        cout << p.fnamn << " " << p.enamn << ": " << p.nummer << endl;

}

void ny_person(vector<Person>& tfnregister, string fnamn, string enamn, string nummer)
{
    Person p;
    p.fnamn = fnamn;
    p.enamn = enamn;
    p.nummer = nummer;
    tfnregister.push_back(p);
}

void ta_bort_person(vector<Person>& tfnregister, string fnamn)
{
    for (auto iter = tfnregister.begin(); iter != tfnregister.end();) {
        if ((*iter).fnamn == (fnamn)) {
            cout << (*iter).fnamn << " " << (*iter).enamn << " tas nu bort." << endl;
            iter = tfnregister.erase(iter);
        }
        else {
            iter++;
        }

    }
}

int main()
{
    vector<Person>tfnregister;

    Person christina;
    christina.fnamn = "Christina";
    christina.enamn = "Nyberg";
    christina.nummer = "0707423653";

    Person josefin;
    josefin.fnamn = "Josefin";
    josefin.enamn = "Danielsson";
    josefin.nummer = "0705463245";

    Person ellen;
    ellen.fnamn = "Ellen";
    ellen.enamn = "Lindgren";
    ellen.nummer = "0705643229";

    Person stig;
    stig.fnamn = "Stig";
    stig.enamn = "Ek";
    stig.nummer = "0705673247";

    Person linus;
    linus.fnamn = "Linus";
    linus.enamn = "Jonasson";
    linus.nummer = "0703457923";

    Person adam;
    adam.fnamn = "Adam";
    adam.enamn = "Nordin";
    adam.nummer = "0203456297";

    tfnregister.push_back(christina);
    tfnregister.push_back(josefin);
    tfnregister.push_back(ellen);
    tfnregister.push_back(stig);
    tfnregister.push_back(linus);
    tfnregister.push_back(adam);

    string fnamn, enamn, nummer;
    char kommando;
    do {
        cout << "Kommando: ";
        cin >> kommando;
        switch (kommando) {
        case 'n':
            cin >> fnamn >> enamn >> nummer;
            ny_person(tfnregister, fnamn, enamn, nummer);
            break;

        case 'v':
            cin >> fnamn;
            visa_person(tfnregister, fnamn);
            break;

        case 's':
            skriv_hela_telefonreg(tfnregister);
            break;

        case 'd':
            cin >> fnamn;
            ta_bort_person(tfnregister, fnamn);
            break;
        }
    } while (kommando != 'q');
    cout << "Hejdå!";

    return 0;
}

