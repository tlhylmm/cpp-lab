#define _CRT_SECURE_NO_WARNINGS 1 //for localtime function
#include <iostream>
#include <conio.h> //to use _getch()
#include <string>
#include <sstream> //will be used in calculateDays()
#include <iomanip> //will be used in calculateDays()
#include <fstream> //file operations
#include <cstdio> //for file operations
#include <ctime> //will be used in calculateDays()
#include <clocale> //for turkish characters

using namespace std;

/* Arrays -> used in buildUserFromDatabase()
 * Pointers -> used in getID, buildUserFromDatabase() and calculateDays()
 * Strings -> used in all functions
 * Structs -> used to define a person with registration properties
 * File I/o -> used in nearly all functions
 *
 * Some info about functions:
 *
 * getID() function only checks if the given ID is in correct form.
 * It modifies the default ID variable created by other functions.
 * It doesn't check if given ID is in the database. checkID() function
 * does that job.
 *
 * checkID() searches the database and returns true if the given ID is in database.
 *
 * buildUserFromDatabase() function takes the ID and "user" type structure variable
 * and it finds the ID in the database. Then it assigns the values to members of user variable.
 * It doesn't check if the ID is in the database.
 * So, before calling the function; checkID() is used to check if ID is in database.
 * Before it assigns, the values held in an array with eight elements:
 * 0- ID
 * 1- Name
 * 2- Surname
 * 3- Age
 * 4- City
 * 5- Last Vaccination Date
 * 6- Vaccination Count
 * 7- Vaccination Type
 * This function basically creates this array and then matches these elements
 * with user structure members.
 *
 * calculateDays() uses ctime library to take system date
 * it does conversions between tm struct and time_t type variables
 * so when making a new vaccine appointment. date will be taken from system.
 */

struct user {
    /* size of the structure is 152 when calculated with sizeof()
     * it doesn't change if int variables moved to bottom or top
     * so member order can stay in the same order as in the PDF:
     */
    string ID;
    string name;
    string surname;
    int age;
    string city;
    string lastVacDate;
    int vacCount;
    string vacType;
};

//defining prototypes:
void registration(); //register new user
void setDefault(string ID); //set default time, vaccine type and number for new user
void view(); //view info about registered user
void update(); //update registered user info
void newVaccine(); //new vaccine for registered user
void getID(string& ID); //get ID and check if it's in correct form
void buildUserFromDatabase(string ID, user& yeni); //build user from database 
int calculateDays(string lastVacDate, string* appointment); //calculate days between dates
bool checkID(string ID); //check if given ID is in the database

int main() {
    setlocale(LC_ALL, "Turkish");
    string navigator; //will be used to navigate through functions 

    while (true) {
        for (int i = 0; i < 51; i++) { cout << "="; }
        cout << "\n\t\tCOVID Asi Sistemi\n";
        cout << "(Butun islemlerden \"exit\" yazarak cikabilirsiniz.)\n";
        for (int i = 0; i < 51; i++) { cout << "="; }
        cout << "\nNumaralari kullanarak islemlere erisebilirsiniz:\n"
            << "\n(1) Yeni Kayit\n"
            << "(2) Kayit Goruntule\n"
            << "(3) Kayit Guncelle\n"
            << "(4) Yeni Asi Kaydi\n"
            << "(5) Cikis\n";
        cout << "\nNe yapmak istiyorsunuz? -> ";
        cin >> ws; //discard the input buffer (to make getline work properly)
        getline(cin, navigator);
        if (navigator == "1") {
            system("cls"); //clear the console
            registration();
        }
        else if (navigator == "2") {
            system("cls"); //clear the console
            view();
        }
        else if (navigator == "3") {
            system("cls"); //clear the console
            update();
        }
        else if (navigator == "4") {
            system("cls"); //clear the console
            newVaccine();
        }
        else if (navigator == "exit" || navigator == "5") { exit(0); }
        else {
            cout << "Yanlis giris yaptiniz. Tekrar denemek icin bir tusa basin.\n";
            _getch();
            system("cls"); //clear the console
            main();
        }
    }
    return 0;
}

void registration() {
    string ID; //this variable will be sent to getID and and got changed
    string currentLine;
    for (int i = 0; i < 51; i++) { cout << "="; }
    cout << "\n\t\tYeni kayit" << endl;
    cout << "(Butun islemlerden \"exit\" yazarak cikabilirsiniz.)\n";
    for (int i = 0; i < 51; i++) { cout << "="; }

    getID(ID); //Get new ID

    //prompt error if ID is already in database:
    if (checkID(ID) == true) {
        cout << "\nGirilen ID zaten sistemde kayitli. Bilgilerinizi degistirmek icin kayit guncelleyebilirsiniz."
            << "\n\nDevam etmek icin bir tusa basiniz.";
        _getch();
        system("cls"); //clear the console

    }

    //register if ID is not in database:
    else if (checkID(ID) == false) {
        user yeni; //create a new user
        yeni.ID = ID; //Assign the ID to new user's ID

        //Get new user's informations:
        cout << "\n(Lutfen yeni kayit bilgilerini giriniz. Cift isimler arasinda \"-\" kullaniniz.)\nIsim: ";
        cin >> yeni.name;
        cout << "Soyisim: ";
        cin >> yeni.surname;

        //get age and check if it contains digits:
        string ageStr; //user can put both letters and digits in this. we'll check it later
        while (true) {
            cout << "Yas: ";
            cin >> ageStr;

            //check the string
            int len = ageStr.size();
            bool notDigit = false;
            for (int i = 0; i < len; i++) {
                if (isdigit(ageStr[i]) == 0) {
                    notDigit = true;
                    break;
                }
            }

            if (notDigit == true) {
                cout << "Yasiniz sadece sayilardan olusmalidir." << endl;
            }
            else {
                yeni.age = stoi(ageStr);
                break;
            }
        }

        cout << "Sehir: ";
        cin >> yeni.city;

        //open the database file and append new user's info to the end.
        fstream database("database.txt", ios::app);
        database << yeni.ID << " " << yeni.name << " " << yeni.surname << " "
            << yeni.age << " " << yeni.city << endl;
        database.close();
        setDefault(ID); //call setDefault to append default values
        cout << "\n" << yeni.ID << " kimlikli " << yeni.name << " " << yeni.surname
            << " (" << yeni.age << "/" << yeni.city << ") icin kayit olusturulmustur."
            << "\nYeni asi kaydi yapabilir veya hatali bilgi girdiyseniz kayit guncelleyebilirsiniz." << endl;
        cout << "\nDevam etmek icin bir tusa basiniz.";
        _getch();
        system("cls"); //clear the console
    }
}

void setDefault(string ID) {
    /* the plan is to create a new file, find the line to be changed,
     * append default info to the end of the line and put it into
     * new database file. keep copying the other lines while searching.
     * then delete the old database.txt and rename the new one to same name
     */

    string currentLine;
    ifstream database("database.txt"); //open database in readmode
    ofstream newDatabase("newDatabase.txt"); //create a new file to write updated database
    while (getline(database, currentLine)) {
        //append default values when ID match is found:
        if (ID[0] == currentLine[0] && ID[1] == currentLine[1]
            && ID[2] == currentLine[2] && ID[3] == currentLine[3])
        {
            currentLine = currentLine + " 01.06.2020 0 NULL";
            newDatabase << currentLine << endl;
        }
        //keep copying lines until there is a ID match: 
        else { newDatabase << currentLine << endl; }
    }
    database.close();
    newDatabase.close();
    int status = remove("database.txt"); //delete old database
    rename("newDatabase.txt", "database.txt"); //rename updated database
}

void view() {
    string currentLine, ID, retry;

    for (int i = 0; i < 51; i++) { cout << "="; }
    cout << "\n\t\tKayit Goruntule" << endl;
    cout << "(Butun islemlerden \"exit\" yazarak cikabilirsiniz.)\n";
    for (int i = 0; i < 51; i++) { cout << "="; }

    while (true) { //infinite loop to try again until ID is found
        getID(ID); //Get correct ID from user              

        /* If ID match is found in database, display the info and end the view function
         * by breaking infinite loop. If match is not found in database. Keep looping and
         * ask for ID again.
         */
        if (checkID(ID) == true) {
            user kullanici;
            buildUserFromDatabase(ID, kullanici);

            cout << "\nID: " << kullanici.ID << endl
                << "Isim: " << kullanici.name << endl
                << "Soyisim: " << kullanici.surname << endl
                << "Yas: " << kullanici.age << endl
                << "Sehir: " << kullanici.city << endl
                << "Son asi tarihi: " << kullanici.lastVacDate << endl
                << "Olunan asi sayisi: " << kullanici.vacCount << endl
                << "Asi turu: " << kullanici.vacType << endl;

            cout << "\nAna menuye donmek icin bir tusa basiniz.";
            _getch(); //stop and wait for keypress
            system("cls"); //clear the console
            break;
        }
        else if (checkID(ID) == false) {
            cout << "\nEslesen kayit bulunamadi. Yeniden denemek icin 1, cikmak icin herhangi bir sey yazabilirsiniz: ";
            getline(cin, retry);
            if (retry == "1") { continue; } //continue to run view function
            else {
                system("cls"); //clear the console
                break;
            } //break the loop and terminate view function
        }
    }
}

void update() {
    string ID, currentLine, retry, navigator;
    for (int i = 0; i < 51; i++) { cout << "="; }
    cout << "\n\t\tKayit Guncelle" << endl;
    cout << "(Butun islemlerden \"exit\" yazarak cikabilirsiniz.)\n";
    for (int i = 0; i < 51; i++) { cout << "="; }

    while (true) { //infinite loop to try again until ID is found in database
        getID(ID); //Get correct ID from user

        /* If ID match is found in database. End getting ID by breaking
         * infinite loop. If match is not found in database. Keep looping and
         * ask for ID again.
         */
        if (checkID(ID) == true) { break; }
        else if (checkID(ID) == false) {
            cout << "\nEslesen kayit bulunamadi. Yeniden denemek icin 1, cikmak icin herhangi bir sey yazabilirsiniz: ";
            getline(cin, retry);
            if (retry == "1") { continue; } //continue to run view function
            else {
                system("cls"); //clear the console
                break;
            }
        }
    }

    /* If ID is found in database
     * Rebuild the user with properties again
     * Print the info and ask which one to change
     * Rebuild the database with the same way as setDefault()
     * create a temp database > copy every unchanged line
     * > put the changed line > delete the old database
     * > rename the temp database as the new database
     */
    if (checkID(ID) == true) {
        user kullanici;
        buildUserFromDatabase(ID, kullanici);
        cout << "\n(1) ID: " << kullanici.ID
            << "\n(2) Isim: " << kullanici.name
            << "\n(3) Soyisim: " << kullanici.surname
            << "\n(4) Yas: " << kullanici.age
            << "\n(5) Sehir: " << kullanici.city << endl;

        //ask for which one to change:
        while (true) {
            cout << "\nHangi bilgiyi degistirmek istiyorsunuz? ";
            cin >> ws; //clear input buffer
            getline(cin, navigator);
            if (navigator == "1") {
                string newID;
                while (true) {
                    getID(newID);
                    //check if there is a conflict:
                    if (newID == kullanici.ID) {
                        cout << "Yeni ID'niz eskisi ile ayni.";
                        continue;
                    }
                    else if (checkID(newID) == false) {
                        kullanici.ID = newID;
                        cout << "Yeni ID'niz " << kullanici.ID << " olarak guncellenmistir.\n"
                            << "\nDevam etmek icin bir tusa basiniz.";
                        _getch();
                        system("cls"); //clear the console
                        break;
                    }
                    else {
                        cout << "Girdiginiz ID baska bir kayitli kullaniciya ait."
                            << " Farkli bir ID giriniz.";
                        continue;
                    }
                }
                break;
            }
            else if (navigator == "2") {
                string newName;
                cout << "\n(Cift isimler arasinda \"-\" kullaniniz.)\nLutfen yeni isim giriniz: ";
                cin >> ws; //clear input buffer
                getline(cin, newName);
                if (newName == "exit") {
                    system("cls"); //clear the console
                    break;
                }
                else {
                    kullanici.name = newName;
                    cout << "Yeni isminiz " << kullanici.name << " olarak guncellenmistir.\n"
                        << "\nDevam etmek icin bir tusa basiniz.";
                    _getch();
                    system("cls"); //clear the console
                    break;
                }

            }
            else if (navigator == "3") {
                string newSurname;
                cout << "\nLutfen yeni soyisim giriniz: ";
                cin >> ws; //clear input buffer
                getline(cin, newSurname);
                if (newSurname == "exit") {
                    system("cls"); //clear the console
                    break;
                }
                else {
                    kullanici.surname = newSurname;
                    cout << "Yeni soyisminiz " << kullanici.surname << " olarak guncellenmistir.\n"
                        << "\nDevam etmek icin bir tusa basiniz.";
                    _getch();
                    system("cls"); //clear the console
                    break;
                }
            }
            else if (navigator == "4") {
                string newAge;
                while (true) {
                    cout << "\nLutfen yeni yas giriniz: ";
                    cin >> ws; //clear input buffer
                    getline(cin, newAge);
                    if (newAge == "exit") {
                        system("cls"); //clear the console
                        break;
                    }
                    else {
                        //check if age contains only digits:
                        int len = newAge.size();
                        bool notDigit = false;
                        for (int i = 0; i < len; i++) {
                            if (isdigit(newAge[i]) == 0) {
                                notDigit = true;
                                break;
                            }
                        }
                        if (notDigit == true) {
                            cout << "Yeni yasiniz sayilardan olusmalidir." << endl;
                            continue;
                        }

                        //check if it is +18:
                        if (stoi(newAge) < 18) {
                            cout << "Yasiniz en az 18 olmalidir." << endl;
                        }
                        else { break; }

                    }
                }
                kullanici.age = stoi(newAge);
                cout << "Yeni yasiniz " << kullanici.age << " olarak guncellenmistir.\n"
                    << "\nDevam etmek icin bir tusa basiniz.";
                _getch();
                system("cls"); //clear the console
                break;


            }
            else if (navigator == "5") {
                string newCity;
                cout << "\nLutfen yeni sehir giriniz: ";
                cin >> ws; //clear input buffer
                getline(cin, newCity);
                if (newCity == "exit") {
                    system("cls"); //clear the console
                    break;
                }
                else {
                    kullanici.city = newCity;
                    cout << "Yeni sehriniz " << kullanici.city << " olarak guncellenmistir.\n"
                        << "\nDevam etmek icin bir tusa basiniz.";
                    _getch();
                    system("cls"); //clear the console
                    break;
                }

            }
            else if (navigator == "exit") {
                system("cls"); //clear the console
                main();
            }
            else {
                cout << "\nYanlis giris yaptiniz. Tekrar deneyebilir veya exit yazarak cikabilirsiniz.";
            }
        }

        //rebuild the database:
        ifstream database("database.txt"); //open database in readmode
        ofstream newDatabase("newDatabase.txt"); //create a new file to write updated database
        while (getline(database, currentLine)) {
            //change the line when ID match is found
            if (ID[0] == currentLine[0] && ID[1] == currentLine[1]
                && ID[2] == currentLine[2] && ID[3] == currentLine[3])
            {
                newDatabase << kullanici.ID << " " << kullanici.name << " " << kullanici.surname << " "
                    << kullanici.age << " " << kullanici.city << " "
                    << kullanici.lastVacDate << " " << kullanici.vacCount << " " << kullanici.vacType << endl;
            }
            //keep copying lines until there is a ID match: 
            else { newDatabase << currentLine << endl; }
        }
        database.close();
        newDatabase.close();
        int status = remove("database.txt"); //delete old database
        rename("newDatabase.txt", "database.txt"); //rename updated database
    }

}

void newVaccine() {
    /* -> check the age
     * -> check if 1 month passed since the last vaccination using system date with calculateDays()
     * -> ask user the vacType even if it is the second time, then prompt error if it's different than the first
     * -> rebuild the database with new info
     */
    string ID, currentLine, retry;

    for (int i = 0; i < 51; i++) { cout << "="; }
    cout << "\n\t\tYeni Asi Kaydi" << endl;
    cout << "(Butun islemlerden \"exit\" yazarak cikabilirsiniz.)\n";
    for (int i = 0; i < 51; i++) { cout << "="; }

    //get ID and search database:
    while (true) { //infinite loop to try again until ID is found in database
        getID(ID); //Get correct ID from user

        /* If ID match is found in database. End getting ID by breaking
         * infinite loop. If match is not found in database. Keep looping and
         * ask for ID again.
         */
        if (checkID(ID) == true) { break; }
        else if (checkID(ID) == false) {
            cout << "\nEslesen kayit bulunamadi. Yeniden denemek icin 1, cikmak icin herhangi bir sey yazabilirsiniz: ";
            getline(cin, retry);
            if (retry == "1") { continue; } //continue ask for ID
            else {
                system("cls"); //clear the console
                main();
            }
        }
    }

    if (checkID(ID) == true) {
        system("cls"); //clear the console
        user kullanici;
        buildUserFromDatabase(ID, kullanici);
        for (int i = 0; i < 51; i++) { cout << "="; }
        cout << "\n" << kullanici.ID << " - " << kullanici.name << " " << kullanici.surname
            << " (" << kullanici.age << "/" << kullanici.city << ") icin yeni asi kaydi" << endl;
        for (int i = 0; i < 51; i++) { cout << "-"; }

        //check the age:
        if (kullanici.age < 18) {
            cout << "\nYasiniz 18'den kucuk oldugu icin yeni asi kaydi olusturamazsiniz."
                << "\n\nDevam etmek icin bir tusa basiniz.";
            _getch();
            system("cls"); //clear the console
            main();
        }

        else {
            //check the vaccination count:
            if (kullanici.vacCount == 2) {
                cout << "\n2 Asi ile asi sureciniz tamamlanmistir. Yeni asi kaydi olusturamazsiniz."
                    << "\n\nDevam etmek icin bir tusa basiniz.";
                _getch();
                system("cls"); //clear the console
                main();
            }

            else {
                string appointment;
                //check if 30 days passed since the last vaccination:
                if (calculateDays(kullanici.lastVacDate, &appointment) < 30) {
                    cout << "\nYeni asi kaydi icin son asinizin uzerinden 30 gun gecmis olmalidir."
                        << "\nSon asiniz ile randevu tarihiniz arasinda " << calculateDays(kullanici.lastVacDate, &appointment)
                        << " gun var. Daha ileri bir tarihe randevu alabilirsiniz."
                        << "\n\nDevam etmek icin bir tusa basiniz.";
                    _getch();
                    system("cls"); //clear the console
                    main();
                }

                else {
                    string type; // X = 1 , Y = 2
                    int flag = 0; //will turn to 1 if appointment succesful                    
                    while (true) {
                        cout << "\nLutfen asi seciniz:\n"
                            << "(1) X\n"
                            << "(2) Y\n\n"
                            << "-> ";
                        cin >> ws; //clear input buffer
                        getline(cin, type);

                        //if user never vaccinated before:
                        if ((type == "1" || type == "2") && (kullanici.vacType == "NULL")) {
                            kullanici.lastVacDate = appointment; //update last vaccination date
                            if (type == "1") {
                                kullanici.vacCount++; //raise the number of vaccinations
                                kullanici.vacType = "X";
                                flag = 1;
                            }
                            else {
                                kullanici.vacCount++; //raise the number of vaccinations
                                kullanici.vacType = "Y";
                                flag = 1;
                            }
                            break;
                        }

                        //if vaccinated user picks X:
                        else if (type == "1") {
                            //check if the previous vaccination type is the same:
                            if (kullanici.vacType == "X") {
                                kullanici.lastVacDate = appointment; //update last vaccination date
                                kullanici.vacCount++; //raise the number of vaccinations
                                flag = 1;
                                break;
                            }
                            else {
                                cout << "\nDaha once Y asisi oldugunuz icin sadece Y asisini secebilirsiniz.\n";
                            }
                        }

                        //if vaccinated user picks Y:
                        else if (type == "2") {
                            //check if the previous vaccination type is the same:
                            if (kullanici.vacType == "Y") {
                                kullanici.lastVacDate = appointment; //update last vaccination date
                                kullanici.vacCount++; //raise the number of vaccinations
                                flag = 1;
                                break;
                            }
                            else {
                                cout << "\nDaha once X asisi oldugunuz icin sadece X asisini secebilirsiniz.\n";
                            }
                        }
                        else if (type == "exit") {
                            system("cls"); //clear the console
                            main();
                        }
                        else {
                            cout << "\nYanlis giris yaptiniz. Lutfen tekrar deneyin (cikis icin exit yazabilirsiniz).\n";
                        }
                    }

                    //rebuild the database and inform the user if appointment is succesful
                    if (flag == 1) {
                        //rebuild the database:
                        ifstream database("database.txt"); //open database in readmode
                        ofstream newDatabase("newDatabase.txt"); //create a new file to write updated database
                        while (getline(database, currentLine)) {
                            //change the line when ID match is found
                            if (ID[0] == currentLine[0] && ID[1] == currentLine[1]
                                && ID[2] == currentLine[2] && ID[3] == currentLine[3])
                            {
                                newDatabase << kullanici.ID << " " << kullanici.name << " " << kullanici.surname << " "
                                    << kullanici.age << " " << kullanici.city << " "
                                    << kullanici.lastVacDate << " " << kullanici.vacCount << " " << kullanici.vacType << endl;
                            }

                            //otherwise keep copying lines until there is a ID match: 
                            else { newDatabase << currentLine << endl; }
                        }
                        database.close();
                        newDatabase.close();
                        int status = remove("database.txt"); //delete old database
                        rename("newDatabase.txt", "database.txt"); //rename updated database

                        //inform the user:
                        cout << kullanici.name << " " << kullanici.surname << " adina "
                            << kullanici.lastVacDate << " tarihli "
                            << kullanici.vacType << " asisi randevunuz olusturulmustur."
                            << "\n\nDevam etmek icin bir tusa basiniz.";
                        _getch();
                        system("cls"); //clear the console
                    }
                }
            }
        }
    }
}

void getID(string& ID) {
    //recursive getID function
    cout << "\nLutfen iki buyuk harf ve iki rakamdan olusan ID'nizi giriniz: ";
    getline(cin, ID);
    if (ID.size() == 4 && ID[0] >= 'A' && ID[0] <= 'Z'
        && ID[1] >= 'A' && ID[1] <= 'Z'
        && ID[2] >= '0' && ID[2] <= '9'
        && ID[3] >= '0' && ID[3] <= '9') {/*don't do anything if it's in correct form*/
    }
    else if (ID == "exit") { //return back to main menu if exit is given
        system("cls"); //clear the console
        main();
    }
    else {
        cout << "\nHatali giris yaptiniz. Iki buyuk harf ve iki rakam olmasina dikkat ediniz";
        getID(ID); //call the function again to take the ID again
    }
}

void buildUserFromDatabase(string ID, user& yeni) {
    string currentLine;
    ifstream database("database.txt"); //open database
    //find the ID in database:
    while (getline(database, currentLine)) {
        if (ID[0] == currentLine[0] && ID[1] == currentLine[1]
            && ID[2] == currentLine[2] && ID[3] == currentLine[3])
        {
            int x = 0, start = 0;
            string info[8]; //will store the info about user
            currentLine = currentLine + ' ';

            //get the words into array:
            for (int i = 0; i < currentLine.size(); i++) {
                if (currentLine[i] == ' ') {
                    for (int j = start; j < i; j++) {
                        info[x] = info[x] + currentLine[j];
                    }
                    x++;
                    start = i + 1;
                }
            }

            //fill the user properties using array
            yeni.ID = info[0];
            yeni.name = info[1];
            yeni.surname = info[2];
            yeni.age = stoi(info[3]);
            yeni.city = info[4];
            yeni.lastVacDate = info[5];
            yeni.vacCount = stoi(info[6]);
            yeni.vacType = info[7];

            break;
        }
    }
    database.close();
}

int calculateDays(string lastVacDate, string* appointment) {
    //get system date:
    time_t currentTime = time(NULL);

    //string concatenations (split date into day, month, year):
    string day1, month1, year1;

    day1 = lastVacDate[0];
    day1 += lastVacDate[1];

    month1 = lastVacDate[3];
    month1 += lastVacDate[4];

    year1 = lastVacDate[6];
    year1 += lastVacDate[7];
    year1 += lastVacDate[8];
    year1 += lastVacDate[9];

    /* get default values to myDate from currentTime
     * it will be changed later with the values from database:
     */
    struct tm* myDate = localtime(&currentTime);

    /* update the appointment string with system date:
     * members of myDate will be just integers
     * for example 1.5.2022. but we need to store
     * it with also zeros like: 01.05.2022
     * so we use stringstream and setfill('0')
     */
    stringstream ss;
    ss << setw(2) << setfill('0') << to_string(myDate->tm_mday);
    ss << ".";
    ss << setw(2) << setfill('0') << to_string(myDate->tm_mon + 1);
    ss << ".";
    ss << to_string(myDate->tm_year + 1900);
    *appointment = ss.str();

    //update the values:
    myDate->tm_mday = stoi(day1);

    myDate->tm_mon = (stoi(month1) - 1);

    myDate->tm_year = (stoi(year1) - 1900);



    /*using mktime() to convert between tm and time_t:
     * total seconds elapsed / (60*60*24) to find days
     */
    return (difftime(currentTime, mktime(myDate)) / (60 * 60 * 24));
}

bool checkID(string ID) {
    string currentLine;

    //check if the given ID exists in database:
    ifstream database("database.txt"); //open database in read mode
    while (getline(database, currentLine)) {
        if (ID[0] == currentLine[0] && ID[1] == currentLine[1]
            && ID[2] == currentLine[2] && ID[3] == currentLine[3]) {
            database.close();
            return true; //return true if it exists
        }
    }
    database.close();
    return false; //return false if ID was not found
}
