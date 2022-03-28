#include "MyForm3.h"
#include "FormBeg.h"
System::Void ISLB::MyForm3::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    parentForm->budget(Convert::ToInt32(textBox1->Text));
}

System::Void ISLB::MyForm3::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	FormBeg^ f = gcnew FormBeg();//создаем новый экземпл€р
	f->Show();//открываем вторую форму
	MyForm3::Hide();
}
