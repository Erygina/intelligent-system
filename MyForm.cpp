#include "MyForm.h"
#include "FormBeg.h"
#include "convert.h"
#include "MyForm1.h"
#include "MyForm4.h"

System::Void ISLB::MyForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "city";
	if (radioButton1->Checked) parentForm->location(Convert_string_to_String(s));
}

System::Void ISLB::MyForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "nocity";
	if (radioButton2->Checked) parentForm->location(Convert_string_to_String(s));
}

System::Void ISLB::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton1->Checked)
	{
		MyForm1^ f2 = gcnew MyForm1();//создаем новый экземпл€р
		f2->Show();//открываем вторую форму
		MyForm::Hide();
	}
	if (radioButton2->Checked)
	{
		MyForm4^ f = gcnew MyForm4();//создаем новый экземпл€р
		f->Show();//открываем вторую форму
		MyForm::Hide();
	}
}
