/*
 * silofilter.h
 *
 *  Created on: Dec 10, 2008
 *      Author: Vincent
 */

#ifndef SILOFILTER_H_
#define SILOFILTER_H_

#include <QSortFilterProxyModel>
#include <QDateTime>
#include "common.h"
using namespace Silo;

class SiloFilter: public QSortFilterProxyModel {
Q_OBJECT
public:
	SiloFilter(QObject *parent = 0);
	void setFilterDateTime(const QDateTime &dateTime, FilterType filterType =
			FILTER_MATCH);
	void setFilterSize(qint64 filterSize, FilterType filterType = FILTER_MATCH);
	void setFilterType(FilterType filterType);

protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
	FilterType filterType;
	QDateTime filterDate;
	qint64 filterSize;
};

#endif /* SILOFILTER_H_ */
