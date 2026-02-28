//Orihuela Castillo Luis Yehosua
//320255409
//Practica 2
//20 de Febrero de 2026

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 667;	


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Dibujo de Primitivas en 2D", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		//Ala
		1.0f, 1.0f, 0.0f, 0.9f,0.1f,0.1f, //0
		0.0625f, 0.4002998501f, 0.0f, 1.0f,0.4f,0.4f, //1
		0.43f, 0.4002998501f, 0.0f, 0.7f,0.0f,0.2f, //2
		-0.375f, 0.2803598201f, 0.0f, 0.8f,0.2f,0.5f, //3
		-0.4375f, 0.01049475262f, 0.0f, 0.6f,0.0f,0.4f, //4
		-0.265f, -0.4392803598f, 0.0f, 0.9f,0.3f,0.6f, //5
		-0.2f, -0.2593703148f, 0.0f, 1.0f,0.6f,0.6f, //6
		0.1325f, 0.1214392804f, 0.0f, 0.7f,0.1f,0.3f, //7
		0.1825f, 0.2593703148f, 0.0f, 1.0f,1.0f,1.0f, //8

		//Cola
		0.8f, -0.1844077961f, 0.0f, 0.8f,0.0f,0.5f, //9
		0.6575f, -0.1214392804f, 0.0f, 1.0f,0.5f,0.5f, //10
		0.6925f, -0.1364317841f, 0.0f, 0.6f,0.0f,0.6f, //11
		0.655f, -0.1454272864f, 0.0f, 0.9f,0.2f,0.4f, //12
		0.5375f, -0.1094452774f, 0.0f, 1.0f,0.7f,0.7f, //13
		0.575f, -0.1604197901f, 0.0f, 0.7f,0.0f,0.5f, //14
		0.525f, -0.1394302849f, 0.0f, 0.9f,0.1f,0.3f, //15
		0.325f, -0.06446776612f, 0.0f, 1.0f,0.4f,0.6f, //16
		0.3725f, -0.1094452774f, 0.0f, 0.8f,0.0f,0.3f, //17
		0.32f, -0.1094452774f, 0.0f, 1.0f,1.0f,1.0f, //18
		0.07f, -0.08245877061f, 0.0f, 0.85f,0.15f,0.25f, //19
		-0.0525f, -0.1139430285f, 0.0f, 0.75f,0.0f,0.45f, //20
		-0.0425f, -0.5592203898f, 0.0f, 1.0f,0.5f,0.6f, //21
		0.0875f, -0.3343328336f, 0.0f, 0.6f,0.0f,0.6f, //22
		0.1025f, -0.2893553223f, 0.0f, 0.95f,0.3f,0.4f, //23
		0.3675f, -0.2173913043f, 0.0f, 0.7f,0.0f,0.2f, //24
		0.37f, -0.2023988006f, 0.0f, 1.0f,0.6f,0.6f, //25
		0.575f, -0.2293853073f, 0.0f, 0.8f,0.0f,0.4f, //26
		0.575f, -0.1994002999f, 0.0f, 0.65f,0.0f,0.55f, //27
		0.7f, -0.2053973013f, 0.0f, 1.0f,0.4f,0.5f, //28
		0.7f, -0.1934032984f, 0.0f, 0.9f,0.1f,0.3f, //29

		//Cabeza
		-0.3875f, 0.5952023988f, 0.0f, 0.8f,0.0f,0.5f, //30
		-0.625f, 0.4002998501f, 0.0f, 1.0f,0.7f,0.7f, //31
		-0.605f, 0.4602698651f, 0.0f, 0.6f,0.0f,0.6f, //32
		-0.6025f, 0.5202398801f, 0.0f, 0.9f,0.2f,0.4f, //33
		-0.6875f, 0.4242878561f, 0.0f, 0.7f,0.0f,0.3f, //34
		-0.6875f, 0.4662668666f, 0.0f, 1.0f,0.5f,0.6f, //35
		-0.7325f, 0.4032983508f, 0.0f, 0.5f,0.0f,0.5f, //36
		-0.8f, 0.3733133433f, 0.0f, 0.85f,0.15f,0.35f, //37
		-0.7875f, 0.3013493253f, 0.0f, 0.95f,0.4f,0.5f, //38
		-0.69f, 0.3643178411f, 0.0f, 0.6f,0.0f,0.4f, //39
		-0.6375f, 0.3013493253f, 0.0f, 1.0f,1.0f,1.0f, //40
		-0.7225f, 0.2743628186f, 0.0f, 0.75f,0.0f,0.5f, //41
		-0.7125f, 0.3013493253f, 0.0f, 0.9f,0.3f,0.6f, //42
		-0.7575f, 0.3013493253f, 0.0f, 0.7f,0.0f,0.45f, //43
		-0.59f, 0.4302848576f, 0.0f, 1.0f,0.6f,0.6f, //44
		-0.5775f, 0.4182908546f, 0.0f, 0.8f,0.0f,0.4f, //45
		-0.3875f, 0.5352323838f, 0.0f, 0.95f,0.2f,0.4f, //46
		-0.55f, 0.3703148426f, 0.0f, 0.6f,0.0f,0.6f, //47
		-0.5125f, 0.3253373313f, 0.0f, 1.0f,0.5f,0.7f, //48
		-0.4875f, -0.09445277361f, 0.0f, 0.7f,0.0f,0.3f, //49
		-0.7f, -0.03448275862f, 0.0f, 0.9f,0.1f,0.2f, //50
		-0.5125f, -0.1544227886f, 0.0f, 0.8f,0.0f,0.5f, //51
		-0.5525f, -0.3583208396f, 0.0f, 1.0f,0.4f,0.6f, //52

		//Patas
		-0.4025f, -0.07946026987f, 0.0f, 0.6f,0.0f,0.4f, //53
		-0.425f, -0.4242878561f, 0.0f, 0.9f,0.2f,0.5f, //54
		-0.5925f, -0.5352323838f, 0.0f, 1.0f,0.7f,0.7f, //55
		-0.57f, -0.4392803598f, 0.0f, 0.75f,0.0f,0.45f, //56
		-0.6625f, -0.5352323838f, 0.0f, 0.85f,0.15f,0.35f, //57
		-0.655f, -0.5892053973f, 0.0f, 0.6f,0.0f,0.6f, //58
		-0.4375f,-0.5892053973f, 0.0f, 1.0f,0.5f,0.6f, //59
		-0.0975f, -0.1364317841f, 0.0f, 0.7f,0.0f,0.3f, //60
		-0.105f, -0.3883058471f, 0.0f, 0.9f,0.3f,0.6f, //61
		-0.055f, -0.3793103448f, 0.0f, 1.0f,0.6f,0.6f, //62
		-0.045f, -0.4362818591f, 0.0f, 0.8f,0.0f,0.4f, //63
		-0.2475f, -0.5892053973f, 0.0f, 0.65f,0.0f,0.5f, //64
		-0.04f, -0.5892053973f, 0.0f, 1.0f,1.0f,1.0f, //65
		-0.1825f, -0.5352323838f, 0.0f, 0.85f,0.2f,0.4f, //66
		-0.10375f, -0.3793103448f, 0.0f, 0.7f,0.0f,0.5f, //67
		-0.1325f, -0.4452773613f, 0.0f, 0.95f,0.4f,0.5f, //68
		-0.26f, -0.5352323838f, 0.0f, 0.6f,0.0f,0.6f, //69

	};
	unsigned int indices[] = {  // note that we start from 0!
		//Triangle
		8,2,1,
		1,3,4,
		4,5,6,
		1,4,6,
		1,6,7,
		1,7,8,
		10,11,12,
		13,14,15,
		16,17,18,
		20,21,22,
		30,31,32,
		32,33,34,
		34,35,36,
		31,32,37,
		31,37,38,
		31,39,40,
		38,39,40,
		41,42,43,
		46,45,47,
		49,50,51,
		50,51,52,
		49,51,53,
		51,53,54,
		53,54,5,
		51,54,55,
		56,57,55,
		58,59,54,
		6,60,62,
		6,61,62,
		60,63,20,
		68,69,66,
		63,64,65,
		62,63,67,
		67,63,68,
		68,63,66,
		40,50,49,
		48,40,49,
		31,44,48,
		31,48,40,

		//Lines
		9,10,
		12,13,
		15,16, 
		18,19,
		20,22,
		22,23,
		19,23,
		19,20,
		23,24,
		24,25,
		25,26,
		26,27,
		27,28,
		28,29,
		29,9,
		17,25,
		14,27,
		11,29,
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);


        //glPointSize(5);
        //glDrawArrays(GL_POINTS,0,71);
        
        //glDrawArrays(GL_LINES,9,10);
		//glDrawArrays(GL_LINES, 12, 13);
		//glDrawArrays(GL_LINES, 15, 16);
        //glDrawArrays(GL_LINE_LOOP,0,4);
        
        //glDrawArrays(GL_TRIANGLES,10,12);
        glDrawElements(GL_TRIANGLES, 117,GL_UNSIGNED_INT,0);
		glDrawElements(GL_LINES, 36, GL_UNSIGNED_INT, (void*)(117 * sizeof(unsigned int)));
        
        
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}