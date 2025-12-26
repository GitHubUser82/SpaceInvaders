//
// Created by mouni on 27/12/2025.
//

#ifndef SPACEINVADERS_MAINFRAME_H
#define SPACEINVADERS_MAINFRAME_H


#include <wx/wx.h>

enum
{
    ID_Hello = 1,
    ID_New
};

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};


#endif //SPACEINVADERS_MAINFRAME_H