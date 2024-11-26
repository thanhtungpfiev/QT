#include "Logger.h"

#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QHash>
#include <QObject>

QFile* Logger::logFile = Q_NULLPTR;
bool Logger::isInit = false;
QHash<QtMsgType, QString> Logger::contextNames = {
	{QtMsgType::QtDebugMsg,		" Debug  "},
	{QtMsgType::QtInfoMsg,		"  Info  "},
	{QtMsgType::QtWarningMsg,	"Warning "},
	{QtMsgType::QtCriticalMsg,	"Critical"},
	{QtMsgType::QtFatalMsg,		" Fatal  "}
};

void Logger::init() {
	if (isInit) {
		return;
	}
	
	// Create log file
	logFile = new QFile;
	logFile->setFileName("./MyLog.log");
	logFile->open(QIODevice::Append | QIODevice::Text);

	// Redirect logs to messageOutput
	qInstallMessageHandler(Logger::messageOutput);

	// Clear file contents
	logFile->resize(0);

	Logger::isInit = true;
}

void Logger::clean() {
	if (logFile != Q_NULLPTR) {
		logFile->close();
		delete logFile;
	}
}

void Logger::messageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg) {

	QString log = QObject::tr("%1 | %2 | %3 | %4 | %5 | %6\n").
		arg(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")).
		arg(Logger::contextNames.value(type)).
		arg(context.line).
        arg(QString(context.file)).
		arg(QString(context.function)).
		arg(msg);

	// Write to the log file
    if (logFile) {
        logFile->write(log.toLocal8Bit());
        logFile->flush();
    }

    // Also write to the console
    fprintf(stderr, "%s", log.toLocal8Bit().constData());
    fflush(stderr);  // Ensure it gets written immediately
}
