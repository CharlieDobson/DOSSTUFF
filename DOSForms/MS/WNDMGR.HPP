// wndmgr.hpp : Window manager defintion file for DOSForms

#ifndef WNDMGR_HPP
#define WNDMGR_HPP 1

#include "form.hpp"

// Window manager for multiple forms
//
// Handles multiple forms, z-order, redraws,
// and input dispatch
// 
class WindowManager {
public:
    Form* activeForm;

    void SetActiveForm(Form* form);
    void DispatchInput(int key);
    void DrawActiveForm();
};

#endif