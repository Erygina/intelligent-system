#pragma once
#include <string>
using namespace System;
std::string& String_to_string(String^ s, std::string& os);

String^ string_to_String(std::string& os,String^ s);

std::string& Convert_String_to_string(String^ s);

System::String^ Convert_string_to_String(std::string& os);

char* Convert_String_to_char(System::String^ s);

String^ Convert_char_to_String(char* ch);
