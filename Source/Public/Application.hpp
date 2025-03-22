#pragma once

#include "Renderer.hpp"

#include <wx/wx.h>
#include <wx/clrpicker.h>

class MyFrame : public wxFrame
{
public:
	MyFrame();
	~MyFrame();

private:
	Renderer* m_renderer;

private:
	wxPanel* control_panel;

	wxSlider* cam_pos_x;
	wxSlider* cam_pos_y;
	wxSlider* cam_pos_z;

	wxSlider* light_pos_x;
	wxSlider* light_pos_y;
	wxSlider* light_pos_z;
	wxColourPickerCtrl* light_color;

	wxSlider* object_rot_x;
	wxSlider* object_rot_y;
	wxSlider* object_rot_z;

	wxCheckBox* wireframe_checkbox;

private:
	bool isControlPanelVisible = false;
	bool isMouseOverButton = false;

private:
	void Render();

private:
	void OnPaint(wxPaintEvent& event);
	void OnResize(wxSizeEvent& event);

	void OnMouse(wxMouseEvent& event);
	void OnMouseMotion(wxMouseEvent& event);
	void OnMouseWheel(wxMouseEvent& event);

	void OnCamX(wxCommandEvent& event);
	void OnCamZ(wxCommandEvent& event);
	void OnCamY(wxCommandEvent& event);

	void OnLightX(wxCommandEvent& event);
	void OnLightZ(wxCommandEvent& event);
	void OnLightY(wxCommandEvent& event);

	void OnSliderX(wxCommandEvent& event);
	void OnSliderY(wxCommandEvent& event);
	void OnSliderZ(wxCommandEvent& event);

	void OnCheckBox(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};

class MainApplication : public wxApp
{
public:
	virtual bool OnInit() override;
};