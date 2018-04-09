#include "simplecreator.h"
#include "simpletable.h"
#include "simpleball.h"

unique_ptr<Table> SimpleCreator::makeTable(const QJsonObject &spec) {
	return unique_ptr<SimpleTable>(
		new SimpleTable(
			QSize(spec["size"]["x"].toInt(), spec["size"]["y"].toInt()),
			spec["colour"].toString(), spec["friction"].toDouble()
		)
	);
}

unique_ptr<Ball> SimpleCreator::makeBall(const QJsonObject &spec) {
	return unique_ptr<Ball>(
		new SimpleBall(
			spec["radius"].toDouble(), spec["colour"].toString(),
			spec["mass"].toDouble(),
			QVector2D(spec["position"]["x"].toDouble(), spec["position"]["y"].toDouble()),
			QVector2D(spec["velocity"]["x"].toDouble(), spec["velocity"]["y"].toDouble())
		)
	);
}
