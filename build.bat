@echo off
g++ main.cpp glad.c ^
imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp ^
imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp ^
-Iinclude -Iimgui -Iimgui/backends ^
-lglfw3 -lgdi32 -lopengl32 -luser32 -o build/app.exe

