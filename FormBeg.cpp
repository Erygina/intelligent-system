#include "FormBeg.h"
#include "MyForm.h"
#include "Form1.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace System;
using namespace System::Windows::Forms;
using namespace::IO;


[STAThreadAttribute]

void main(array<String^ >^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ISLB::FormBeg Form;
    Application::Run(% Form);
}


std::ifstream fileApartment;
std::ifstream fileGarage;
std::ifstream fileHouse;
std::ifstream fileFlatAndGarage;
std::ofstream result;


std::vector<std::string > Choice;


std::string help;
struct Apartment {
    int number;
    std::string adress;
    int price;
    int rooms;
    int space;
    std::string infrastructure;
    std::string comfortLevel;
    std::string finishingFlat;
};

Apartment* apartmentVector;//массив для запоминания всех данных из файла квартиры
int sizeApartment = 9;

void ISLB::FormBeg::inf_apartment()//заполнить информацию о квартирах
{
    int i = 0;
    std::string s;
    apartmentVector = new Apartment[sizeApartment];
    fileApartment.open("flat.txt", std::ifstream::in);
    fileApartment.seekg(0, fileApartment.beg);
    while (!fileApartment.eof() && i < sizeApartment) {
        fileApartment >> apartmentVector[i].number;
        getline(fileApartment, s);
        getline(fileApartment, apartmentVector[i].adress);
        fileApartment >> apartmentVector[i].price;
        getline(fileApartment, s);
        fileApartment >> apartmentVector[i].rooms;
        getline(fileApartment, s);
        fileApartment >> apartmentVector[i].space;
        getline(fileApartment, s);
        getline(fileApartment, apartmentVector[i].infrastructure);
        getline(fileApartment, apartmentVector[i].comfortLevel);
        getline(fileApartment, apartmentVector[i].finishingFlat);
        i++;
    }
}

struct Garages {
    int number;
    std::string adress;
    int price;
    int space;
};

Garages* garageVector;  //массив для запоминания всех данных из файла гаражи
int sizeGarages = 5;

void ISLB::FormBeg::inf_garage()//заполнить информацию о гаражах
{
    int i = 0;
    std::string s;
    garageVector = new Garages[sizeGarages];
    fileGarage.open("garage.txt", std::ifstream::in);
    fileGarage.seekg(0, fileGarage.beg);
    while (!fileGarage.eof() && i < sizeGarages) {
        fileGarage >> garageVector[i].number;
        getline(fileGarage, s);
        getline(fileGarage, garageVector[i].adress);
        fileGarage >> garageVector[i].price;
        getline(fileGarage, s);
        fileGarage >> garageVector[i].space;
        getline(fileGarage, s);
        i++;
    }
}

struct House {
    int number;
    std::string adress;
    int price;
    int floors;
    int space;
    std::string comfortLevel;
    std::string finishingFlat;
    std::string addBuilding;
};

House* houseVector;    // массив для запоминания всех данных из файла с домами
int sizeHouse = 5;

void ISLB::FormBeg::inf_house()//заполнить данные о домах
{
    int i = 0;
    std::string s;
    houseVector = new House[sizeHouse];
    fileHouse.open("house.txt", std::ifstream::in);
    fileHouse.seekg(0, fileHouse.beg);
    while (!fileHouse.eof() && i < sizeHouse) {
        fileHouse >> houseVector[i].number;
        getline(fileHouse, s);
        getline(fileHouse, houseVector[i].adress);
        fileHouse >> houseVector[i].price;
        getline(fileHouse, s);
        fileHouse >> houseVector[i].floors;
        getline(fileHouse, s);
        fileHouse >> houseVector[i].space;
        getline(fileHouse, s);
        getline(fileHouse, houseVector[i].comfortLevel);
        getline(fileHouse, houseVector[i].finishingFlat);
        getline(fileHouse, houseVector[i].addBuilding);
        i++;
    }
}

struct FlatAndGarage {
    int number;
    std::string adressApartment;
    int rooms;
    int spaceApartment;
    std::string infrastructure;
    std::string comfortLevel;
    std::string finishingFlat;
    std::string adressGarage;
    int spaceGarage;
    int price;
};

FlatAndGarage* flatAndGarageVector;   //массив для запоминания всех данных квартир с гаражами
int sizeFlatAndGarage = 5;

void ISLB::FormBeg::inf_flat_and_garage()//заполнить данные о квартирах с гаражами
{
    int i = 0;
    std::string s;
    flatAndGarageVector = new FlatAndGarage[sizeFlatAndGarage];
    fileFlatAndGarage.open("flatAndGarage.txt", std::ifstream::in);
    fileFlatAndGarage.seekg(0, fileFlatAndGarage.beg);
    while (!fileFlatAndGarage.eof() && i < sizeFlatAndGarage) {
        fileFlatAndGarage >> flatAndGarageVector[i].number;
        getline(fileFlatAndGarage, s);
        getline(fileFlatAndGarage, flatAndGarageVector[i].adressApartment);
        fileFlatAndGarage >> flatAndGarageVector[i].rooms;
        getline(fileFlatAndGarage, s);
        fileFlatAndGarage >> flatAndGarageVector[i].spaceApartment;
        getline(fileFlatAndGarage, s);
        getline(fileFlatAndGarage, flatAndGarageVector[i].infrastructure);
        getline(fileFlatAndGarage, flatAndGarageVector[i].comfortLevel);
        getline(fileFlatAndGarage, flatAndGarageVector[i].finishingFlat);
        getline(fileFlatAndGarage, flatAndGarageVector[i].adressGarage);
        fileFlatAndGarage >> flatAndGarageVector[i].spaceGarage;
        getline(fileFlatAndGarage, s);
        fileFlatAndGarage >> flatAndGarageVector[i].price;
        getline(fileFlatAndGarage, s);
        i++;
    }
}

void ISLB::FormBeg::buy_apartment()//предложение вариантов квартир
{
    int i;
    int* help = new int[sizeApartment];
   result.open("result.txt", std::ofstream::out);
    for (i = 0; i < sizeApartment; i++) help[i] = 0;

    if (find(Choice.begin(), Choice.end(), "noGarage ") != Choice.end()) {
        inf_apartment();
        about_apartment(apartmentVector, sizeApartment, help);
        for (int i = 0; i < sizeApartment; i++) {
            if (help[i] != -1) {
                //result << std::to_string(apartmentVector[i].number) << '\n';
                result <<"Адрес:  "<< apartmentVector[i].adress << '\n';
                result << "Цена:  " << std::to_string(apartmentVector[i].price) << " руб." << '\n';
                result << "Количество комнат:  "<< std::to_string(apartmentVector[i].rooms) << '\n';
                result << "Площадь:  " << std::to_string(apartmentVector[i].space) << " м.кв." << '\n';
                result << "Инфраструктура:  " << apartmentVector[i].infrastructure << '\n';
                result << "Уровень комфорта:  " << apartmentVector[i].comfortLevel << '\n';
                result << "Отделка:  " << apartmentVector[i].finishingFlat << '\n';
                result << '\n';
            }
        }
    }
    if (find(Choice.begin(), Choice.end(), "Garage ") != Choice.end()) {
        inf_flat_and_garage();
        about_apartment(flatAndGarageVector, sizeFlatAndGarage, help);
        for ( i = 0; i < sizeFlatAndGarage; i++) {
            if (help[i] != -1) {
                //result << std::to_string(flatAndGarageVector[i].number) << '\n';
                result << "Адрес:  " << flatAndGarageVector[i].adressApartment << '\n';
                result << "Количество комнат:  " << std::to_string(flatAndGarageVector[i].rooms) << '\n';
                result << "Площадь:  " << std::to_string(flatAndGarageVector[i].spaceApartment) << " м.кв." << '\n';
                result << "Инфраструктура:  " << flatAndGarageVector[i].infrastructure << '\n';
                result << "Уровень комфорта:  " << flatAndGarageVector[i].comfortLevel << '\n';
                result << "Отделка:  " << flatAndGarageVector[i].finishingFlat << '\n';
                result << "Адрес Гаража:  " << flatAndGarageVector[i].adressGarage << '\n';
                result << "Площадь Гаража:  " << std::to_string(flatAndGarageVector[i].spaceGarage) << " м.кв." << '\n';
                result << "Цена:  " << std::to_string(flatAndGarageVector[i].price) << " руб." << '\n';
                result << '\n';
            }
        }
    }
}

void ISLB::FormBeg::buy_garage()//предложение вариантов гаражей
{
    int i;
    int* help = new int[sizeGarages];
    inf_garage();
    //result.open("result.txt", std::ofstream::out);
    result.open("result.txt", std::ofstream::out);
    for (i = 0; i < sizeGarages; i++) help[i] = 0;
    for (i = 0; i < sizeGarages; i++) {           //Если бюджет покупателя больше или равен цены , то ее следует купить
        if (garageVector[i].price > Budget) help[i] = -1;
    }
    for (i = 0; i < sizeGarages; i++) {
        if (help[i] != -1) {
           // result << std::to_string(garageVector[i].number)<< '\n';
            result << "Адрес Гаража:  " << garageVector[i].adress << '\n';
            result << "Цена Гаража:  " << std::to_string(garageVector[i].price) << " руб." << '\n';
            result << "Площадь Гаража:  " << std::to_string(garageVector[i].space) << " м.кв." << '\n';
            result << '\n';
        }
    }
}

void ISLB::FormBeg::buy_house()//предложение вариантов домов
{
    int i;
    inf_house();
    int* help = new int[sizeHouse];
    result.open("result.txt", std::ofstream::out);
    for (i = 0; i < sizeHouse; i++) help[i] = 0;
    if (find(Choice.begin(), Choice.end(), "bathhouse ") != Choice.end()) {
        for (i = 0; i < sizeHouse; i++) {
            if (houseVector[i].addBuilding != "баня") help[i] = -1;
        }
    }
    if (find(Choice.begin(), Choice.end(), "noBathhouse ") != Choice.end()) {
        for (i = 0; i < sizeHouse; i++) {
            if (houseVector[i].addBuilding != "пристройки нет") help[i] = -1;
        }
    }

    for (i = 0; i < sizeHouse; i++) {       ////Если бюджет покупателя больше или равен цены , то ее следует купить
        if (houseVector[i].price > Budget) help[i] = -1;
    }
    for (i = 0; i < sizeHouse; i++) {
        if (help[i] != -1) {
            //result << std::to_string(houseVector[i].number) << '\n';
            result << "Адрес:  " << houseVector[i].adress << '\n';
            result << "Цена:  " << std::to_string(houseVector[i].price) << " руб." << '\n';
            result << "Этажи:  " << std::to_string(houseVector[i].floors) << '\n';
            result << "Площадь:  " << std::to_string(houseVector[i].space) << " м.кв." << '\n';
            result << "Уровень комфорта:  " << houseVector[i].comfortLevel << '\n';
            result << "Отделка:  " << houseVector[i].finishingFlat << '\n';
            result << "Пристройка:  " << houseVector[i].addBuilding << '\n';
            result << '\n';
        }
    }
}

void ISLB::FormBeg::buy()//направление на покупку
{
    //int i;
    if (find(Choice.begin(), Choice.end(), "apartment ") != Choice.end()) {
        buy_apartment();
    }
    if (find(Choice.begin(), Choice.end(), "garage ") != Choice.end()) {
        buy_garage();
    }
    if (find(Choice.begin(), Choice.end(), "house ") != Choice.end()) {
        buy_house();
    }
}

//=======================================
System::Void ISLB::FormBeg::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
   Form1^ f1 = gcnew Form1();//создаем новый экземпляр
   f1->Show();//открываем вторую форму
   FormBeg::Hide();
}

System::Void ISLB::FormBeg::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    Q1();
    
    std::string s = "result.txt";
    String^ fResult = gcnew String(s.c_str());
    System::Diagnostics::Process::Start(fResult);

    result.close();
    Application::Exit();
}

System::Void ISLB::FormBeg::Q6()//Если  покупателю нужен дом, то предложить баню
{
    std::string os;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(AdditionalBuilding)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    if (os == "bathhouse ")
    {
        Choice.push_back("bathhouse ");
    }
    else  Choice.push_back("noBathhouse ");//Если не нужна баня
}

System::Void ISLB::FormBeg::Q5()//Если у покупателя есть машина и нужна квартира, но нет гаража, то надо купить гараж
{
    std::string s1;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(Car)).ToPointer();
    s1 = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    if (s1 == "yes")
    {
        std::string s2;
        using namespace Runtime::InteropServices;
        const char* chars =
            (const char*)(Marshal::StringToHGlobalAnsi(Garage)).ToPointer();
        s2 = chars;
        Marshal::FreeHGlobal(IntPtr((void*)chars));

        if (s2 == "no")
        {

            std::string s3;
            using namespace Runtime::InteropServices;
            const char* chars =
                (const char*)(Marshal::StringToHGlobalAnsi(DesiredProperty)).ToPointer();
            s3 = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
            if (s3 == "apartment")
            {
                Choice.push_back("Garage ");
            }
        }
        
    }
    else  Choice.push_back("noGarage ");//Если у покупателя НЕТ машины или ЕСТЬ гараж,гараж не нужен
}

System::Void ISLB::FormBeg::Q4()//Если у покупателя есть дети младше 7 лет, то рядом с квартирой нужны детский садик и школа
{
    if (MinimumAge <= 6)
    {
        Choice.push_back("SchoolAndKindergarten ");
    }
    else  Choice.push_back("School ");//Если у покупателя дети >6лет , то школа рядом
}

System::Void ISLB::FormBeg::Q3()//Если у покупателя 2 и более ребенка и они разнополые, то нужна квартира с 2-мя и более комнатами
{
    std::string s1;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(HavingChildren)).ToPointer();
    s1 = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    

    if (s1 == "yes")
    {
        std::string s2;
        using namespace Runtime::InteropServices;
        const char* chars =
            (const char*)(Marshal::StringToHGlobalAnsi(GenderOfChildren)).ToPointer();
        s2 = chars;
        Marshal::FreeHGlobal(IntPtr((void*)chars));

        if (NumberOfChildren >= 2 && s2 == "different")
        {

            help = ">=2_room";
            Choice.push_back(">=2_room ");
        }
        else  Choice.push_back("any ");//Если у покупателя <2 детей или они однополые, то квартира любая
        Q4();//else нужен, чтобы дальше спрашивать про детей, даже, <2 детей или они однополые
    }
    else  Choice.push_back("any ");//Если у покупателя НЕТ детей или они однополые, то квартира любая
}

System::Void ISLB::FormBeg::Q2()//Если покупатель выбирает город, то недвижимость - квартира
{
    std::string s1;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(Location)).ToPointer();
    s1 = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    if (s1 == "city")
    {
        std::string str = "apartment";
        System::String^ s = gcnew System::String(str.c_str());
        DesiredProperty = s;

        Choice.push_back("apartment ");
        Q3();
    }
    else //Если покупатель выбирает НЕ город, то недвижимость - дом
    {
        std::string str = "house";
        System::String^ s = gcnew System::String(str.c_str());
        DesiredProperty = s;

        Choice.push_back("house ");
        Q6();// баня
    }
}

System::Void ISLB::FormBeg::Q1()//Если покупатель выбирает Жилое помещение, то недвижимость - квартира или дом
{
    std::string s1;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(LivingSpace)).ToPointer();
    s1 = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    if (s1 == "yes")
    {
        Q2(); // на счет дом или квартира
        Q5(); //на счет гаража        

    }
    else //Если покупатель выбирает НЕ Жилое помещение, то недвижимость - гараж
    {
        std::string str = "garage";
        System::String^ s = gcnew System::String(str.c_str());
        DesiredProperty = s;

        Choice.push_back("garage ");
    }
    buy();
}

