#include "paintwidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
//    m_nInitialX = 0;
//    m_nInitialY = 0;
//    m_nFinalX = 0;
//    m_nFinalY = 0;
//    m_nPTargetPixmap = 0;
//    m_nPTargetPixmap = new QPixmap(400,400);
    m_nPTargetPixmap = QPixmap(400,400);
    m_nPTargetPixmap.fill();
    m_nbMousePressed = false;
}

PaintWidget::~PaintWidget()
{
//    delete ui;
}

void PaintWidget::mousePressEvent(QMouseEvent* event)
{
    m_nbMousePressed = true;
//    m_nInitialX = event->pos().x();
//    m_nInitialY = event->pos().y();
    m_line.setP1(event->pos());
    m_line.setP2(event->pos());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_nbMousePressed = false;
    update();
}

void PaintWidget::paintEvent(QPaintEvent *e)
{
    static bool wasPressed = false;
    QPainter painter(this);

    if(m_nbMousePressed)
    {
        painter.drawPixmap(0, 0, m_nPTargetPixmap);
        painter.drawLine(m_line);
        wasPressed = true;
    }
    else if(wasPressed)
    {
        QPainter PixmapPainter(&m_nPTargetPixmap);
        QPen pen(Qt::green);
        PixmapPainter.setPen(pen);
        PixmapPainter.drawLine(m_line);

        painter.drawPixmap(0, 0, m_nPTargetPixmap);
        wasPressed = false;
    }
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
//        QPainter PixmapPainter(m_nPTargetPixmap);
//        QPen pen(Qt::black);
//        PixmapPainter.setPen(pen);
//        PixmapPainter.drawLine(m_nInitialX, m_nInitialY, m_nFinalX, m_nFinalY);
//        m_nFinalX = event->pos().x();
//        m_nFinalY = event->pos().y();
        m_line.setP2(event->pos());
//        update(); // update your view
    }
    update(); // update your view
}
