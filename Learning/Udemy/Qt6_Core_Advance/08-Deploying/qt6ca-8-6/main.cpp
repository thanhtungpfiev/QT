/*****************************************************************************
 * author Admin - thanhtungpfiev@gmail.com
 *
 * date 2/8/2025
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
  A test application

  Why
  We need something to deploy

  How
  Build in release
  Explain debug vs release
  We will use the Release build to deploy

 */

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString build;

#ifdef QT_DEBUG
    build = "debug";
#else
    build = "release";
#endif

    qInfo() << "Current build: " << build;

    return a.exec();
}
