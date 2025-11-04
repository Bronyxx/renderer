
#include<iostream>
#include<math.h>
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include<fstream>
#include<string>
#include <sstream>
 


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
     float positions[6]={
        -0.5f,-0.5f,
         0.0f,0.5f,
         0.5f,-0.5f

     };
   
   
    
    while(!glfwWindowShouldClose(window))

    {
       glClear(GL_COLOR_BUFFER_BIT);
       glDrawArrays(GL_TRIANGLES,0,3);
        glfwSwapBuffers(window);
        glfwPollEvents();
       
    }
    
    
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
     