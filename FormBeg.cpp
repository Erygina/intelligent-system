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

Apartment* apartmentVector;//������ ��� ����������� ���� ������ �� ����� ��������
int sizeApartment = 9;

void ISLB::FormBeg::inf_apartment()//��������� ���������� � ���������
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

Garages* garageVector;  //������ ��� ����������� ���� ������ �� ����� ������
int sizeGarages = 5;

void ISLB::FormBeg::inf_garage()//��������� ���������� � �������
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

House* houseVector;    // ������ ��� ����������� ���� ������ �� ����� � ������
int sizeHouse = 5;

void ISLB::FormBeg::inf_house()//��������� ������ � �����
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

FlatAndGarage* flatAndGarageVector;   //������ ��� ����������� ���� ������ ������� � ��������
int sizeFlatAndGarage = 5;

void ISLB::FormBeg::inf_flat_and_garage()//��������� ������ � ��������� � ��������
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

void ISLB::FormBeg::buy_apartment()//����������� ��������� �������
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
                result <<"�����:  "<< apartmentVector[i].adress << '\n';
                result << "����:  " << std::to_string(apartmentVector[i].price) << " ���." << '\n';
                result << "���������� ������:  "<< std::to_string(apartmentVector[i].rooms) << '\n';
                result << "�������:  " << std::to_string(apartmentVector[i].space) << " �.��." << '\n';
                result << "��������������:  " << apartmentVector[i].infrastructure << '\n';
                result << "������� ��������:  " << apartmentVector[i].comfortLevel << '\n';
                result << "�������:  " << apartmentVector[i].finishingFlat << '\n';
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
                result << "�����:  " << flatAndGarageVector[i].adressApartment << '\n';
                result << "���������� ������:  " << std::to_string(flatAndGarageVector[i].rooms) << '\n';
                result << "�������:  " << std::to_string(flatAndGarageVector[i].spaceApartment) << " �.��." << '\n';
                result << "��������������:  " << flatAndGarageVector[i].infrastructure << '\n';
                result << "������� ��������:  " << flatAndGarageVector[i].comfortLevel << '\n';
                result << "�������:  " << flatAndGarageVector[i].finishingFlat << '\n';
                result << "����� ������:  " << flatAndGarageVector[i].adressGarage << '\n';
                result << "������� ������:  " << std::to_string(flatAndGarageVector[i].spaceGarage) << " �.��." << '\n';
                result << "����:  " << std::to_string(flatAndGarageVector[i].price) << " ���." << '\n';
                result << '\n';
            }
        }
    }
}

void ISLB::FormBeg::buy_garage()//����������� ��������� �������
{
    int i;
    int* help = new int[sizeGarages];
    inf_garage();
    //result.open("result.txt", std::ofstream::out);
    result.open("result.txt", std::ofstream::out);
    for (i = 0; i < sizeGarages; i++) help[i] = 0;
    for (i = 0; i < sizeGarages; i++) {           //���� ������ ���������� ������ ��� ����� ���� , �� �� ������� ������
        if (garageVector[i].price > Budget) help[i] = -1;
    }
    for (i = 0; i < sizeGarages; i++) {
        if (help[i] != -1) {
           // result << std::to_string(garageVector[i].number)<< '\n';
            result << "����� ������:  " << garageVector[i].adress << '\n';
            result << "���� ������:  " << std::to_string(garageVector[i].price) << " ���." << '\n';
            result << "������� ������:  " << std::to_string(garageVector[i].space) << " �.��." << '\n';
            result << '\n';
        }
    }
}

void ISLB::FormBeg::buy_house()//����������� ��������� �����
{
    int i;
    inf_house();
    int* help = new int[sizeHouse];
    result.open("result.txt", std::ofstream::out);
    for (i = 0; i < sizeHouse; i++) help[i] = 0;
    if (find(Choice.begin(), Choice.end(), "bathhouse ") != Choice.end()) {
        for (i = 0; i < sizeHouse; i++) {
            if (houseVector[i].addBuilding != "����") help[i] = -1;
        }
    }
    if (find(Choice.begin(), Choice.end(), "noBathhouse ") != Choice.end()) {
        for (i = 0; i < sizeHouse; i++) {
            if (houseVector[i].addBuilding != "���������� ���") help[i] = -1;
        }
    }

    for (i = 0; i < sizeHouse; i++) {       ////���� ������ ���������� ������ ��� ����� ���� , �� �� ������� ������
        if (houseVector[i].price > Budget) help[i] = -1;
    }
    for (i = 0; i < sizeHouse; i++) {
        if (help[i] != -1) {
            //result << std::to_string(houseVector[i].number) << '\n';
            result << "�����:  " << houseVector[i].adress << '\n';
            result << "����:  " << std::to_string(houseVector[i].price) << " ���." << '\n';
            result << "�����:  " << std::to_string(houseVector[i].floors) << '\n';
            result << "�������:  " << std::to_string(houseVector[i].space) << " �.��." << '\n';
            result << "������� ��������:  " << houseVector[i].comfortLevel << '\n';
            result << "�������:  " << houseVector[i].finishingFlat << '\n';
            result << "����������:  " << houseVector[i].addBuilding << '\n';
            result << '\n';
        }
    }
}

void ISLB::FormBeg::buy()//����������� �� �������
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
   Form1^ f1 = gcnew Form1();//������� ����� ���������
   f1->Show();//��������� ������ �����
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

System::Void ISLB::FormBeg::Q6()//����  ���������� ����� ���, �� ���������� ����
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
    else  Choice.push_back("noBathhouse ");//���� �� ����� ����
}

System::Void ISLB::FormBeg::Q5()//���� � ���������� ���� ������ � ����� ��������, �� ��� ������, �� ���� ������ �����
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
    else  Choice.push_back("noGarage ");//���� � ���������� ��� ������ ��� ���� �����,����� �� �����
}

System::Void ISLB::FormBeg::Q4()//���� � ���������� ���� ���� ������ 7 ���, �� ����� � ��������� ����� ������� ����� � �����
{
    if (MinimumAge <= 6)
    {
        Choice.push_back("SchoolAndKindergarten ");
    }
    else  Choice.push_back("School ");//���� � ���������� ���� >6��� , �� ����� �����
}

System::Void ISLB::FormBeg::Q3()//���� � ���������� 2 � ����� ������� � ��� ����������, �� ����� �������� � 2-�� � ����� ���������
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
        else  Choice.push_back("any ");//���� � ���������� <2 ����� ��� ��� ���������, �� �������� �����
        Q4();//else �����, ����� ������ ���������� ��� �����, ����, <2 ����� ��� ��� ���������
    }
    else  Choice.push_back("any ");//���� � ���������� ��� ����� ��� ��� ���������, �� �������� �����
}

System::Void ISLB::FormBeg::Q2()//���� ���������� �������� �����, �� ������������ - ��������
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
    else //���� ���������� �������� �� �����, �� ������������ - ���
    {
        std::string str = "house";
        System::String^ s = gcnew System::String(str.c_str());
        DesiredProperty = s;

        Choice.push_back("house ");
        Q6();// ����
    }
}

System::Void ISLB::FormBeg::Q1()//���� ���������� �������� ����� ���������, �� ������������ - �������� ��� ���
{
    std::string s1;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(LivingSpace)).ToPointer();
    s1 = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    if (s1 == "yes")
    {
        Q2(); // �� ���� ��� ��� ��������
        Q5(); //�� ���� ������        

    }
    else //���� ���������� �������� �� ����� ���������, �� ������������ - �����
    {
        std::string str = "garage";
        System::String^ s = gcnew System::String(str.c_str());
        DesiredProperty = s;

        Choice.push_back("garage ");
    }
    buy();
}

