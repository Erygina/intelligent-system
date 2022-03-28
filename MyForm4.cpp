#include "MyForm4.h"
#include "convert.h"
#include "FormBeg.h"
#include "MyForm3.h"
System::Void ISLB::MyForm4::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "bathhouse ";
	if (radioButton1->Checked) parentForm->additionalBuilding(Convert_string_to_String(s));
}

System::Void ISLB::MyForm4::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "noBathhouse ";
	if (radioButton1->Checked) parentForm->additionalBuilding(Convert_string_to_String(s));
}

System::Void ISLB::MyForm4::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm3^ f = gcnew MyForm3();//создаем новый экземпл€р
	f->Show();//открываем вторую форму
	MyForm4::Hide();
}
