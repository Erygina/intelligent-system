#include "MyForm1.h"
#include "convert.h"
#include "FormBeg.h"
#include "MyForm2.h"

System::Void ISLB::MyForm1::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "yes";
	if (radioButton1->Checked) parentForm->havingChildren(Convert_string_to_String(s));
}

System::Void ISLB::MyForm1::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "no";
	if (radioButton2->Checked) parentForm->havingChildren(Convert_string_to_String(s));
}

System::Void ISLB::MyForm1::radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton4->Checked) parentForm->numberOfChildren(3);
}

System::Void ISLB::MyForm1::radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton3->Checked) parentForm->numberOfChildren(1);
}

System::Void ISLB::MyForm1::radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton5->Checked) parentForm->numberOfChildren(0);
}

System::Void ISLB::MyForm1::radioButton7_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "one";
	if (radioButton7->Checked) parentForm->genderOfChildren(Convert_string_to_String(s));
}

System::Void ISLB::MyForm1::radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "different";
	if (radioButton6->Checked) parentForm->genderOfChildren(Convert_string_to_String(s));
}

System::Void ISLB::MyForm1::radioButton10_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	std::string s = "no";
	if (radioButton10->Checked) parentForm->genderOfChildren(Convert_string_to_String(s));
}

System::Void ISLB::MyForm1::radioButton9_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton9->Checked) parentForm->minimumAge(6);
}

System::Void ISLB::MyForm1::radioButton8_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton8->Checked) parentForm->minimumAge(7);
}

System::Void ISLB::MyForm1::radioButton11_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (radioButton8->Checked) parentForm->minimumAge(-1);
}

System::Void ISLB::MyForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm2^ f = gcnew MyForm2();//создаем новый экземпл€р
	f->Show();//открываем вторую форму
	MyForm1::Hide();
}
