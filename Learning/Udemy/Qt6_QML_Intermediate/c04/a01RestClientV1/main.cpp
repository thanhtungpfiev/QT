/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/24/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename %{Cpp:License:FileName}
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 *****************************************************************************/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "appwrapper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    AppWrapper wrapper;
    if (!wrapper.initialize(&app)) {
        return -1;
    }

    return app.exec();
}
