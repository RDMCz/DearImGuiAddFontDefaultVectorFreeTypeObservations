cmake_minimum_required(VERSION 3.25)

project(imgui)

add_library(imgui)

set(IMGUI_DIR "imgui-1.92.7")

target_sources(imgui PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/imgui.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/imgui_demo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/imgui_draw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/imgui_tables.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/imgui_widgets.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/misc/freetype/imgui_freetype.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp"
)

target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/${IMGUI_DIR}")

target_link_libraries(imgui PUBLIC glfw glad freetype)
