#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "point.h"

namespace Microsoft
{
    namespace VisualStudio
    {
        namespace CppUnitTestFramework
        {
            template<> inline std::wstring ToString<point>(const point& t)
            {
                std::wstringstream _s;
                _s << L" (" << t.get_x() << L", " << t.get_y() << L")";
                return _s.str();
            }
            template<> inline std::wstring ToString<point>(const point* t)
            {
                if (NULL == t) return std::wstring(L"(NULL)");
                std::wstringstream _s;
                _s << L" (" << t->get_x() << L", " << t->get_y() << L")";
                return _s.str();
            }
            template<> inline std::wstring ToString<point>(point* t)
            {
                if (NULL == t) return std::wstring(L"(NULL)");
                std::wstringstream _s;
                _s << L" (" << t->get_x() << L", " << t->get_y() << L")";
                return _s.str();
            }
        }
    }
}

std::wstring get_message(const wchar_t *title, const point *p1 = 0, const point *p2 = 0);

