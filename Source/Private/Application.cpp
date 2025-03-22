#include "Application.hpp"

bool MainApplication::OnInit() {
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_PAINT(MyFrame::OnPaint)
wxEND_EVENT_TABLE()

MyFrame::MyFrame()
	: wxFrame(nullptr, wxID_ANY, "Interactive GL Canvas", wxDefaultPosition, wxSize(800, 600))
{
	int gl_attribs[] = {
		WX_GL_CORE_PROFILE,
		WX_GL_MAJOR_VERSION, 4,
		WX_GL_MINOR_VERSION, 0,
		WX_GL_DOUBLEBUFFER, 0
	};

	// Renderer Setup
	{
		m_renderer = new Renderer(new wxGLCanvas(this, wxID_ANY,
			gl_attribs, wxDefaultPosition, wxSize(600, 600), wxFULL_REPAINT_ON_RESIZE));

		m_renderer->m_canvas->Bind(wxEVT_PAINT, &MyFrame::OnPaint, this);
		m_renderer->m_canvas->Bind(wxEVT_SIZE, &MyFrame::OnResize, this);
		m_renderer->m_canvas->Bind(wxEVT_LEFT_DOWN, &MyFrame::OnMouse, this);
		m_renderer->m_canvas->Bind(wxEVT_MOTION, &MyFrame::OnMouseMotion, this);
		m_renderer->m_canvas->Bind(wxEVT_MOUSEWHEEL, &MyFrame::OnMouseWheel, this);
	}

	wxBoxSizer* main_sizer = new wxBoxSizer(wxHORIZONTAL);
	main_sizer->Add(m_renderer->m_canvas, 1, wxEXPAND);

	control_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, -1));

	// Light Controls
	{
		light_pos_x = new wxSlider(control_panel, wxID_ANY,
			100, -500, 500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
		light_pos_y = new wxSlider(control_panel, wxID_ANY,
			100, -500, 500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
		light_pos_z = new wxSlider(control_panel, wxID_ANY,
			200, -500, 500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);

		light_pos_x->Bind(wxEVT_SLIDER, &MyFrame::OnLightX, this);
		light_pos_y->Bind(wxEVT_SLIDER, &MyFrame::OnLightY, this);
		light_pos_z->Bind(wxEVT_SLIDER, &MyFrame::OnLightZ, this);
	}

	// Object Controls
	{
		object_rot_x = new wxSlider(control_panel, wxID_ANY,
			0, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
		object_rot_y = new wxSlider(control_panel, wxID_ANY,
			0, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
		object_rot_z = new wxSlider(control_panel, wxID_ANY,
			0, 0, 360, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);

		object_rot_x->Bind(wxEVT_SLIDER, &MyFrame::OnSliderX, this);
		object_rot_y->Bind(wxEVT_SLIDER, &MyFrame::OnSliderY, this);
		object_rot_z->Bind(wxEVT_SLIDER, &MyFrame::OnSliderZ, this);
	}

	// Render Option Controls
	{
		wireframe_checkbox = new wxCheckBox(control_panel, wxID_ANY, "Wireframe Mode");

		wireframe_checkbox->Bind(wxEVT_CHECKBOX, &MyFrame::OnCheckBox, this);
	}

	light_color = new wxColourPickerCtrl(control_panel, wxID_ANY, *wxWHITE);

	light_color->Bind(wxEVT_COLOURPICKER_CHANGED, [=](wxColourPickerEvent& event) {
		wxColour colour = event.GetColour();

		glm::vec3 light_color_vec3(
			colour.Red() / 255.0f,
			colour.Green() / 255.0f,
			colour.Blue() / 255.0f
		);

		m_renderer->m_light_col = glm::vec3(
			colour.Red() / 255.0f, colour.Green() / 255.0f, colour.Blue() / 255.0f);
		m_renderer->m_canvas->Refresh();
	});

	wxBoxSizer* panel_sizer = new wxBoxSizer(wxVERTICAL);
	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Rotate X"), 0, wxALL, 5);
	panel_sizer->Add(object_rot_x, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Rotate Y"), 0, wxALL, 5);
	panel_sizer->Add(object_rot_y, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Rotate Z"), 0, wxALL, 5);
	panel_sizer->Add(object_rot_z, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Light X"), 0, wxALL, 5);
	panel_sizer->Add(light_pos_x, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Light Y"), 0, wxALL, 5);
	panel_sizer->Add(light_pos_y, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Light Z"), 0, wxALL, 5);
	panel_sizer->Add(light_pos_z, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(new wxStaticText(control_panel, wxID_ANY, "Light Color"), 0, wxALL, 5);
	panel_sizer->Add(light_color, 0, wxEXPAND | wxALL, 5);

	panel_sizer->Add(wireframe_checkbox, 0, wxEXPAND | wxALL, 5);

	control_panel->SetSizer(panel_sizer);
	control_panel->Hide();
	main_sizer->Add(control_panel, 0, wxEXPAND);

	SetSizer(main_sizer);
	SetMinSize(wxSize(800, 600));
	Centre();

	m_renderer->m_canvas->Refresh();
}
MyFrame::~MyFrame()
{
	delete m_renderer;
}

void MyFrame::OnPaint(wxPaintEvent& event)
{
	if (!m_renderer->m_canvas->IsShown())
		return;

	if (!m_renderer->m_canvas->SetCurrent(*m_renderer->m_context)) {
		wxLogDebug("Failed to set OpenGL context!");
		return;
	}

	m_renderer->Render();
	m_renderer->m_canvas->SwapBuffers();

	event.Skip();
}
void MyFrame::OnResize(wxSizeEvent& event)
{
	if (m_renderer->m_canvas->IsShown())
	{
		m_renderer->m_canvas->SetCurrent(*m_renderer->m_context);

		wxSize size = m_renderer->m_canvas->GetSize();
		glViewport(0, 0, size.GetWidth(), size.GetHeight());

		m_renderer->m_canvas->Refresh();
	}
	event.Skip();
}

void MyFrame::OnMouse(wxMouseEvent& event)
{
	if (event.LeftDown())
	{
		int x = event.GetX();
		int y = event.GetY();

		if (x >= 10 && x <= 60 && y >= 10 && y <= 30)
		{
			isControlPanelVisible = !isControlPanelVisible;
			control_panel->Show(isControlPanelVisible);
			Layout();
			m_renderer->m_canvas->Refresh();
		}
	}
}
void MyFrame::OnMouseMotion(wxMouseEvent& event)
{
	int x = event.GetX();
	int y = event.GetY();
	bool overButton = (x >= 10 && x <= 60 && y >= 10 && y <= 30);

	if (overButton != isMouseOverButton)
	{
		isMouseOverButton = overButton;
		m_renderer->m_canvas->Refresh();
	}
}
void MyFrame::OnMouseWheel(wxMouseEvent& event)
{
	int wheel_rotation = event.GetWheelRotation();

	float delta = wheel_rotation > 0 ? -0.1f : 0.1f;

	m_renderer->m_cam_pos.z += delta;
	m_renderer->m_cam_pos.z = glm::clamp(m_renderer->m_cam_pos.z, 0.5f, 10.0f);

	wxLogDebug("Camera Z: %f", m_renderer->m_cam_pos.z); // Debug output

	m_renderer->m_canvas->Refresh();
}

void MyFrame::OnCamX(wxCommandEvent& event)
{
	m_renderer->m_cam_pos.x = cam_pos_x->GetValue() / 100.0f;
	m_renderer->m_canvas->Refresh();
}
void MyFrame::OnCamZ(wxCommandEvent& event)
{
	m_renderer->m_cam_pos.y = cam_pos_y->GetValue() / 100.0f;
	m_renderer->m_canvas->Refresh();
}
void MyFrame::OnCamY(wxCommandEvent& event)
{
	m_renderer->m_cam_pos.y = cam_pos_z->GetValue() / 100.0f;
	m_renderer->m_canvas->Refresh();
}

void MyFrame::OnLightX(wxCommandEvent& event)
{
	m_renderer->m_light_pos.x = light_pos_x->GetValue() / 100.0f;
	m_renderer->m_canvas->Refresh();
}
void MyFrame::OnLightY(wxCommandEvent& event)
{
	m_renderer->m_light_pos.y = light_pos_y->GetValue() / 100.0f;
	m_renderer->m_canvas->Refresh();
}
void MyFrame::OnLightZ(wxCommandEvent& event)
{
	m_renderer->m_light_pos.z = light_pos_z->GetValue() / 100.0f;
	m_renderer->m_canvas->Refresh();
}

void MyFrame::OnSliderX(wxCommandEvent& event)
{
	m_renderer->m_obj_rot.x = object_rot_x->GetValue() * (3.14159f / 180.0f);
	m_renderer->m_canvas->Refresh();
}
void MyFrame::OnSliderY(wxCommandEvent& event)
{
	m_renderer->m_obj_rot.y= object_rot_y->GetValue() * (3.14159f / 180.0f);
	m_renderer->m_canvas->Refresh();
}
void MyFrame::OnSliderZ(wxCommandEvent& event)
{
	m_renderer->m_obj_rot.z = object_rot_z->GetValue() * (3.14159f / 180.0f);
	m_renderer->m_canvas->Refresh();
}

void MyFrame::OnCheckBox(wxCommandEvent& event)
{
	m_renderer->SetWireframeMode(wireframe_checkbox->GetValue());
	m_renderer->m_canvas->Refresh();
}