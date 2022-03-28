#include "MyForm2.h"
#include "convert.h"
#include "FormBeg.h"
#include "MyForm3.h"

System::Void ISLB::MyForm2::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "yes";
	if (radioButton1->Checked) parentForm->car(Convert_string_to_String(s));
}

System::Void ISLB::MyForm2::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "no";
	if (radioButton2->Checked) parentForm->car(Convert_string_to_String(s));
}

System::Void ISLB::MyForm2::radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "yes";
	if (radioButton4->Checked) parentForm->garage(Convert_string_to_String(s));
}

System::Void ISLB::MyForm2::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "no";
	if (radioButton3->Checked) parentForm->garage(Convert_string_to_String(s));
}

System::Void ISLB::MyForm2::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm3^ f = gcnew MyForm3();//создаем новый экземпл€р
	f->Show();//открываем вторую форму
	MyForm2::Hide();
}
