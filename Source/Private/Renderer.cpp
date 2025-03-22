#include "Renderer.hpp"

#include "Utils.hpp"

Renderer::Renderer(wxGLCanvas* canvas)
	: m_canvas(canvas)
{
	m_context = new wxGLContext(m_canvas);
	m_canvas->SetCurrent(*m_context);

	m_cam_pos = glm::vec3(0.0f, 0.0f, 3.0f);

	m_light_col = glm::vec3(1.0f);
	m_light_pos = glm::vec3(0.0f);

	m_obj_pos = glm::vec3(0.0f);
	m_obj_rot = glm::vec3(0.0f);
	m_obj_scale = glm::vec3(1.0f);

	this->InitDriver();
	this->InitObjectBuffers();
	this->InitButtonBuffers();
	this->InitObjectShaders();
	this->InitButtonShaders();
}
Renderer::~Renderer() {
	if (m_canvas && m_context)
		m_canvas->SetCurrent(*m_context);

	glDeleteBuffers(1, &_object_vbo);
	glDeleteVertexArrays(1, &_object_vao);
	glDeleteProgram(_object_shader_program);

	delete m_context;
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, m_wireframe_mode ? GL_LINE : GL_FILL);

	wxSize size = m_canvas->GetSize();

	// Render Object
	{
		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, m_obj_pos);

		model = glm::rotate(model, m_obj_rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, m_obj_rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, m_obj_rot.z, glm::vec3(0.0f, 0.0f, 1.0f));

		model = glm::scale(model, m_obj_scale);

		glm::mat4 view = glm::lookAt(
			m_cam_pos,
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
		);

		float aspect = (float)size.GetWidth() / size.GetHeight();
		glm::mat4 projection = glm::perspective(
			glm::radians(45.0f),
			aspect,
			0.1f, 100.0f
		);

		glm::mat4 mvp = projection * view * model;

		glUseProgram(_object_shader_program);
		glUniformMatrix4fv(glGetUniformLocation(_object_shader_program, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
		glUniformMatrix4fv(glGetUniformLocation(_object_shader_program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(glGetUniformLocation(_object_shader_program, "lightPos"), 1, glm::value_ptr(m_light_pos));
		glUniform3fv(glGetUniformLocation(_object_shader_program, "viewPos"), 1, glm::value_ptr(m_cam_pos));
		glUniform3fv(glGetUniformLocation(_object_shader_program, "lightCol"), 1, glm::value_ptr(m_light_col));
		glBindVertexArray(_object_vao);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	// Render Button
	{
		glm::mat4 projection = glm::ortho(
			0.0f, (float)size.GetWidth(),
			(float)size.GetHeight(), 0.0f,
			-1.0f, 1.0f
		);

		glUseProgram(_button_shader_program);
		glUniformMatrix4fv(glGetUniformLocation(_button_shader_program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniform3f(glGetUniformLocation(_button_shader_program, "color"), 0.5f, 0.5f, 0.5f);
		glDisable(GL_DEPTH_TEST);
		glBindVertexArray(_button_vao);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glEnable(GL_DEPTH_TEST);
	}
}

void Renderer::InitDriver()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
		wxLogDebug("GLEW Error: %s", glewGetErrorString(err));

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	glViewport(0, 0,
		m_canvas->GetSize().GetWidth(), m_canvas->GetSize().GetHeight());
}
void Renderer::InitObjectBuffers()
{
	glGenVertexArrays(1, &_object_vao);
	glBindVertexArray(_object_vao);

	glGenBuffers(1, &_object_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _object_vbo);

	auto cube_vertices = GenerateCube();
	glBufferData(GL_ARRAY_BUFFER, cube_vertices.size() * sizeof(float), cube_vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}
void Renderer::InitButtonBuffers()
{
	static float button_vertices[] = {
		10.0f, 10.0f, 0.0f, 60.0f, 10.0f, 0.0f, 60.0f, 30.0f, 0.0f,
		10.0f, 10.0f, 0.0f, 60.0f, 30.0f, 0.0f, 10.0f, 30.0f, 0.0f
	};

	glGenVertexArrays(1, &_button_vao);
	glBindVertexArray(_button_vao);

	glGenBuffers(1, &_button_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _button_vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(button_vertices), button_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}
void Renderer::InitObjectShaders()
{
	const char* vertexShaderSource = R"(
		#version 400 core

		layout(location = 0) in vec3 aPos;
		layout(location = 1) in vec3 aNormal;

		uniform mat4 mvp;
		uniform mat4 model;

		out vec3 FragPos;
		out vec3 Normal;

		void main()
		{
			gl_Position = mvp * vec4(aPos, 1.0);

			FragPos = vec3(model * vec4(aPos, 1.0));
			Normal = mat3(transpose(inverse(model))) * aNormal;
		}
	)";
	const char* fragmentShaderSource = R"(
		#version 400 core

		in vec3 FragPos;
		in vec3 Normal;

		out vec4 FragColor;

		uniform vec3 lightPos;
		uniform vec3 lightCol;

		uniform vec3 viewPos;

		void main()
		{
			vec3 objectColor = vec3(1.0, 1.0, 1.0);

			float ambientStrength = 0.1;

			vec3 norm = normalize(Normal);
			vec3 ambient = ambientStrength * lightCol;
			vec3 lightDir = normalize(lightPos - FragPos);

			float diff = max(dot(norm, lightDir), 0.0);

			vec3 diffuse = diff * lightCol;

			float specularStrength = 0.5;

			vec3 viewDir = normalize(viewPos - FragPos);
			vec3 reflectDir = reflect(-lightDir, norm);

			float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);

			vec3 specular = specularStrength * spec * lightCol;
			vec3 result = (ambient + diffuse + specular) * objectColor;

			FragColor = vec4(result, 1.0);
		}
	)";

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		wxLogDebug("Vertex Shader Error: %s", infoLog);
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		wxLogDebug("Fragment Shader Error: %s", infoLog);
	}

	_object_shader_program = glCreateProgram();

	glAttachShader(_object_shader_program, vertexShader);
	glAttachShader(_object_shader_program, fragmentShader);
	glLinkProgram(_object_shader_program);

	glGetProgramiv(_object_shader_program, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetProgramInfoLog(_object_shader_program, 512, nullptr, infoLog);
		wxLogDebug("Shader Program Link Error: %s", infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
void Renderer::InitButtonShaders()
{
	const char* vertexShaderSource = R"(
		#version 400 core

		layout(location = 0) in vec3 aPos;

		uniform mat4 projection;

		void main()
		{
			gl_Position = projection * vec4(aPos, 1.0);
		}
	)";
	const char* fragmentShaderSource = R"(
		#version 400 core

		out vec4 FragColor;

		uniform vec3 color;

		void main()
		{
			FragColor = vec4(color, 1.0);
		}
	)";

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		wxLogDebug("Vertex Shader Error: %s", infoLog);
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		wxLogDebug("Fragment Shader Error: %s", infoLog);
	}

	_button_shader_program = glCreateProgram();

	glAttachShader(_button_shader_program, vertexShader);
	glAttachShader(_button_shader_program, fragmentShader);
	glLinkProgram(_button_shader_program);

	glGetProgramiv(_button_shader_program, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetProgramInfoLog(_button_shader_program, 512, nullptr, infoLog);
		wxLogDebug("Shader Program Link Error: %s", infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}