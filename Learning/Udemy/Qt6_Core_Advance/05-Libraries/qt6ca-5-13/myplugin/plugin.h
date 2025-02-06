/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/6/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename plugin.h
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef PLUGIN_H
#define PLUGIN_H

#include <QString>

class Plugin
{
public:
    virtual void test(QString name) = 0;
};

Q_DECLARE_INTERFACE(Plugin, "com.thanhtungpfiev.plugin")

#endif // PLUGIN_H
