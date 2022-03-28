#include "convert.h"

std::string& String_to_string(System::String^ s, std::string& os)
{
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return os;
}

System::String^ string_to_String(std::string& os, System::String^ s)
{
    s = gcnew System::String(os.c_str());
    return s;
}

std::string& Convert_String_to_string(System::String^ s)
{
    std::string os;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    return os;
}

System::String^ Convert_string_to_String(std::string& os)
{
    System::String^ s = gcnew System::String(os.c_str());
    return s;
}

char* Convert_String_to_char(System::String^ s)
{
    using namespace Runtime::InteropServices;
    return (char*)(void*)Marshal::StringToHGlobalAnsi(s);
}

System::String^ Convert_char_to_String(char* ch)
{
    char* chr = new char();
    chr = ch;
    System::String^ s;
    for (int i = 0;chr[i] != '\0';i++)
    {
        s += wchar_t(ch[i]);
    }
    return s;
}
