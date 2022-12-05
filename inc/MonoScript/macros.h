//
// Created by Monika on 04.12.2022.
//

#ifndef MONOSCRIPTTEST_MACROS_H
#define MONOSCRIPTTEST_MACROS_H

#ifdef _MSC_VER
    #pragma warning (disable: 4005)
    #pragma warning (disable: 4067)
    #pragma warning (disable: 4133)
    #pragma warning (disable: 4090)
    #pragma warning (disable: 4098)
    #pragma warning (disable: 5208)
    #pragma warning (disable: 4028)
#endif

#ifdef WIN32
    #define MONO_SCRIPT_WINDOWS
#endif

#define MST_EXPORT __declspec(dllexport)
#define MST_EXTERN extern

#endif //MONOSCRIPTTEST_MACROS_H
