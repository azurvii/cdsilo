/*
 * findwidget.cpp
 *
 *  Created on: Dec 11, 2008
 *      Author: Vincent
 */

#include "findwidget.h"
#include "mainwindow.h"
#include "silofilter.h"
#include <QMessageBox>
#include "common.h"
using namespace Silo;

//---------- public ----------//

FindWidget::FindWidget(MainWindow *parent) :
	QDialog(parent) {
	setupUi(this);

	setupConnections();
	setupAppearance();
}

//---------- private static ----------//

void FindWidget::populateSizeCombo(QComboBox *combo) {
	populateSizeFilterCombo(combo);
	combo->addItem(tr("Between"));
}

void FindWidget::populateDateCombo(QComboBox *combo) {
	populateDateFilterCombo(combo);
	combo->addItem(tr("Between"));
}

//---------- private slots ----------//

void FindWidget::onDateFilterChanged(int index) {
	if (index == dateFilterCombo->count() - 1) {
		toDateTimeEdit->show();
	} else {
		toDateTimeEdit->hide();
	}
}

void FindWidget::onSizeFilterChanged(int index) {
	if (index == sizeFilterCombo->count() - 1) {
		toSpin->show();
		toUnitCombo->show();
	} else {
		toSpin->hide();
		toUnitCombo->hide();
	}
}

void FindWidget::onSizeUnitChanged(int unit) {
	if (unit == UNIT_B) {
		sizeSpin->setDecimals(0);
	} else {
		sizeSpin->setDecimals(sizePrecision);
	}
}

void FindWidget::onSizeToUnitChanged(int unit) {
	if (unit == UNIT_B) {
		toSpin->setDecimals(0);
	} else {
		toSpin->setDecimals(sizePrecision);
	}
}

void FindWidget::onFind() {
	static QString text;
	MainWindow *parent = (MainWindow *) parentWidget();
	parent->clearFilters();
	if (nameCheck->isChecked()) {
		text = nameEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_NAME);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (typeCheck->isChecked()) {
		text = typeEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_TYPE);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (pathCheck->isChecked()) {
		text = pathEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_PATH);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (labelCheck->isChecked()) {
		text = labelEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_LABEL);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (commentCheck->isChecked()) {
		text = commentEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_COMMENT);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (dateCheck->isChecked()) {
		int dateFilterType = dateFilterCombo->currentIndex();
		if (dateFilterType == dateFilterCombo->count() - 1) {
			QDateTime min = dateTimeEdit->dateTime();
			QDateTime max = toDateTimeEdit->dateTime();
			bool invert = min > max;
			SiloFilter *minFilter = new SiloFilter(parent);
			SiloFilter *maxFilter = new SiloFilter(parent);
			minFilter->setFilterKeyColumn(ID_DATE);
			maxFilter->setFilterKeyColumn(ID_DATE);
			minFilter->setFilterDateTime(min, invert ? FILTER_LESS
					: FILTER_MORE);
			maxFilter->setFilterDateTime(max, invert ? FILTER_MORE
					: FILTER_LESS);
			parent->appendFilter(minFilter);
			parent->appendFilter(maxFilter);
		} else {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_DATE);
			filter->setFilterDateTime(dateTimeEdit->dateTime(), FilterType(
					dateFilterType));
			parent->appendFilter(filter);
		}
	}
	if (sizeCheck->isChecked()) {
		int sizeFilterType = sizeFilterCombo->currentIndex();
		if (sizeFilterType == sizeFilterCombo->count() - 1) {
			qint64 min = getBytes(sizeSpin->value(), UnitType(
					sizeUnitCombo->currentIndex()));
			qint64 max = getBytes(toSpin->value(), UnitType(
					toUnitCombo->currentIndex()));
			bool invert = min > max;
			SiloFilter *minFilter = new SiloFilter(parent);
			SiloFilter *maxFilter = new SiloFilter(parent);
			minFilter->setFilterKeyColumn(ID_SIZE);
			maxFilter->setFilterKeyColumn(ID_SIZE);
			minFilter->setFilterSize(min, invert ? FILTER_LESS : FILTER_MORE);
			maxFilter->setFilterSize(max, invert ? FILTER_MORE : FILTER_LESS);
			parent->appendFilter(minFilter);
			parent->appendFilter(maxFilter);
		} else {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(ID_SIZE);
			filter->setFilterSize(getBytes(sizeSpin->value(), UnitType(
					sizeUnitCombo->currentIndex())), FilterType(sizeFilterType));
			parent->appendFilter(filter);
		}
	}
}

void FindWidget::onClear() {
	MainWindow *parent = (MainWindow *) parentWidget();
	parent->clearFilters();
}

//---------- private ----------//

void FindWidget::setupAppearance() {
	populateDateCombo(dateFilterCombo);
	populateSizeCombo(sizeFilterCombo);
	populateUnitCombo(sizeUnitCombo);
	populateUnitCombo(toUnitCombo);
	onSizeFilterChanged(sizeFilterCombo->currentIndex());
	onDateFilterChanged(dateFilterCombo->currentIndex());
	onSizeToUnitChanged(toUnitCombo->currentIndex());
	onSizeUnitChanged(sizeUnitCombo->currentIndex());
	dateTimeEdit->setDateTime(QDateTime::currentDateTime());
	toDateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void FindWidget::setupConnections() {
	connect(sizeFilterCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onSizeFilterChanged(int)));
	connect(dateFilterCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onDateFilterChanged(int)));
	connect(sizeUnitCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onSizeUnitChanged(int)));
	connect(toUnitCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(onSizeToUnitChanged(int)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(onFind()));
	connect(clearButton, SIGNAL(clicked()), this, SLOT(onClear()));
}
