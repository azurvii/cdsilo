/*
 * silofilter.cpp
 *
 *  Created on: Dec 10, 2008
 *      Author: Vincent
 */

#include "silofilter.h"
#include "mainwindow.h"

SiloFilter::SiloFilter(QObject *parent) :
	QSortFilterProxyModel(parent) {
	filterType = FILTER_INVALID;
	filterSize = 0;
}

void SiloFilter::setFilterDateTime(const QDateTime &dateTime,
		SiloFilter::FilterType filterType) {
	this->filterType = filterType;
	filterDate = dateTime;
}

void SiloFilter::setFilterSize(qint64 filterSize,
		SiloFilter::FilterType filterType) {
	this->filterType = filterType;
	this->filterSize = filterSize;
}

void SiloFilter::setFilterType(SiloFilter::FilterType filterType) {
	this->filterType = filterType;
}

bool SiloFilter::filterAcceptsRow(int sourceRow,
		const QModelIndex &sourceParent) const {
	int keyColumn = filterKeyColumn();
	if (keyColumn == MainWindow::ID_DATE) {
		QModelIndex index = sourceModel()->index(sourceRow, keyColumn,
				sourceParent);
		switch (filterType) {
		case FILTER_LESS:
			return index.data(Qt::DisplayRole).toDateTime() < filterDate;
		case FILTER_MORE:
			return index.data(Qt::DisplayRole).toDateTime() > filterDate;
		case FILTER_MATCH:
			return index.data(Qt::DisplayRole).toDateTime() == filterDate;
		case FILTER_INVALID:
			return true;
		}
	} else if (keyColumn == MainWindow::ID_SIZE) {
		QModelIndex index = sourceModel()->index(sourceRow, keyColumn,
				sourceParent);
		switch (filterType) {
		case FILTER_LESS:
			return index.data(Qt::DisplayRole).toLongLong() < filterSize;
		case FILTER_MORE:
			return index.data(Qt::DisplayRole).toLongLong() > filterSize;
		case FILTER_MATCH:
			return index.data(Qt::DisplayRole).toLongLong() == filterSize;
		case FILTER_INVALID:
			return true;
		}
	} else if (filterType == FILTER_INVALID
			&& filterRegExp().pattern().isEmpty()) {
		return true;
	}
	return QSortFilterProxyModel::filterAcceptsRow(sourceRow, sourceParent);
}
