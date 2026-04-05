#include "App.hpp"
#include "freetype/freetype.h"

void App::Update()
{
    // Demonstration window
    constexpr ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;
    constexpr auto text = "Dear ImGui Aa Bb Cc Dd Ee";
    constexpr auto font_size = 28.0f;

    ImGui::Begin("Blurry forever", nullptr, flags);

    ImGui::PushFont(nullptr, font_size);
#ifdef IMGUI_ENABLE_FREETYPE
    ImGui::Text("(FreeType is enabled, version %d.%d.%d)", FREETYPE_MAJOR, FREETYPE_MINOR, FREETYPE_PATCH);
#else
    ImGui::Text("(FreeType is disabled)");
#endif
#ifdef PROGGY_FOREVER_EXTRA_SCALE
    ImGui::Text("(ExtraSizeScale is applied)");
#else
    ImGui::Text("(ExtraSizeScale is NOT applied)");
#endif
    ImGui::PopFont();

    ImGui::PushFont(nullptr, font_size);
    ImGui::Text("%s (added via AddFontDefaultVector)", text);
    ImGui::PopFont();

    ImGui::PushFont(m_font_proggyforever, font_size);
    ImGui::Text("%s (added via AddFontFromFileTTF)", text);
    ImGui::PopFont();

    ImGui::End();

    // Demo window
    ImGui::ShowDemoWindow();
}
