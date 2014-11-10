#ifndef SHORTY_H
#define SHORTY_H

#include <QQuickItem>

class Shorty : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Shorty)    
    
public:
    Shorty(QQuickItem *parent = 0);
    ~Shorty();
    Q_INVOKABLE void shootFull(QString name);    
    Q_INVOKABLE void shoot(QString name, QSize size);
    Q_INVOKABLE void shootThumb(QString name);
};

#endif // SHORTY_H

