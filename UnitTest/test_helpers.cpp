#include "stdafx.h"
#include "test_helpers.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::wstring get_message(const wchar_t *title, const point *p1, const point *p2)
{
    std::wstringstream message;
    message << title;
    if (p1)
        message << ToString(p1);
    if (p2)
        message << ToString(p2);
    return message.str();
}
