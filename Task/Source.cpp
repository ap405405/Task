#include <GLFW/glfw3.h>
#include "math.h"
#include <iostream>
#include <vector>
#include "GeometryObj.h"
#include "Circle.h"
#include "ThickerLine.h"
#include "Square.h"
#include "Down.h"
#include "Right.h"
#include "One.h"
#include "Up.h"
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		//assign all pixels red color 
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++) {
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}



		std::vector<GeometryObj*> go_vector;
		GeometryObj * temp = nullptr;
		int k = 0;
		for (int i = 0; i < 6; i++) {
			if (i < 3) {
				temp = new Circle(75 + i * 250, 375, 60);
			}
			else {

				temp = new Circle(75 + k * 250, 150, 60);
				k += 1;
			}
			go_vector.push_back(temp);
		}

		go_vector.push_back(new ThickerLine);
		go_vector.push_back(new Square);
		go_vector.push_back(new Down);
		go_vector.push_back(new Right);
		go_vector.push_back(new One);
		go_vector.push_back(new Up);
		
		for (auto itr : go_vector) {
			(itr)->draw();
		}



		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);


		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		std::cout << xpos << "   " << 480 - ypos << std::endl;
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	delete[] pixels;
	//free(pixels);
	return 0;
}