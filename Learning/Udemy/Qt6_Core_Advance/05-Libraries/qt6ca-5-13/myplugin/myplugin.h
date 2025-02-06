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
#ifndef MYPLUGIN_H
#define MYPLUGIN_H

#include <QObject>
#include "plugin.h"

class MyPlugin : public QObject, public Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.thanhtungpfiev.plugin")
    Q_INTERFACES(Plugin)
public:
    explicit MyPlugin(QObject *parent = nullptr);
    ~MyPlugin();

signals:

public slots:

    // Plugin interface
public:
    void test(QString name) override;
};

#endif // MYPLUGIN_H
