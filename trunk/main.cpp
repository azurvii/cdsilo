#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QFont>
#include "mainwindow.h"
#include "common.h"
using namespace Silo;

int main(int argc, char **argv) {
	QApplication a(argc, argv);
	QSettings settings(orgName, appName);
	QString lang = settings.value("lang", "en").toString();
	if (lang == "zh_CN") {
		a.setFont(QFont("SimSun", 9));
		QTranslator *appTranslator = new QTranslator;
		appTranslator->load("lang-" + lang);
		QTranslator *qtTranslator = new QTranslator;
		qtTranslator->load("qt_" + lang);
		a.installTranslator(appTranslator);
		a.installTranslator(qtTranslator);
		currentLanguage = LANG_ZH_CN;
	}
	MainWindow w;
	w.show();
	return a.exec();
}
