#include "Form1.h"
#include "convert.h"
#include "MyForm.h"
#include "MyForm3.h"
#include "FormBeg.h"

System::Void ISLB::Form1::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    std::string s = "yes";
	if (radioButton1->Checked) parentForm->livingSpace(Convert_string_to_String(s));
}

System::Void ISLB::Form1::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "no";
	if (radioButton2->Checked) parentForm->livingSpace(Convert_string_to_String(s));
}

System::Void ISLB::Form1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton1->Checked)
	{
		MyForm^ f2 = gcnew MyForm();//создаем новый экземпл€р
		f2->Show();//открываем вторую форму
		Form1::Hide();
	}
	if (radioButton2->Checked)
	{
		MyForm3^ f = gcnew MyForm3();//создаем новый экземпл€р
		f->Show();//открываем вторую форму
		Form1::Hide();
	}
}
