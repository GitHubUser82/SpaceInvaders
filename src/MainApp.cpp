//
// Created by mouni on 27/12/2025.
//

#include "MainApp.h"
#include "MainFrame.h"

bool MainApp::OnInit()
{
    wxFrame* frame = new MainFrame();
    frame->Show(true);
    return true;
}