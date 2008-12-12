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

//---------- public ----------//

FindWidget::FindWidget(MainWindow *parent) :
	QDialog(parent) {
	setupUi(this);

	setupConnections();
	setupAppearance();
}

//---------- private static ----------//

void FindWidget::populateSizeCombo(QComboBox *combo) {
	MainWindow::populateSizeFilterCombo(combo);
	combo->addItem(tr("Between"));
}

void FindWidget::populateDateCombo(QComboBox *combo) {
	MainWindow::populateDateFilterCombo(combo);
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
	if (unit == MainWindow::UNIT_B) {
		sizeSpin->setDecimals(0);
	} else {
		sizeSpin->setDecimals(MainWindow::sizePrecision());
	}
}

void FindWidget::onSizeToUnitChanged(int unit) {
	if (unit == MainWindow::UNIT_B) {
		toSpin->setDecimals(0);
	} else {
		toSpin->setDecimals(MainWindow::sizePrecision());
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
			filter->setFilterKeyColumn(MainWindow::ID_NAME);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (typeCheck->isChecked()) {
		text = typeEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(MainWindow::ID_TYPE);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (pathCheck->isChecked()) {
		text = pathEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(MainWindow::ID_PATH);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (labelCheck->isChecked()) {
		text = labelEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(MainWindow::ID_LABEL);
			filter->setFilterWildcard(text);
			filter->setFilterCaseSensitivity(Qt::CaseInsensitive);
			parent->appendFilter(filter);
		}
	}
	if (commentCheck->isChecked()) {
		text = commentEdit->text();
		if (!text.isEmpty()) {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(MainWindow::ID_COMMENT);
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
			minFilter->setFilterKeyColumn(MainWindow::ID_DATE);
			maxFilter->setFilterKeyColumn(MainWindow::ID_DATE);
			minFilter->setFilterDateTime(min, invert ? SiloFilter::FILTER_LESS
					: SiloFilter::FILTER_MORE);
			maxFilter->setFilterDateTime(max, invert ? SiloFilter::FILTER_MORE
					: SiloFilter::FILTER_LESS);
			parent->appendFilter(minFilter);
			parent->appendFilter(maxFilter);
		} else {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(MainWindow::ID_DATE);
			filter->setFilterDateTime(dateTimeEdit->dateTime(),
					SiloFilter::FilterType(dateFilterType));
			parent->appendFilter(filter);
		}
	}
	if (sizeCheck->isChecked()) {
		int sizeFilterType = sizeFilterCombo->currentIndex();
		if (sizeFilterType == sizeFilterCombo->count() - 1) {
			qint64 min = MainWindow::getBytes(sizeSpin->value(),
					MainWindow::UnitType(sizeUnitCombo->currentIndex()));
			qint64 max = MainWindow::getBytes(toSpin->value(),
					MainWindow::UnitType(toUnitCombo->currentIndex()));
			bool invert = min > max;
			SiloFilter *minFilter = new SiloFilter(parent);
			SiloFilter *maxFilter = new SiloFilter(parent);
			minFilter->setFilterKeyColumn(MainWindow::ID_SIZE);
			maxFilter->setFilterKeyColumn(MainWindow::ID_SIZE);
			minFilter->setFilterSize(min, invert ? SiloFilter::FILTER_LESS
					: SiloFilter::FILTER_MORE);
			maxFilter->setFilterSize(max, invert ? SiloFilter::FILTER_MORE
					: SiloFilter::FILTER_LESS);
			parent->appendFilter(minFilter);
			parent->appendFilter(maxFilter);
		} else {
			SiloFilter *filter = new SiloFilter(parent);
			filter->setFilterKeyColumn(MainWindow::ID_SIZE);
			filter->setFilterSize(MainWindow::getBytes(sizeSpin->value(),
					MainWindow::UnitType(sizeUnitCombo->currentIndex())),
					SiloFilter::FilterType(sizeFilterType));
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
	MainWindow::populateUnitCombo(sizeUnitCombo);
	MainWindow::populateUnitCombo(toUnitCombo);
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
