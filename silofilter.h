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

class SiloFilter: public QSortFilterProxyModel {
Q_OBJECT
public:
	enum FilterType {
		FILTER_LESS = 0,
		FILTER_MATCH = 1,
		FILTER_MORE = 2,
		FILTER_INVALID = -1,
		FILTER_MAX = 3
	};

public:
	SiloFilter(QObject *parent = 0);
	void setFilterDateTime(const QDateTime &dateTime, FilterType filterType =
			FILTER_MATCH);
	void setFilterSize(qint64 filterSize, FilterType filterType = FILTER_MATCH);
	void setFilterType(FilterType filterType);
//	bool isActive() const {
//		return (filterRegExp().pattern() != QString()) || (filterType
//				!= FILTER_INVALID);
//	}

protected:
	bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:
	FilterType filterType;
	QDateTime filterDate;
	qint64 filterSize;
};

#endif /* SILOFILTER_H_ */
