//
// Created by mouni on 27/12/2025.
//

#include "MainFrame.h"
#include "OpenGLFrame.h"


MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    auto* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    auto* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    auto* menuWindow = new wxMenu;
    menuWindow->Append(ID_New, "&New");

    auto* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    menuBar->Append(menuWindow, "&Window");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MainFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnNew, this, ID_New);
}

void MainFrame::OnExit(wxCommandEvent&)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent&)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World",
                 wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent&)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MainFrame::OnNew(wxCommandEvent&)
{
    auto* glFrame = new OpenGLFrame(this);
    glFrame->Show(true);
}
