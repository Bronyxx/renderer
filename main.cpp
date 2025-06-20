
#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


const char*vertexShaderSource="#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"  // Vertex position input
"void main( )\n"
"{\n"
    "gl_Position = vec4(aPos, 1.0);\n"  // Pass position to fragment shader
"}\0";
const char*FragmentShaderSource="#version 330 core\n"
"out vec4 FragColor;\n"
"void main( )\n"
"{\n"
    "FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\0";

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
    GLFWwindow* window=glfwCreateWindow(800,800,"main window",NULL,NULL);
     if(window==NULL){
       std::cout<<"error loading window"<<std::endl;
       glfwTerminate();
       return -1;
    }
    glfwMakeContextCurrent(window);
  
 

   
    gladLoadGL();
    glViewport(0,0,800,800);
    glClearColor(0.07f,0.13f,0.17f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
   
     GLfloat vertices[]={
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f

    };
     
       //initializing vertex shader
    GLuint VertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(VertexShader);
    // initialize fragment shader
    GLuint FragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader,1,&FragmentShaderSource,NULL);
    glCompileShader(FragmentShader);
    // create shader program
    GLuint shaderProgram=glCreateProgram();
    glAttachShader(shaderProgram,VertexShader);
    glAttachShader(shaderProgram,FragmentShader);
    glLinkProgram(shaderProgram);
    //passing memory from CPU to GPU
    GLuint VAO,VBO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(GL_FLOAT),(void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    
    while(!glfwWindowShouldClose(window))

    {
        glClearColor(0.07f,0.13f,0.17f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);
        glfwSwapBuffers(window);
        glfwPollEvents();
       
    }
    glDeleteVertexArrays(1,&VAO);
    glDeleteBuffers(1,&VBO);
    glDeleteProgram(shaderProgram);

    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
   