/*
 * main.h
 *
 *  Created on: Dec 12, 2008
 *      Author: Vincent
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <QHash>
#include <QString>
class QComboBox;
class QAbstractItemModel;

namespace Silo {

enum ColumnType {
	ID_LABEL = 0,
	ID_NAME = 1,
	ID_PATH = 2,
	ID_TYPE = 3,
	ID_SIZE = 4,
	ID_DATE = 5,
	ID_COMMENT = 6,
	ID_MAX = 7,
	ID_MIN = 0
};

enum FindPage {
	FIND_TEXT = 0, FIND_DATE = 1, FIND_SIZE = 2
};

enum UnitType {
	UNIT_B = 0,
	UNIT_KB = 1,
	UNIT_MB = 2,
	UNIT_GB = 3,
	UNIT_TB = 4,
	UNIT_PB = 5,
	UNIT_MAX = 6,
	UNIT_MIN = 0
};

enum FilterType {
	FILTER_INVALID = -1,
	FILTER_LESS = 0,
	FILTER_MATCH = 1,
	FILTER_MORE = 2,
	FILTER_MAX = 3
};

enum Language {
	LANG_EN, LANG_ZH_CN
};

extern const qint16 dbVersion;
extern const qint16 dbHeader;
extern const int dataStreamVersion;
extern const QString dateTimeFormat;
//extern const QString multivalueString;
extern QHash<int, QString> columnNames;
extern QHash<int, QString> unitNames;
extern const int sizePrecision;
extern Language currentLanguage;
// Strings used for QSettings:
extern const char *orgName;
extern const char *appName;

void populateDateFilterCombo(QComboBox *combo);
void populateSizeFilterCombo(QComboBox *combo);
void populateColumnCombo(QComboBox *combo);
void populateUnitCombo(QComboBox *combo);
void populateColumnNames();
void populateUnitNames();
void populateModelHeaders(QAbstractItemModel *model);
qint64 getBytes(double displayValue, UnitType unit);
QString stringFromSize(qint64 size, int precision = sizePrecision);
QString getUnitName(UnitType unitId);

}

#endif /* COMMON_H_ */
