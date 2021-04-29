#pragma once
#include <QAbstractListModel>
#include <QObject>
#include <QModelIndex>
#include <QString>
#include <QHash>

class LogExDataObject
{
    QString _type;
    QString _message;
public:
    LogExDataObject(const QString &type, const QString &message)
    {
        _type = type;
        _message = message;
    }
    QString type() const
    {
        return _type;
    }
    QString message() const
    {
        return _message;
    }
};

class LogExModel :
    public QAbstractListModel
{
    Q_OBJECT
private:
    QList<LogExDataObject> _data;
    enum LogRoles {
        TypeRole = Qt::UserRole + 1,
        MessageRole
    };
public:
    explicit LogExModel(QObject* parent = nullptr);
    void addMessage(QString type, QString message);

    // Inherited via QAbstractListModel
    QHash<int, QByteArray> LogExModel::roleNames() const;
    virtual Q_INVOKABLE int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    virtual Q_INVOKABLE QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};

