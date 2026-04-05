cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME "DearImGuiProggyForeverFreeTypeBlurIssue")
set(BINARY_NAME "DearImGuiProggyForeverFreeTypeBlurIssue")

# Project setup
project("${PROJECT_NAME}")
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)

# ==============================
# =   FREETYPE/FONT SETTINGS   =
# ==============================
set(USE_FREETYPE_ANY ON)
set(USE_FREETYPE_LATEST ON)
set(APPLY_EXTRA_SCALE ON)
# ==============================

# Build only the necessary parts of GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Minimal FreeType installation aswell
set(FT_DISABLE_ZLIB ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BZIP2 ON CACHE BOOL "" FORCE)
set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BROTLI ON CACHE BOOL "" FORCE)

# Dependencies
add_subdirectory(Dependency/glfw-3.4)
add_subdirectory(Dependency/glad)
add_subdirectory(Dependency/imgui)

# Apply FreeType/Font settings
if (APPLY_EXTRA_SCALE)
    target_compile_definitions(imgui PUBLIC PROGGY_FOREVER_EXTRA_SCALE)
endif ()

if (USE_FREETYPE_LATEST)
    add_subdirectory(Dependency/freetype-VER-2-14-3)
    target_compile_definitions(imgui PUBLIC IMGUI_ENABLE_FREETYPE)
else ()
    add_subdirectory(Dependency/freetype-VER-2-13-3)
endif ()

if (USE_FREETYPE_ANY)
    target_compile_definitions(imgui PUBLIC IMGUI_ENABLE_FREETYPE)
endif ()

# Executable setup
file(GLOB_RECURSE SOURCES
        "${PROJECT_SOURCE_DIR}/App/*.cpp"
)

add_executable("${BINARY_NAME}"
        "Run.cpp"
        ${SOURCES}
)

if (MSVC)
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)
    set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") # No console
endif ()

target_link_libraries("${BINARY_NAME}"
        glfw
        glad
        imgui
        freetype
)

# Copy resources folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resource
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)
