/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/6/2025
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
#include "myplugin.h"
#include <QDebug>

MyPlugin::MyPlugin(QObject *parent)
{
    Q_UNUSED(parent);
    qInfo() << "Plugin Constructed";
}

MyPlugin::~MyPlugin()
{
    qInfo() << "Plugin Deconstructed";
}

void MyPlugin::test(QString name)
{
    qInfo() << "Test from plugin: " << name;
}
