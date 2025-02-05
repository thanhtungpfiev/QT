/*****************************************************************************
 * author DTA3HC - thanhtungpfiev@gmail.com
 *
 * date 2/5/2025
 *
 * copyright 2025 - thanhtungpfiev@gmail.com. All rights reserved.
 *
 * filename test.h
 *
 * class Test
 *
 * brief
 *
 *
 *****************************************************************************/
#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtConcurrent>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    void process();
    static void multiply(int &value);

signals:
public slots:
    void canceled();
    void finished();
    void suspending();
    void suspended();
    void progressRangeChanged(int minimum, int maximum);
    void progressTextChanged(const QString &progressText);
    void progressValueChanged(int progressValue);
    void resultReadyAt(int index);
    void resultsReadyAt(int beginIndex, int endIndex);
    void resumed();
    void started();

private:
    QFutureWatcher<void> watcher;
    QFuture<void> future;
    QList<int> list;
};

#endif // TEST_H
