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

/*

  What
  Application plugins

  Why
  We want to extend our application

  How
  QPluginLoader
  Make the plugin
  Build it
  Include the Plugin.h file
  Add the compiled plugin to a sub folder called "plugins" in the build directory

 */

#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>
#include "plugin.h"

QStringList getPlugins(QString path)
{
    QStringList plugins;

    QStringList filter;
    filter << "*.dll" << "*.so" << "*.dylib";

    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(filter);
    foreach (QFileInfo file, list) {
        plugins.append(file.filePath());
        //Mac - if(!file.isSymLink()) plugins.append(file.filePath());
    }

    return plugins;
}

void testPlugins(QStringList plugins)
{
    foreach (QString file, plugins) {
        qInfo() << "Loading..." << file;

        QPluginLoader loader(file);
        if (!loader.load()) {
            qInfo() << "Error: " << loader.fileName() << " Error: " << loader.errorString();
            continue;
        }

        qInfo() << "Loaded: " << loader.fileName();
        Plugin *plugin = qobject_cast<Plugin *>(loader.instance());
        if (plugin) {
            plugin->test("Dao Thanh Tung");
            loader.unload();
        } else {
            qInfo() << "Could not cast: " << loader.fileName();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Hello Plugins";
    QDir dir = QDir::current();
    // dir.cdUp();
    dir.cd("plugins"); // Plugins
    qInfo() << "Path: " << dir.path();

    QStringList plugins = getPlugins(dir.path());
    qInfo() << "Plugins: " << plugins;

    testPlugins(plugins);

    qInfo() << "Done!";

    return a.exec();
}
