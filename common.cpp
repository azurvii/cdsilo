/*
 * common.cpp
 *
 *  Created on: Dec 12, 2008
 *      Author: Vincent
 */

#include "common.h"
#include <QtGui>

namespace Silo {

const qint16 dbVersion = 0x0100;
const qint16 dbHeader = 0xE7FC;
const int dataStreamVersion = QDataStream::Qt_4_4;
const QString dateTimeFormat = QObject::tr("yyyy-MM-dd HH:mm:ss");
//const QString multivalueString = QObject::tr("<<< multiple values >>>");
QHash<int, QString> columnNames;
QHash<int, QString> unitNames;
const int sizePrecision = 2;
Language currentLanguage = LANG_EN;
const char *orgName = "azurvii";
const char *appName = "CD Silo";

void populateDateFilterCombo(QComboBox *combo) {
	combo->clear();
	combo->addItem(QObject::tr("Before"));
	combo->addItem(QObject::tr("Exactly"));
	combo->addItem(QObject::tr("After"));
}

void populateSizeFilterCombo(QComboBox *combo) {
	combo->clear();
	combo->addItem(QObject::tr("Less than"));
	combo->addItem(QObject::tr("Exactly"));
	combo->addItem(QObject::tr("More than"));
}

void populateColumnCombo(QComboBox *combo) {
	if (columnNames.size() != ID_MAX) {
		populateColumnNames();
	}
	combo->clear();
	combo->addItems(columnNames.values());
}

void populateUnitCombo(QComboBox *combo) {
	if (unitNames.size() != UNIT_MAX) {
		populateUnitNames();
	}
	combo->clear();
	combo->addItems(unitNames.values());
}

void populateColumnNames() {
	columnNames.clear();
	columnNames[ID_NAME] = QObject::tr("Name");
	columnNames[ID_PATH] = QObject::tr("Path");
	columnNames[ID_TYPE] = QObject::tr("Type");
	columnNames[ID_SIZE] = QObject::tr("Size");
	columnNames[ID_DATE] = QObject::tr("Last Modified");
	columnNames[ID_LABEL] = QObject::tr("Label");
	columnNames[ID_COMMENT] = QObject::tr("Comment");
}

void populateUnitNames() {
	unitNames.clear();
	unitNames[UNIT_B] = QObject::tr("B");
	unitNames[UNIT_KB] = QObject::tr("KB");
	unitNames[UNIT_MB] = QObject::tr("MB");
	unitNames[UNIT_GB] = QObject::tr("GB");
	unitNames[UNIT_TB] = QObject::tr("TB");
	unitNames[UNIT_PB] = QObject::tr("PB");
}

void populateModelHeaders(QAbstractItemModel *model) {
	model->setHeaderData(ID_NAME, Qt::Horizontal, columnNames[ID_NAME],
			Qt::DisplayRole);
	model->setHeaderData(ID_PATH, Qt::Horizontal, columnNames[ID_PATH],
			Qt::DisplayRole);
	model->setHeaderData(ID_TYPE, Qt::Horizontal, columnNames[ID_TYPE],
			Qt::DisplayRole);
	model->setHeaderData(ID_SIZE, Qt::Horizontal, columnNames[ID_SIZE],
			Qt::DisplayRole);
	model->setHeaderData(ID_DATE, Qt::Horizontal, columnNames[ID_DATE],
			Qt::DisplayRole);
	model->setHeaderData(ID_LABEL, Qt::Horizontal, columnNames[ID_LABEL],
			Qt::DisplayRole);
	model->setHeaderData(ID_COMMENT, Qt::Horizontal, columnNames[ID_COMMENT],
			Qt::DisplayRole);
}

qint64 getBytes(double displayValue, UnitType unit) {
	int u = unit;
	while (u > UNIT_B) {
		displayValue *= 1024.0;
		--u;
	}
	return qint64(displayValue);
}

QString stringFromSize(qint64 size, int precision) {
	int unit = UNIT_B;
	double displayValue = size;
	while (displayValue >= 1024.0) {
		if (unit >= UNIT_MAX) {
			--unit;
			break;
		}
		displayValue /= 1024.0;
		++unit;
	}
	return QObject::tr("%1%2").arg(displayValue, 0, 'f', unit == 0 ? 0
			: precision).arg(unitNames[unit]);
}

QString getUnitName(UnitType unitId) {
	if (unitNames.size() != ID_MAX) {
		populateUnitNames();
	}
	return unitNames[unitId];
}

}
