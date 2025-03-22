#pragma once

#include <gl/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <wx/glcanvas.h>

class Renderer {
public:
	wxGLCanvas* m_canvas;
	wxGLContext* m_context;

private:
	GLuint _object_vao, _object_vbo;
	GLuint _button_vao, _button_vbo;
	GLuint _object_shader_program;
	GLuint _button_shader_program;

private:
	bool m_wireframe_mode = false;

public:
	glm::vec3 m_cam_pos, m_cam_orien;
	glm::vec3 m_light_col, m_light_pos;
	glm::vec3 m_obj_pos, m_obj_rot, m_obj_scale;

public:
	Renderer(wxGLCanvas* canvas);
	~Renderer();

public:
	void SetWireframeMode(bool mode);

public:
	void SetCameraPosition(const glm::vec3& pos);
	void SetCameraOrientation(const glm::vec3& orien);

public:
	void SetLightColor(const glm::vec3& col);
	void SetLightPosition(const glm::vec3& pos);

public:
	void SetObjectPosition(const glm::vec3& pos);
	void SetObjectRotation(const glm::vec3& rot);
	void SetObjectScale(const glm::vec3& scale);

public:
	void Render();

private:
	void InitDriver();
	void InitObjectBuffers();
	void InitButtonBuffers();
	void InitObjectShaders();
	void InitButtonShaders();
};

inline
void Renderer::SetWireframeMode(bool mode)
{
	m_wireframe_mode = mode;
}

inline
void Renderer::SetCameraPosition(const glm::vec3& pos)
{
	m_cam_pos = pos;
}
inline
void Renderer::SetCameraOrientation(const glm::vec3& orien)
{
	m_cam_orien = orien;
}

inline
void Renderer::SetLightColor(const glm::vec3& col)
{
	m_light_col = col;
}
inline
void Renderer::SetLightPosition(const glm::vec3& pos)
{
	m_light_pos = pos;
}

inline
void Renderer::SetObjectPosition(const glm::vec3& pos)
{
	m_obj_pos = pos;
}
inline
void Renderer::SetObjectRotation(const glm::vec3& rot)
{	m_obj_rot = rot;

}
inline
void Renderer::SetObjectScale(const glm::vec3& scale)
{
	m_obj_scale = scale;
}