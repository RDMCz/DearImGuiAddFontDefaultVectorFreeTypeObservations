#include "App.hpp"

void App::Start()
{
    const ImGuiIO& io = ImGui::GetIO();

    io.Fonts->AddFontDefaultVector();

    m_font_proggyforever = io.Fonts->AddFontFromFileTTF("./Resource/ProggyForever-Regular.ttf");

    IM_ASSERT(m_font_proggyforever != nullptr);
}
