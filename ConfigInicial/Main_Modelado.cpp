//Practica 4
//Luis Yehosua Orihuela Castillo 
//6 de marzo de 2026
//320255409

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Modelado geometrico", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,0.0f,//Front
		0.5f, -0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		0.5f,  0.5f, 0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f, 0.5f, 1.0f, 0.0f,0.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 0.0f,0.0f,
		
	    -0.5f, -0.5f,-0.5f, 0.0f, 1.0f,0.0f,//Back
		 0.5f, -0.5f,-0.5f, 0.0f, 1.0f,0.0f,
		 0.5f,  0.5f,-0.5f, 0.0f, 1.0f,0.0f,
		 0.5f,  0.5f,-0.5f, 0.0f, 1.0f,0.0f,
	    -0.5f,  0.5f,-0.5f, 0.0f, 1.0f,0.0f,
	    -0.5f, -0.5f,-0.5f, 0.0f, 1.0f,0.0f,
		
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		 0.5f,  -0.5f, 0.5f, 0.0f, 0.0f,1.0f,
      
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f,  0.5f,  1.0f, 1.0f,0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.0f,
		
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 1.0f,1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 1.0f,1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 1.0f,1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,1.0f,
		
		-0.5f,  0.5f, -0.5f, 1.0f, 0.2f,0.5f,
		0.5f,  0.5f, -0.5f,  1.0f, 0.2f,0.5f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.2f,0.5f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.2f,0.5f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.2f,0.5f,
		-0.5f,  0.5f, -0.5f, 1.0f, 0.2f,0.5f,
	};




	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.5f, 0.3f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");
		GLint colorLoc = glGetUniformLocation(ourShader.Program, "objectColor");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	

		glBindVertexArray(VAO);
		
		//Cuerpo (principal)
	    model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(2.0f, 0.7f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.45f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(0.5f, 1.4285714286f, 1.0f));

		//Cuerpo2 
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.165f, 0.0875f, 0.0f));
		model = glm::scale(model, glm::vec3(0.33f, 0.525f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.45f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(3.030303f, 1.9047619f, 1.0f));
		model = glm::translate(model, glm::vec3(-1.165f, -0.0875f, 0.0f));

		//Cuerpo 3
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, -0.4f, 0.0f));
		model = glm::scale(model, glm::vec3(2.0f, 0.1f, 0.66f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.65f, 0.35f, 0.08f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(0.5f, 10.0f, 1.515151f));
		model = glm::translate(model, glm::vec3(-1.165f, -0.0875f, 0.0f));

		//Pata 1
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.9f, -0.65f, -0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.6f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.40f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 1.66666f, 5.88235f));
		model = glm::translate(model, glm::vec3(-0.9f, 0.65f, 0.415f));

		//Punta 1
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.9f, -1.0f, -0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.1f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 10.0f, 5.88235f));
		model = glm::translate(model, glm::vec3(-0.9f, 1.0f, 0.415f));

		//Pata 2
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.7f, -0.65f, -0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.6f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.40f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 1.66666f, 5.88235f));
		model = glm::translate(model, glm::vec3(0.7f, 0.65f, 0.415f));

		//Punta 2
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.7f, -1.0f, -0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.1f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 10.0f, 5.88235f));
		model = glm::translate(model, glm::vec3(0.7f, 1.0f, 0.415f));

		//Pata 3
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.9f, -0.65f, 0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.6f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.40f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 1.66666f, 5.88235f));
		model = glm::translate(model, glm::vec3(-0.9f, 0.65f, -0.415f));

		//Punta 3
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.9f, -1.0f, 0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.1f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 10.0f, 5.88235f));
		model = glm::translate(model, glm::vec3(-0.9f, 1.0f, -0.415f));

		//Pata 4
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.7f, -0.65f, 0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.6f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.40f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 1.66666f, 5.88235f));
		model = glm::translate(model, glm::vec3(0.7f, 0.65f, -0.415f));

		//Punta 4
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.7f, -1.0f, 0.415f));
		model = glm::scale(model, glm::vec3(0.17f, 0.1f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.88235f, 10.0f, 5.88235f));
		model = glm::translate(model, glm::vec3(0.7f, 1.0f, -0.415f));

		//Cuello
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.1f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.7f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.95f, 0.95f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.0f, 1.4285714f, 1.0f));
		model = glm::translate(model, glm::vec3(1.1f, 0.0f, 0.0f));

		//Cabeza
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.50f, 0.4f, 0.0f));
		model = glm::scale(model, glm::vec3(0.7f, 0.9f, 1.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.45f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(1.428571f, 1.111111f, 0.666666f));
		model = glm::translate(model, glm::vec3(1.5f, -0.4f, 0.0f));

		//Cabeza Blanca
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.50f, -0.11f, 0.0f));
		model = glm::scale(model, glm::vec3(0.7f, 0.18f, 1.5f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.95f, 0.95f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(1.428571f, 5.55555f, 0.666666f));
		model = glm::translate(model, glm::vec3(1.5f, -0.63f, 0.0f));

		//Cabeza 2 (top)
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.5f, 0.9f, 0.0f));
		model = glm::scale(model, glm::vec3(0.7f, 0.2f, 0.75f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.45f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(1.428571f, 5.0f, 1.33333f));
		model = glm::translate(model, glm::vec3(1.5f, -0.9f, 0.0f));
		
		//Cabeza 3 (frente)
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.95f, 0.70f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.9f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.6f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 1.11111f));
		model = glm::translate(model, glm::vec3(1.95f, 0.9f, 0.0f));

		//Cabeza 4 (separación)
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.95f, 0.52f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.54f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.6f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 1.8518f));
		model = glm::translate(model, glm::vec3(1.95f, -0.52f, 0.0f));

		//ojo1
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.95f, 0.52f, 0.36f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.18f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 5.55555f));
		model = glm::translate(model, glm::vec3(1.95f, -0.52f, -0.36f));

		//ojo2
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.95f, 0.52f, -0.36f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.18f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 5.55555f));
		model = glm::translate(model, glm::vec3(1.95f, -0.52f, -0.36f));

		//Cabeza 5
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.95f, 0.25f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.36f, 1.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.6f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 2.77777f, 1.0f));
		model = glm::translate(model, glm::vec3(1.95f, -0.25f, 0.0f));

		//Cabeza 5 Blanco
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.95f, -0.02f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.95f, 0.95f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 1.25f));
		model = glm::translate(model, glm::vec3(1.95f, 0.2f, 0.0f));

		//Ocico
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.13f, 0.25f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.36f, 0.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.45f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 2.77777f, 1.25f));
		model = glm::translate(model, glm::vec3(2.13f, -0.25f, 0.0f));

		//Ocico Blanco
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.13f, -0.02f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.8f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.95f, 0.95f, 0.95f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 1.25f));
		model = glm::translate(model, glm::vec3(2.13f, 0.2f, 0.0f));

		//Nariz
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.31f, 0.16f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.36f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.05f, 0.05f, 0.05f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 2.77777f, 1.11111f));
		model = glm::translate(model, glm::vec3(2.13f, -0.16f, 0.0f));

		//Nariz Blanco 
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.31f, -0.02f, 0.0f));
		model = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.36f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.90f, 0.90f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(5.55555f, 5.55555f, 1.25f));
		model = glm::translate(model, glm::vec3(2.31f, 0.02f, 0.0f));

		//Oreja derecha 1
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.5f, 1.05f, 0.5625f));
		model = glm::scale(model, glm::vec3(0.35f, 0.4f, 0.375f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.75f, 0.35f, 0.08f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(2.85f, 2.5f, 2.66666f));
		model = glm::translate(model, glm::vec3(1.5f, -1.05f,0.5625f));

		//Oreja izquierda 1
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.5f, 1.05f, -0.5625f));
		model = glm::scale(model, glm::vec3(0.35f, 0.4f, 0.375f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.75f, 0.35f, 0.08f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(2.85f, 2.5f, 2.66666f));
		model = glm::translate(model, glm::vec3(1.5f, -1.05f, 0.5625f));

		//cola

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.5f, 0.0875f, 0.0f));
		model = glm::scale(model, glm::vec3(0.6f, 0.17f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.90f, 0.45f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::scale(model, glm::vec3(1.6666f, 5.8822f, 5.8822f));
		model = glm::translate(model, glm::vec3(-1.5f, -0.0875f, 0.0f));

		//cola2

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.87f, 0.0875f, 0.0f));
		model = glm::scale(model, glm::vec3(0.17f, 0.17f, 0.17f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3f(colorLoc, 0.9f, 0.6f, 0.10f);
		glDrawArrays(GL_TRIANGLES, 0, 36);



		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		 movY += 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		 movY -= 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.08f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.4f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.4f;
 }


