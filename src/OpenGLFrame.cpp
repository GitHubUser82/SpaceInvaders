//
// Created by mouni on 27/12/2025.
//

#include "OpenGLFrame.h"

class OpenGLCanvas : public wxGLCanvas
{
public:
    explicit OpenGLCanvas(wxWindow* parent)
        : wxGLCanvas(parent, wxID_ANY, nullptr),
          m_context(new wxGLContext(this))
    {
        Bind(wxEVT_PAINT, &OpenGLCanvas::OnPaint, this);
    }

private:
    wxGLContext* m_context;

    void OnPaint(wxPaintEvent&)
    {
        wxPaintDC dc(this);
        SetCurrent(*m_context);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);   // red
            glVertex2f( 0.0f,  0.5f);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f( 0.5f, -0.5f);
        glEnd();

        glFlush();
        SwapBuffers();
    }

};

OpenGLFrame::OpenGLFrame(wxWindow* parent)
    : wxFrame(parent, wxID_ANY, "OpenGL Window",
              wxDefaultPosition, wxSize(800, 600))
{
    auto* canvas = new OpenGLCanvas(this);

    auto* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(canvas, 1, wxEXPAND);
    SetSizer(sizer);
}
