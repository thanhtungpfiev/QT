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
#ifndef MYLIB_GLOBAL_H
#define MYLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYLIB_LIBRARY)
#define MYLIB_EXPORT Q_DECL_EXPORT
#else
#define MYLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // MYLIB_GLOBAL_H
