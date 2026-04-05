#include "App/App.hpp"

App app;

int main()
{
    if (app.Init()) {
        app.Run();
    }

    return 0;
}
