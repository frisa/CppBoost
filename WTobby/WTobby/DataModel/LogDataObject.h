#pragma once
#include <QObject>

class LogDataObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mtype READ mtype WRITE setMType NOTIFY mtypeChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    LogDataObject(QString type, QString message)
    {
        _mtype = type;
        _message = message;
    }

    /* GETTERS */
    QString mtype() const
    {
        return _mtype;
    }
    QString message() const
    {
        return _message;
    }

    /* SETTERS */
    void setMType(QString value)
    {
        _mtype = value;
    }
    void setMessage(QString value)
    {
        _message = value;
    }
signals:
    void mtypeChanged();
    void messageChanged();

private:
    QString _mtype;
    QString _message;
};