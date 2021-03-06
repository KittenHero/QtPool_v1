#pragma once

#include <QColor>
#include <QPainter>

#include "pocket.h"

class Ball;

/**
 * @brief The Table base class
 * pure virtual -> clone & render
 */
class Table {
protected:
    int m_width;
    int m_height;
    QBrush m_brush;
    double m_friction;
public:
    virtual ~Table() {}
    Table(int width, int height, QColor colour, double friction) :
        m_width(width), m_height(height),
        m_brush(colour), m_friction(friction) {}
	virtual Table* clone() const = 0;
    /**
     * @brief render - draw the table to screen using the specified painter
     * @param painter - painter to use
     */
    virtual void render(QPainter& painter, const QVector2D& offset) = 0;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    double getFriction() const { return m_friction; }

    virtual bool sinks(Ball*) { return false; }
};

/**
 * @brief The StageOneTable class
 * does nothing special
 */
class StageOneTable : public Table
{
public:
    StageOneTable(int width, int height, QColor colour, double friction) :
        Table(width, height, colour, friction) {}
	Table* clone() const override { return new StageOneTable(*this); }
    /**
     * @brief render - draw the stageonetable to screen using the specified painter
     * @param painter - painter to use
     */
    void render(QPainter &painter, const QVector2D& offset) override;
};

/**
 * @brief The StageTwoTable class
 * keeps count of how many balls are in each pocket
 */
class StageTwoTable : public Table {
protected:
    std::vector<Pocket*> m_pockets;

public:
    StageTwoTable(int width, int height, QColor colour, double friction) :
        Table(width, height, colour, friction) {}

	Table* clone() const override {
		StageTwoTable* t = new StageTwoTable(*this);
		std::transform(t->m_pockets.begin(), t->m_pockets.end(), t->m_pockets.begin(),
			[](Pocket* p) -> Pocket* { return new Pocket(*p); }
		);
		return t;
	}

    ~StageTwoTable();

    /**
     * @brief render - draw the stageonetable to screen using the specified painter
     * @param painter - painter to use
     */
    void render(QPainter &painter, const QVector2D& offset) override;

    // sinky winky ball
    virtual bool sinks(Ball* b) override;

    /* self explanatory */
    void addPocket(Pocket* p) { m_pockets.push_back(p); }
	const std::vector<Pocket*>& getPockets() { return m_pockets; }
};
