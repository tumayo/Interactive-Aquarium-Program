#include "Angel.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

typedef vec4  color4;
typedef vec4  point4;

// Model-view and projection matrices uniform location
GLuint  ModelView, Projection;

//----------------------------------------------------------------------------
point4 fish1[49152]; // 49152: total number of vertices in polygons
point4 octopus[23988];
point4 seashell[29704];
point4 urchin[22080];
color4 fish_color[49152];
color4 octopus_color[23988];
color4 urchin_color[22080];
color4 seashell_color[29704];


void readOffFish1() {

	//Fish1
	char str[255];
	ifstream in("fish.txt");

	if (!in) {
		cout << "Cannot open input file.\n";
	}
	point4 fish_vertices[12290];
	int vertex_indexes[49152];

	in.getline(str, 255);
	in.getline(str, 255);
	for (int i = 0; i < 12290; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * x = strtok(str, " ");
		char * y = strtok(NULL, " ");
		char * z = strtok(NULL, " ");
		float x_coord = atof(x);
		float y_coord = atof(y);
		float z_coord = atof(z);
		point4 point = point4(x_coord, y_coord, z_coord, 1.0);
		fish_vertices[i] = point;
	}
	int counter = 0;
	for (int i = 0; i < 12288; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * empty4 = strtok(str, " ");
		char * chone = strtok(NULL, " ");
		char * chtwo = strtok(NULL, " ");
		char * chthree = strtok(NULL, " ");
		char * chfour = strtok(NULL, " ");
		int one = atoi(chone);
		int two = atoi(chtwo);
		int three = atoi(chthree);
		int four = atoi(chfour);

		vertex_indexes[counter++] = one;
		vertex_indexes[counter++] = two;
		vertex_indexes[counter++] = three;
		vertex_indexes[counter++] = four;
	}
	//printf("counter %d", counter);
	counter = 0;

	for (int i = 0; i < 49152; i++) {
		fish1[counter++] = fish_vertices[vertex_indexes[i]];

	}
	in.close();
}
void readOffOctopus() {

	//Octopus
	char str[255];
	ifstream in("octopus.txt");

	if (!in) {
		cout << "Cannot open input file.\n";
	}
	point4 octopus_vertices[4000];
	int vertex_indexes[23988];

	in.getline(str, 255);
	in.getline(str, 255);
	for (int i = 0; i < 4000; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * x = strtok(str, " ");
		char * y = strtok(NULL, " ");
		char * z = strtok(NULL, " ");
		float x_coord = atof(x);
		float y_coord = atof(y);
		float z_coord = atof(z);
		point4 point = point4(x_coord, y_coord, z_coord, 1.0);
		octopus_vertices[i] = point;
	}
	int counter = 0;
	for (int i = 0; i < 7996; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * empty3 = strtok(str, " ");
		char * chone = strtok(NULL, " ");
		char * chtwo = strtok(NULL, " ");
		char * chthree = strtok(NULL, " ");
		int one = atoi(chone);
		int two = atoi(chtwo);
		int three = atoi(chthree);

		vertex_indexes[counter++] = one;
		vertex_indexes[counter++] = two;
		vertex_indexes[counter++] = three;
	}
	//printf("counter %d", counter);
	counter = 0;

	for (int i = 0; i < 23988; i++) {
		octopus[counter++] = octopus_vertices[vertex_indexes[i]];
	}
	in.close();
}
void readOffSeaShell() {

	//Fish1
	char str[255];
	ifstream in("seashell.txt");

	if (!in) {
		cout << "Cannot open input file.\n";
	}
	point4 seashell_vertices[7428];
	int vertex_indexes[29704];

	in.getline(str, 255);
	in.getline(str, 255);
	for (int i = 0; i < 7428; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * x = strtok(str, " ");
		char * y = strtok(NULL, " ");
		char * z = strtok(NULL, " ");
		float x_coord = atof(x);
		float y_coord = atof(y);
		float z_coord = atof(z);
		point4 point = point4(x_coord, y_coord, z_coord, 1.0);
		seashell_vertices[i] = point;
	}
	int counter = 0;
	for (int i = 0; i < 7426; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * empty4 = strtok(str, " ");
		char * chone = strtok(NULL, " ");
		char * chtwo = strtok(NULL, " ");
		char * chthree = strtok(NULL, " ");
		char * chfour = strtok(NULL, " ");
		int one = atoi(chone);
		int two = atoi(chtwo);
		int three = atoi(chthree);
		int four = atoi(chfour);

		vertex_indexes[counter++] = one;
		vertex_indexes[counter++] = two;
		vertex_indexes[counter++] = three;
		vertex_indexes[counter++] = four;
	}
	//printf("counter %d", counter);
	counter = 0;

	for (int i = 0; i < 29704; i++) {
		seashell[counter++] = seashell_vertices[vertex_indexes[i]];

	}
	in.close();
}
void readOffUrchin() {

	char str[255];
	ifstream in("urchin.txt");

	if (!in) {
		cout << "Cannot open input file.\n";
	}
	point4 urchin_vertices[5522];
	int vertex_indexes[22080];

	in.getline(str, 255);
	in.getline(str, 255);
	for (int i = 0; i < 5522; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * x = strtok(str, " ");
		char * y = strtok(NULL, " ");
		char * z = strtok(NULL, " ");
		float x_coord = atof(x);
		float y_coord = atof(y);
		float z_coord = atof(z);
		point4 point = point4(x_coord, y_coord, z_coord, 1.0);
		urchin_vertices[i] = point;
	}
	int counter = 0;
	for (int i = 0; i < 5520; i++) {
		in.getline(str, 255);  // delim defaults to '\n'
		//if (in) cout << str << endl;
		char * empty4 = strtok(str, " ");
		char * chone = strtok(NULL, " ");
		char * chtwo = strtok(NULL, " ");
		char * chthree = strtok(NULL, " ");
		char * chfour = strtok(NULL, " ");

		int one = atoi(chone);
		int two = atoi(chtwo);
		int three = atoi(chthree);
		int four = atoi(chfour);

		vertex_indexes[counter++] = one;
		vertex_indexes[counter++] = two;
		vertex_indexes[counter++] = three;
		vertex_indexes[counter++] = four;
	}
	//printf("counter %d", counter);
	counter = 0;

	for (int i = 0; i < 22080; i++) {
		urchin[counter++] = urchin_vertices[vertex_indexes[i]];
	}
	in.close();
}

int counters_x[5];
int counters_y[5];
vec3 displacements[5];

GLuint vao[5]; // Create a vertex array object
GLuint buffers[5];
GLuint vColor;
double global_width = 512;
double global_height = 512;
// OpenGL initialization
void
init()
{
	readOffFish1();
	readOffOctopus();
	readOffSeaShell();
	readOffUrchin();

	for (int i = 0; i < 49152; i++)
		fish_color[i] = color4(1.0, 1.0, 0, 1);

	for (int i = 0; i < 23988; i++)
		octopus_color[i] = color4(128.0 / 255, 128.0 / 255, 128.0 / 255, 1);

	for (int i = 0; i < 22080; i++)
		urchin_color[i] = color4(166.0 / 255, 42.0 / 255, 42.0 / 255, 1);

	for (int i = 0; i < 22080; i++)
		seashell_color[i] = color4(1, 253.0 / 255, 208.0 / 255, 1);

	for (int i = 0; i < 5; i++) {
		counters_x[i] = -1;
		counters_y[i] = -1;
	}
	displacements[0] = vec3(0, 0, -2.2);
	displacements[1] = vec3(0, -0.6, -2.2);
	displacements[2] = vec3(0.69, -0.69, -2.2);
	displacements[3] = vec3(0.55, -0.88, -2.5);

	// Create and initialize a buffer object
	glGenBuffers(1, &buffers[0]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(fish1) * 2,
		NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(fish1), fish1);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(fish1), sizeof(fish_color), fish_color);


	glGenBuffers(1, &buffers[1]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(octopus) * 2,
		NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(octopus), octopus);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(octopus), sizeof(octopus_color), octopus_color);

	glGenBuffers(1, &buffers[2]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(urchin) * 2,
		NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(urchin), urchin);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(urchin), sizeof(urchin_color), urchin_color);

	glGenBuffers(1, &buffers[3]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(seashell) * 2,
		NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(seashell), seashell);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(seashell), sizeof(seashell_color), seashell_color);


	// Load shaders and use the resulting shader program
	GLuint program = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(program);
	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation(program, "vPosition");
	vColor = glGetAttribLocation(program, "vColor");

	glGenVertexArrays(3, vao);

	//fish1
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(fish1)));

	//octopus
	glBindVertexArray(vao[1]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(octopus)));

	//urchin
	glBindVertexArray(vao[2]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(urchin)));

	//sea shell
	glBindVertexArray(vao[3]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[3]);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(seashell)));


	// Retrieve transformation uniform variable locations
	ModelView = glGetUniformLocation(program, "ModelView");
	Projection = glGetUniformLocation(program, "Projection");

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.7, 0.9, 1.0, 1.0);
}

//----------------------------------------------------------------------------
int feed_flag = 0;
float feed_x = 0;
float feed_y = 0;
float rotate_angle = 1;
void
display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//  Generate tha model-view matrix
	mat4  model_view;
	if (counters_x[0] == -1)
		model_view = Translate(displacements[0]) * RotateX(-90) * Scale(0.01, 0.01, 0.01);
	else
		model_view = Translate(displacements[0]) * RotateY(180) * RotateX(-90) * Scale(0.01, 0.01, 0.01);

	//fish1
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);
	glDrawArrays(GL_QUADS, 0, 49152);

	if (counters_x[1] == -1)
		model_view = Translate(displacements[1]) *  RotateY(-90) * Scale(0.25, 0.25, 0.25);
	else
		model_view = Translate(displacements[1]) * RotateY(180) * RotateY(-90) * Scale(0.25, 0.25, 0.25);

	//octopus
	glBindVertexArray(vao[1]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);
	glDrawArrays(GL_TRIANGLES, 0, 23988);

	if (counters_x[2] == -1)
		model_view = Translate(displacements[2]) * RotateZ(rotate_angle) * Scale(0.04, 0.04, 0.04);
	else
		model_view = Translate(displacements[2]) * RotateZ(rotate_angle) * Scale(0.04, 0.04, 0.04);

	//urchin
	glBindVertexArray(vao[2]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[2]);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);
	glDrawArrays(GL_QUADS, 0, 22080);

	//sea shell
	glBindVertexArray(vao[3]);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[3]);
	model_view = Translate(displacements[3]) * RotateY(45) * Scale(0.03, 0.03, 0.03);
	glUniformMatrix4fv(ModelView, 1, GL_TRUE, model_view);
	glDrawArrays(GL_QUADS, 0, 29704);

	glutSwapBuffers();

}
//----------------------------------------------------------------------------

void
keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 033:  // Escape key
	case 'q': case 'Q':
		exit(EXIT_SUCCESS);
		break;
	}
}

//----------------------------------------------------------------------------

void
mouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		feed_flag = 1;
		feed_x = (float)(x - global_width/2) / global_width;
		feed_y = (float)(global_height/2 - y) / global_height;

		//printf("feed x: %f  feed y: %f\n", feed_x, feed_y);
	}
	else if (state != GLUT_DOWN) {
		feed_flag = 0;
	}

}

//----------------------------------------------------------------------------
void
idle(void)
{
	//there is a feed flag because there are different actions in feeding and normal cases
	if (feed_flag == 0) {
		for (int i = 0; i < 3; i++) {
			int r_x = rand() % 10000;
			int r_y = rand() % 10000;

			//where direction in both x and y are decided 
			if (displacements[i].x + 0.0002 < -0.7*global_width/ 512.0 || r_x>10000 - 4)
				counters_x[i] = -counters_x[i];
			else if (displacements[i].x + 0.0002 > 0.7*global_width / 512.0 || r_x > 10000 - 4)
				counters_x[i] = -counters_x[i];

			if (displacements[i].y + 0.0002 < -0.7*global_height / 512.0 || r_y>10000 - 4)
				counters_y[i] = -counters_y[i];
			else if (displacements[i].y + 0.0002 > 0.7*global_height / 512.0 || r_y > 10000 - 4)
				counters_y[i] = -counters_y[i];

			//urchin has a different movement both translation and rotation on the ground
			if (i != 2) {
				if (counters_x[i] == -1 && counters_y[i] == -1)
					displacements[i] += vec3(-0.0002, -0.0002, 0);
				else 	if (counters_x[i] == -1 && counters_y[i] == 1)
					displacements[i] += vec3(-0.0002, 0.0002, 0);
				else if (counters_x[i] == 1 && counters_y[i] == -1)
					displacements[i] += vec3(0.0002, -0.0002, 0);
				else if (counters_x[i] == 1 && counters_y[i] == 1)
					displacements[i] += vec3(0.0002, 0.0002, 0);
			}
			else if (i == 2) {

				if (counters_x[i] == -1) {
					rotate_angle += 0.1;
					displacements[i] += vec3(-0.0002, 0, 0);
				}
				else if (counters_x[i] == 1) {
					displacements[i] += vec3(0.0002, 0, 0);
					rotate_angle -= 0.1;
				}
			}

		}
	}
	else {
		for (int i = 0; i < 2; i++) {
			if (feed_x > displacements[i].x && abs(feed_x - displacements[i].x) >= 0.0003) {
				if (counters_x[i] == -1)
					counters_x[i] = 1;
				displacements[i] += vec3(0.0002, 0, 0);
			}
			else if (feed_x < displacements[i].x && abs(feed_x - displacements[i].x) >= 0.0003) {
				if (counters_x[i] == 1)
					counters_x[i] = -1;
				displacements[i] += vec3(-0.0002, 0, 0);
			}
			if (feed_y > displacements[i].y)
				displacements[i] += vec3(0, 0.0002, 0);

			else if (feed_y < displacements[i].y)
				displacements[i] += vec3(0, -0.0002, 0);

		}
		int i = 2;
		int r_x = rand() % 10000;
		int r_y = rand() % 10000;
		if (displacements[i].x + 0.0002 < -0.7 || r_x>10000 - 4)
			counters_x[i] = -counters_x[i];
		else if (displacements[i].x + 0.0002 > 0.7 || r_x > 10000 - 4)
			counters_x[i] = -counters_x[i];

		if (displacements[i].y + 0.0002 < -0.7 || r_y>10000 - 4)
			counters_y[i] = -counters_y[i];
		else if (displacements[i].y + 0.0002 > 0.7 || r_y > 10000 - 4)
			counters_y[i] = -counters_y[i];
		if (counters_x[i] == -1) {
			rotate_angle += 0.1;
			displacements[i] += vec3(-0.0002, 0, 0);
		}
		else if (counters_x[i] == 1) {
			displacements[i] += vec3(0.0002, 0, 0);
			rotate_angle -= 0.1;
		}

	}

	glutPostRedisplay();
}

//----------------------------------------------------------------------------

void
reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	GLfloat aspect = GLfloat(width) / height;
	global_width = width;
	global_height = height;

	displacements[0] = vec3(0, 0, -2.2);
	displacements[1] = vec3(0, -0.6 * global_height/ 512.0, -2.2);
	displacements[2] = vec3(0.69 * global_width / 512.0, -0.69 * global_height / 512.0, -2.2);
	displacements[3] = vec3(0.55 * global_width/ 512.0, -0.88 * global_height/ 512.0, -2.5);

	mat4 projection = Perspective(45.0, aspect, 0.5, 10);
	glUniformMatrix4fv(Projection, 1, GL_TRUE, projection);

}

int
main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Aquarium");

	printf("Supported GLSL version is %s.\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("%s\n%s\n%s\n",
		glGetString(GL_RENDERER),  // e.g. Intel HD Graphics 3000 OpenGL Engine
		glGetString(GL_VERSION),    // e.g. 3.2 INTEL-8.0.61
		glGetString(GL_SHADING_LANGUAGE_VERSION));

	glewExperimental = GL_TRUE;
	glewInit();

	init();

	srand(time(NULL));
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}
